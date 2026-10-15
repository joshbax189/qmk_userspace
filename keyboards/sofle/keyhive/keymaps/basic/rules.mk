RGBLIGHT_ENABLE = yes
VIA_ENABLE = yes

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../rules.mk
