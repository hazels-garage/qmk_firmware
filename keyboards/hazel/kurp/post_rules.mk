ifeq ($(strip $(KEYCOUNT_ENABLE)), yes)
	OPT_DEFS += -DKEYCOUNT_ENABLE
endif

ifeq ($(strip $(KEYLOG_ENABLE)), yes)
	OPT_DEFS += -DKEYLOG_ENABLE
	ifeq ($(strip $(KEYLOG_DEBUG)), yes)
		OPT_DEFS += -DKEYLOG_DEBUG
	endif
endif