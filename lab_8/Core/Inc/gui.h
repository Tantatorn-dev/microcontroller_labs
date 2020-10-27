#ifndef __gui_H
#define __gui_H
#ifdef __cplusplus
 extern "C" {
#endif


#include "ILI9341_Touchscreen.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"
#include "stdio.h"

#include "main.h"

uint8_t red_percent;
uint8_t green_percent;
uint8_t blue_percent;

uint16_t coordinates[2];

// initialization
void GUI_init();

// pages
void first_page();

// render
void draw_color_buttons();
void draw_progress_bars();
void draw_color_percent();

// update
void update_progress_bars();

#ifdef __cplusplus
}
#endif
#endif
