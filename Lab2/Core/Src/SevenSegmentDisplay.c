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

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index){
	switch(index){
		case 0:
			//Display the first 7SEG with led_buffer[0]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index]);
			break;
		case 1:
			//Display the second 7SEG with led_buffer[1]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index]);
			break;
		case 2:
			//Display the third 7SEG with led_buffer[2]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index]);
			break;
		case 3:
			//Display the forth 7SEG with led_buffer[3]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display7SEG(led_buffer[index]);
			break;
		default:
			break;
	}
}
