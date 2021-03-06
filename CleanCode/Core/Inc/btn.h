/*
 * btn.h
 *
 *  Created on: Jun 23, 2022
 *      Author: student
 */

#ifndef INC_BTN_H_
#define INC_BTN_H_

#include "main.h"
#include "clock.h"


typedef enum
{
	BUTTON_STATE_NONE = 0,
	BUTTON_STATE_PRESS,
	BUTTON_STATE_LONG_PRESS,
	BUTTON_STATE_DOUBLE
}BUTTON_STATE;

typedef struct BUTTON_
{
	BUTTON_STATE state ;
	GPIO_TypeDef* GPIO_port;
	uint16_t GPIO_Pin;
}BUTTON;


void Button_init(BUTTON* btn, GPIO_TypeDef* GPIO_port, uint16_t GPIO_Pin);

BUTTON_STATE checkBtnState(BUTTON* btn);


#endif /* INC_BTN_H_ */
