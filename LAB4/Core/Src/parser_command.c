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


                if(transmit_command()==1){
                	print_commnad=1;
    				clear_user_command();
                }else if(stop_command()==1){
                	send_value_active=0;
                	print_commnad=0;
    				clear_user_command();
                }else {
                 	print_commnad=0;
        			clear_user_command();
                }


                if(send_value_active==1){
				  uart_status=SEND_VALUE;
                }

				parser_status=START_PARSER;
			}else if (temp!='#'){

			  user_commnad[index_user_command]=temp;
			  index_user_command++;
			}

			break;

		default:
			break;
	}



}

