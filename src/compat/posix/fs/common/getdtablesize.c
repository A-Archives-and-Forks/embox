/**
 * @file
 * @brief
 *
 * @date 21.02.26
 * @author Aleksey Zhmulin
 */

#include <unistd.h>

#include <kernel/task/resource/idesc_table.h>

int getdtablesize(void) {
	return MODOPS_IDESC_TABLE_SIZE;
}
