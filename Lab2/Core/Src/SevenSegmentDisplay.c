/*
 * SevenSegmentDisplay.c
 *
 *  Created on: Oct 4, 2022
 *      Author: PC
 */


#include "SevenSegmentDisplay.h"

void display7SEG(int num){
	if(num == 0){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0040;
	}
	if(num == 1){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0079;
	}
	if(num == 2){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0024;
	}
	if(num == 3){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0030;
	}
	if(num == 4){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0019;
	}
	if(num == 5){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0012;
	}
	if(num == 6){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0002;
	}
	if(num == 7){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0078;
	}
	if(num == 8){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0080;
	}
	if(num == 9){
		GPIOB -> ODR &= 0xff00;
		GPIOB -> ODR |= 0x0090;
	}
}
