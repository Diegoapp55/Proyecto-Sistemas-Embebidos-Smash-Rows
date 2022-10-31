PATH_TOOLS?=
include $(PATH_TOOLS)/Makefile
BOARD=esp32
DTS_OVERLAY=./boards/esp32.overlay
SERIAL=/dev/ttyUSB0

west-espressif:
	west update
	west blobs fetch hal_espressif

west-espressif-openocd:
	west espressif install

# west-esp-update:
# 	west espressif update

environment:
	/bin/bash $(PATH_TOOLS)/zephyr-env.sh $(BOARD)
