/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f4xx.h"

void gpio_init(){

	GPIO_InitTypeDef gpio;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_13;
	gpio.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_SetBits(GPIOG, GPIO_Pin_13);

}

void delay(int counter) {
	int i;
	for (i = 0; i < counter * 1000000; i++) {}
}

void main_loop(){
	GPIO_SetBits(GPIOG, GPIO_Pin_13); // LED ON
	delay(400);
	GPIO_ResetBits(GPIOG, GPIO_Pin_13); // LED OFF
	delay(400);
}


int main(void) {

	gpio_init();

	while (1) {
		main_loop();
	}
}
