#ifndef __gui_H
#define __gui_H
#ifdef __cplusplus
 extern "C" {
#endif


#include "ILI9341_Touchscreen.h"
#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"
#include "i2c.h"
#include "adc.h"
#include "tim.h"

#include "stdio.h"
#include "string.h"

#include "me.h"

uint8_t red_percent;
uint8_t green_percent;
uint8_t blue_percent;

uint8_t page_num;

uint16_t coordinates[2];

uint32_t time;

uint32_t potentiometer_val;
uint8_t pwm;

float h,t;
uint8_t step;
HAL_StatusTypeDef status;

// initialization
void GUI_init();

// pages
void main_system();
void first_page();
void second_page();

// render
void draw_color_buttons();
void draw_progress_bars();
void draw_color_percent();
void draw_change_page_button();
void draw_sensor_value();

// update
void update_progress_bars();
void update_page();
void update_brightness();

// temperature and humidity
void get_sensor_value();
void get_potentiometer_value();

// utility
uint16_t remix_color(uint8_t r, uint8_t g, uint8_t b);

#ifdef __cplusplus
}
#endif
#endif
