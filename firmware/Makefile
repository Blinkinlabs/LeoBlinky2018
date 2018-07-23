# Specify the variant to build on the command line:
# make variant=DIS
# make variant=ORI
# make variant=ENT

TARGET= LeoBlinky2018-$(variant)

CH554_SDCC= c:/Users/Blinkinlabs/Blinkinlabs-Repos/ch554_sdcc

EXTRA_FLAGS="-DUART0_BAUD=57600" \
            "-DUART1_BAUD=57600"

EXTRA_FLAGS+="-DVARIANT_$(variant)"

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
	$(CH554_SDCC)/include/spi.c \
	$(CH554_SDCC)/include/debug.c

pre-flash:
	

include $(CH554_SDCC)/examples/Makefile.include
