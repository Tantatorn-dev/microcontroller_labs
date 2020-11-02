#include "gui.h"

void GUI_init() {
	HAL_ADC_Start(&hadc1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);

	ILI9341_Init();
	ILI9341_Set_Rotation(3);
	ILI9341_Fill_Screen(WHITE);

	assign_me();

	red_percent = 0;
	green_percent = 0;
	blue_percent = 0;

	page_num = 1;

	time = 0;

	h=30.0;
	t=40.0;
	step = 0;

}

void main_system(){
	get_sensor_value();
	get_potentiometer_value();
	if(page_num==1){
		first_page();
	}
	else if(page_num==2){
		second_page();
	}
}

void first_page() {

	// render
	draw_change_page_button();
	draw_color_buttons();
	draw_progress_bars();
	draw_color_percent();
	draw_sensor_value();

	// update
	update_progress_bars();
	update_page();
	update_brightness();

}

void draw_color_buttons() {

	ILI9341_Draw_Filled_Circle(40, 100, 20, RED);
	ILI9341_Draw_Filled_Circle(40, 150, 20, GREEN);
	ILI9341_Draw_Filled_Circle(40, 200, 20, BLUE);

}

void draw_change_page_button() {

	ILI9341_Draw_Filled_Circle(150, 50, 20,
			remix_color(red_percent, green_percent, blue_percent));

}

void draw_progress_bars() {

	ILI9341_Draw_Filled_Rectangle_Coord(80, 80, 80 + (160 * red_percent / 100),
			120, RED);
	ILI9341_Draw_Filled_Rectangle_Coord(80, 80 + 50,
			80 + (160 * green_percent / 100), 120 + 50, GREEN);
	ILI9341_Draw_Filled_Rectangle_Coord(80, 80 + 100,
			80 + (160 * blue_percent / 100), 120 + 100, BLUE);

	ILI9341_Draw_Filled_Rectangle_Coord(80 + (160 * red_percent / 100), 80, 240,
			120, LIGHTRED);
	ILI9341_Draw_Filled_Rectangle_Coord(80 + (160 * green_percent / 100),
			80 + 50, 240, 120 + 50, LIGHTGREEN);
	ILI9341_Draw_Filled_Rectangle_Coord(80 + (160 * blue_percent / 100),
			80 + 100, 240, 120 + 100, LIGHTBLUE);

}

void draw_sensor_value() {

	char str[10];

	sprintf(str,"%.1fC ",t);

	ILI9341_Draw_Text(str, 30, 40, BLACK, 2, WHITE);

	sprintf(str,"%.1f%%RH ",h);

	ILI9341_Draw_Text(str, 230, 40, BLACK, 2, WHITE);

}

void draw_color_percent() {

	char str[10];

	sprintf(str, "%d%%    ", red_percent);
	ILI9341_Draw_Text(str, 250, 90, BLACK, 3, WHITE);

	sprintf(str, "%d%%    ", green_percent);
	ILI9341_Draw_Text(str, 250, 140, BLACK, 3, WHITE);

	sprintf(str, "%d%%    ", blue_percent);
	ILI9341_Draw_Text(str, 250, 190, BLACK, 3, WHITE);

}

void second_page() {


			update_page();

}

void update_page() {

	if (page_num == 1){
	if (TP_Touchpad_Pressed()) {

		if (TP_Read_Coordinates(coordinates) == TOUCHPAD_DATA_OK) {

			if (coordinates[0] > 30 && coordinates[0] < 80
					&& coordinates[1] < 200 && coordinates[1] > 150) {
				ILI9341_Fill_Screen(WHITE);
				ILI9341_Draw_Image( (const char*)me, 3);
				ILI9341_Draw_Rectangle(210, 10, 100, 100, WHITE);
				ILI9341_Draw_Text("Tantatorn Suksangwarn", 210, 10, remix_color(red_percent, green_percent, blue_percent), 2, WHITE);
				ILI9341_Draw_Text("61010402", 210, 30, remix_color(red_percent, green_percent, blue_percent), 2, WHITE);
				ILI9341_Draw_Text("Group 15", 210, 50, remix_color(red_percent, green_percent, blue_percent), 2, WHITE);
				page_num = 2;
				HAL_Delay(200);
				time = HAL_GetTick();
			}
		}
	}
	}
	else if(page_num == 2){
		if(TP_Touchpad_Pressed() || HAL_GetTick()-time > 5000){
			ILI9341_Fill_Screen(WHITE);
			page_num = 1;
		}
	}
}

void update_progress_bars() {

		if (TP_Touchpad_Pressed()) {

			if (TP_Read_Coordinates(coordinates) == TOUCHPAD_DATA_OK) {

				// push red button
				if (coordinates[0] > 90 && coordinates[0] < 140
						&& coordinates[1] < 310 && coordinates[1] > 260) {

					red_percent += 10;
					if (red_percent > 100) {
						red_percent = 0;
					}

				}

				// push green button
				if (coordinates[0] > 130 && coordinates[0] < 180
						&& coordinates[1] < 310 && coordinates[1] > 260) {
					green_percent += 10;
					if (green_percent > 100) {
						green_percent = 0;
					}
				}

				// push blue button
				if (coordinates[0] > 190 && coordinates[0] < 220
						&& coordinates[1] < 310 && coordinates[1] > 260) {
					blue_percent += 10;
					if (blue_percent > 100) {
						blue_percent = 0;
					}
				}

				HAL_Delay(200);

			}

		}

}

void update_brightness(){

	float dutyCycle = potentiometer_val/4095.0;
	htim2.Instance -> CCR3 = (10000-1) * dutyCycle;
	pwm = (GPIOB->IDR & GPIO_PIN_10) >> 10;

}

// r g b in percent
uint16_t remix_color(uint8_t r, uint8_t g, uint8_t b) {

		return (((r * RED) / 100) & RED) | (((g * GREEN) / 100) & GREEN)
				| (((b * BLUE) / 100) & BLUE);

}

void get_sensor_value(){

	uint8_t cmdBuffer[3];
	uint8_t dataBuffer[8];

	cmdBuffer[0] = 0x03;
	cmdBuffer[1] = 0x00;
	cmdBuffer[2] = 0x04;

	// wake up sensor
	HAL_I2C_Master_Transmit(&hi2c1, 0x5c<<1, cmdBuffer, 3, 200);
	// send reading command
	HAL_I2C_Master_Transmit(&hi2c1, 0x5c<<1, cmdBuffer, 3, 200);

	HAL_Delay(1);

	HAL_I2C_Master_Receive(&hi2c1, 0x5c<<1, dataBuffer, 8, 200);

	uint16_t temperature = ((dataBuffer[4] & 0x7F)<<8) + dataBuffer[5];
	t = temperature/10.0;

	uint16_t humidity = (dataBuffer[2]<<8) + dataBuffer[3];
	h = humidity/10.0;

}

void get_potentiometer_value(){

	potentiometer_val = HAL_ADC_GetValue(&hadc1);

}

