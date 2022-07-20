#include "Display.h"

void Display::draw() {
	for (int i = 0; i < GRID_HEIGHT; i++) {
		for (int k = 0; k < GRID_WIDTH; k++) {
			if (displayData[i][k] == 0) {
				drawPosition(k, i, false);
			}
			else {
				drawPosition(k, i, true);
			}
		}
	}
}