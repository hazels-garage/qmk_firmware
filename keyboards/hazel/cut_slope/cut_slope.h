#pragma once
#include "quantum.h"

typedef struct kb_runtime_config {
    unsigned lcd_power : 1;
} kb_runtime_config;

extern kb_runtime_config kb_state;

void housekeeping_task_sync(void);