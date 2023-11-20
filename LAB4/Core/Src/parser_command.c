/*
 * parser_command.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */
#include "parser_commnad.h"
void command_parser_fsm(){
	switch(parser_status){
		case START_PARSER:


			if(temp=='!'){

				parser_status=RECEIVE_COMMNAD;
				uart_status=WAIT_FOR_COMMAND;
				index_user_command=0;
			}

			break;

		case RECEIVE_COMMNAD:

			if(temp=='#'){

				check_commnad();


				parser_status=START_PARSER;

			}else if (temp!='#'){

			  user_commnad[index_user_command]=temp;
			  index_user_command++;
			}else if(temp=='!'){
				clear_user_command();
				index_user_command=0;
			}

			break;

		default:
			break;
	}



}

