#include "gui.h"

void GUI_init() {
	ILI9341_Init();
	ILI9341_Set_Rotation(3);
	ILI9341_Fill_Screen(WHITE);

	red_percent = 0;
	green_percent = 0;
	blue_percent = 0;
}

void first_page() {

	// render
	draw_color_buttons();
	draw_progress_bars();
	draw_color_percent();

	// update
	update_progress_bars();

}

void draw_color_buttons() {

	ILI9341_Draw_Filled_Circle(40, 100, 20, RED);
	ILI9341_Draw_Filled_Circle(40, 150, 20, GREEN);
	ILI9341_Draw_Filled_Circle(40, 200, 20, BLUE);

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

void draw_color_percent() {

	char str[10];

	sprintf(str,"%d%%",red_percent);
	ILI9341_Draw_Text(str, 250, 90, BLACK, 3, WHITE);

	sprintf(str,"%d%%",green_percent);
	ILI9341_Draw_Text(str, 250, 140, BLACK, 3, WHITE);

	sprintf(str,"%d%%",blue_percent);
	ILI9341_Draw_Text(str, 250, 190, BLACK, 3, WHITE);

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
				//	ILI9341_Draw_Filled_Rectangle_Coord(250, Y0, X1, Y1, Colour)
				}


			}

			// push green button
			if (coordinates[0] > 130 && coordinates[0] < 180
					&& coordinates[1] < 310 && coordinates[1] > 260) {
				green_percent += 10;
				if (green_percent > 100) {
					green_percent = 0;
					ILI9341_Fill_Screen(WHITE);
				}
			}

			// push blue button
			if (coordinates[0] > 190 && coordinates[0] < 220
					&& coordinates[1] < 310 && coordinates[1] > 260) {
				blue_percent += 10;
				if (blue_percent > 100) {
					blue_percent = 0;
					ILI9341_Fill_Screen(WHITE);
				}
			}

			HAL_Delay(200);

		}

	}

}
