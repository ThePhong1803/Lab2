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

void update7SEG(){
	switch(index_led){
		case 0:
			//Display the first 7SEG with led_buffer[0]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index_led]);
			break;
		case 1:
			//Display the second 7SEG with led_buffer[1]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index_led]);
			break;
		case 2:
			//Display the third 7SEG with led_buffer[2]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			display7SEG(led_buffer[index_led]);
			break;
		case 3:
			//Display the forth 7SEG with led_buffer[3]
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			display7SEG(led_buffer[index_led]);
			break;
		default:
			break;
	}
	index_led = (index_led + 1) % 4;
}


void updateClockBuffer(){
	led_buffer[0] = (hour / 10) % 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = (minute / 10) % 10;
	led_buffer[3] = minute % 10;
}

int index_led_matrix = 0;
int index_row = 0;
uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

void updateMatrixBuffer(){
	//this is a demo, only display letter a
	int char_A[8] = {0xe7, 0xc3, 0x99, 0x99, 0x81, 0x81, 0x99, 0x99};
	matrix_buffer[0] = char_A[0];
	matrix_buffer[1] = char_A[1];
	matrix_buffer[2] = char_A[2];
	matrix_buffer[3] = char_A[3];
	matrix_buffer[4] = char_A[4];
	matrix_buffer[5] = char_A[5];
	matrix_buffer[6] = char_A[6];
	matrix_buffer[7] = char_A[7];
}

void setRowPin(){
	//first set the high byte of PORTB to 0 and preserve the low byte of PORTB
	GPIOB -> ODR &= 0x00ff;
	//shifted the value in buffer and add it to output data register of PORTB
	GPIOB -> ODR += (matrix_buffer[index_row] << 8);
	//update index of matrix row
	index_row = (index_row + 1) % MAX_LED_MATRIX;
}

void updateLEDMatrix(){
	//every time this fucntion is called, only one column is turn on
	//set the row pin of the led matrix at row index and update row index
	setRowPin();
	//depend on value of index_led_matrix, each column of matrix is light up
	switch(index_led_matrix){
		case 0:
			//turn on the first column
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			break;
		case 1:
			//turn on the second column
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			break;
		case 2:
			//turn on the third column
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			break;
		case 3:
			//turn on the forth column
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			break;
		case 4:
			//turn on the fifth column
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			break;
		case 5:
			//turn on the sixth column
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			break;
		case 6:
			//turn on the seventh column
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, SET);
			break;
		case 7:
			//turn on the eighth column
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, SET);
			HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, SET);
			HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, SET);
			HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, SET);
			HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, SET);
			HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, SET);
			HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, SET);
			HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
			break;
		default:
			break;
	}
	//update the the index of matrix column to turn on next
	index_led_matrix = (index_led_matrix + 1) % MAX_LED_MATRIX;
}
