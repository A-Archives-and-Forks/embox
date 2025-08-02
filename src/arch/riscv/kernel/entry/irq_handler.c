/**
 * @file
 *
 * @brief
 *
 * @date 05.12.2019
 * @author Nastya Nizharadze
 */

#include <assert.h>

#include <asm/csr.h>
#include <asm/entry.h>
#include <asm/interrupts.h>
#include <asm/ptrace.h>
#include <hal/cpu.h>
#include <kernel/irq.h>
#include <kernel/panic.h>
#ifdef SMP
#include <riscv/smp_ipi.h>
#endif

#define CLEAN_IRQ_BIT (~(1u << 31))

extern void riscv_mtimer_irq_handler(void) __attribute__((weak));

void riscv_interrupt_handler(void) {
	assert(!critical_inside(CRITICAL_IRQ_LOCK));

	critical_enter(CRITICAL_IRQ_HANDLER);
	{
		long pending;
		long interrupt_id;

		pending = (csr_read(CSR_CAUSE)) & CLEAN_IRQ_BIT;
		interrupt_id = pending;

		if (pending == RISCV_IRQ_TIMER) {
			disable_timer_interrupts();
			//ipl_enable();               /* enable mstatus.MIE */
			if (riscv_mtimer_irq_handler) {
				riscv_mtimer_irq_handler();
			}
			//ipl_disable();              /* disable mstatus.MIE */
			enable_timer_interrupts();
		}
		else if (pending == RISCV_IRQ_EXT) {
			/* the ID of the highest-priority pending interrupt */
			interrupt_id = irqctrl_get_intid();

			irqctrl_eoi(interrupt_id);
			irqctrl_disable(interrupt_id);
			ipl_enable();
			irq_dispatch(interrupt_id);
			ipl_disable();
			irqctrl_enable(interrupt_id);
		}
		else if (pending == RISCV_IRQ_SOFT) {
			disable_software_interrupts();
#ifdef SMP
			switch (smp_get_ipi_message()) {
			case NONE:
				smp_ack_ipi();
				break;
			case RESCHED:
				smp_ack_ipi();
				resched();
				break;
			default:
				panic("unknown software interrupt\n");
				break;
			}
#endif
			enable_software_interrupts();
		}
	}
	critical_leave(CRITICAL_IRQ_HANDLER);
	critical_dispatch_pending();
}
