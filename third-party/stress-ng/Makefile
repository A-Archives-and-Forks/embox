
PKG_NAME    := stress-ng
PKG_VER     := 0.20.00
PKG_SOURCES := https://github.com/ColinIanKing/$(PKG_NAME)/archive/refs/tags/V$(PKG_VER).tar.gz
PKG_MD5     := 0d1b99921cd69b4fa49a514dc5c2222c
PKG_PATCHES := stress-ng.patch 

$(CONFIGURE) :
	cd $(PKG_SOURCE_DIR) && ( \
		export EMBOX_GCC_LINK=full; \
		STATIC=1 CC=$(EMBOX_CC) \
		$(MAKE) config.h MAKEFLAGS='$(EMBOX_IMPORTED_MAKEFLAGS)' \
	)
# 	$(CP) $(CURDIR)/config.h $(PKG_SOURCE_DIR)
	touch $@

$(BUILD) :
	cd $(PKG_SOURCE_DIR) && ( \
		STATIC=1 CC=$(EMBOX_CC) \
		$(MAKE) stress-ng MAKEFLAGS='$(EMBOX_IMPORTED_MAKEFLAGS)' \
	)
	touch $@

$(INSTALL) :
	$(CP) $(PKG_SOURCE_DIR)/stress-ng $(PKG_INSTALL_DIR)/stress-ng.o
	touch $@
