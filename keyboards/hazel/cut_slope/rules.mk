BOARD = GENERIC_RP_RP2040

QUANTUM_PAINTER_DRIVERS += st7735_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

SRC += fonts/urbanist24.qff.c fonts/urbanist36.qff.c 
SRC += fonts/roboto12.qff.c fonts/roboto18.qff.c fonts/roboto14.qff.c
SRC += display.c

WPM_ENABLE 					= yes
LTO_ENABLE=yes
OPT_DEFS = -O2