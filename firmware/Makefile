# Specify the variant to build on the command line:
# make variant=DIS
# make variant=ORI
# make variant=ENT

TARGET= LeoBlinky2018-$(variant)

# Adjust the XRAM location and size to leave space for the USB DMA buffers
# Buffer layout in XRAM:
# 0x0000 Ep0Buffer[8]
# 0x0040 Ep1Buffer[8]
# 0x0080 EP2Buffer[2*64]
#
# This takes a total of 256bytes, so there are 768 bytes left.
XRAM_SIZE = 0x0300
XRAM_LOC = 0x0100

CH554_SDCC= c:/Users/blinkinlabs/Blinkinlabs-Repos/ch554_sdcc

EXTRA_FLAGS="-DUART0_BAUD=57600" \
            "-DUART1_BAUD=57600"

EXTRA_FLAGS+="-DVARIANT_$(variant) -Werror"

C_FILES= \
	main.c \
	leoblinky2018.c \
	icn2053.c \
	uart0_int.c \
	uart1_int.c \
	circular_buffer.c \
	comms.c \
	patterns.c \
	spi_flash.c \
        usb_cdc.c \
	uart.c \
        usb_protocol.c \
        animations.c \
	$(CH554_SDCC)/include/spi.c \
	$(CH554_SDCC)/include/debug.c

pre-flash:
	

include $(CH554_SDCC)/examples/Makefile.include
