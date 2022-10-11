/*
 * SevenSegmentDisplay.h
 *
 *  Created on: Oct 4, 2022
 *      Author: PC
 */

#ifndef INC_SEVENSEGMENTDISPLAY_H_
#define INC_SEVENSEGMENTDISPLAY_H_

#include "main.h"
#include "global.h"

const int MAX_LED;
int index_led;
int led_buffer[4];

#define MAX_LED_MATRIX 8;
int index_led_matrix;
int index_row;
uint8_t matrix_buffer[8];

void display7SEG(int num);
void update7SEG();
void updateClockBuffer();

void updateLEDMatrix();
void updateMatrixBuffer();

#endif /* INC_SEVENSEGMENTDISPLAY_H_ */
