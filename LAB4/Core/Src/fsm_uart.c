/*
 * fsm_uart.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */
#include "fsm_uart.h"



void uart_communication_fsm(){
	switch(uart_status){
	 case WAIT_FOR_COMMAND:
		if(print_commnad==1){
			accept_print();


		}

		break;

	 case SEND_VALUE:
		 send_value_active=1;

			ADC_value= HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit (& huart2 , (uint8_t *) str , sprintf (str , "!ADC=%lu#\r\n"
			,ADC_value ), 1000) ;
			setTimer2(50);


		break;
	default:
		break;
	}

}

