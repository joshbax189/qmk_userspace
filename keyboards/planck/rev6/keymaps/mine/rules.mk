ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

# modify some defaults
ENCODER_ENABLE = no
DIP_SWITCH_ENABLE = no
MOUSEKEY_ENABLE = no
