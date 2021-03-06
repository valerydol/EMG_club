/*
 * myMain.h
 *
 *  Created on: Jun 21, 2022
 *      Author: student
 */

#ifndef INC_MYMAIN_H_
#define INC_MYMAIN_H_
#include "main.h"
#include "btn.h"
#include "stm32l4xx_hal_gpio.h"
extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim3;



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
int myMain();

#endif /* INC_MYMAIN_H_ */
