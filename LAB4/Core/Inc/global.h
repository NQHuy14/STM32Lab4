/*
 * global.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "string.h"
#include "software_timer.h"

#define START_PARSER 1
#define RECEIVE_COMMNAD 2

#define WAIT_FOR_COMMAND 5
#define SEND_VALUE 6

extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;



# define MAX_BUFFER_SIZE 30



extern uint8_t temp;
extern uint8_t buffer [ MAX_BUFFER_SIZE ];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint32_t ADC_value;

extern uint8_t user_commnad[MAX_BUFFER_SIZE];

extern char str[MAX_BUFFER_SIZE];

extern int parser_status;
extern int uart_status;

extern int print_commnad;

extern int index_user_command;

void clear_user_command();

extern int stop_command();

extern int transmit_command();

extern int send_value_active;
#endif /* INC_GLOBAL_H_ */
