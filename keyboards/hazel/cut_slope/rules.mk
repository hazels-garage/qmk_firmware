BOARD = GENERIC_RP_RP2040

QUANTUM_PAINTER_DRIVERS += st7735_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

SRC += fonts/urbanist24.qff.c fonts/urbanist36.qff.c display.c