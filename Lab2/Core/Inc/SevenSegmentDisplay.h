/*
 * SevenSegmentDisplay.h
 *
 *  Created on: Oct 4, 2022
 *      Author: PC
 */

#ifndef INC_SEVENSEGMENTDISPLAY_H_
#define INC_SEVENSEGMENTDISPLAY_H_

#include "main.h"

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

extern int hour;
extern int minute;
extern int second;

void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer();

#endif /* INC_SEVENSEGMENTDISPLAY_H_ */
