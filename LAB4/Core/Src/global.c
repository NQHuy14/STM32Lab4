/*
 * global.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Huy
 */
#include "global.h"


uint8_t temp=0;
uint8_t buffer [ MAX_BUFFER_SIZE ]={0};
uint8_t index_buffer=0;
uint8_t buffer_flag=0;

uint8_t user_commnad[MAX_BUFFER_SIZE]={0};

char str[MAX_BUFFER_SIZE]={0};


int parser_status=0;
int uart_status=0;

int print_commnad=0;

int index_user_command=0;

uint32_t ADC_value=0;

int send_value_active=0;


void clear_user_command(){
	memset(user_commnad, 0, sizeof(user_commnad));
}


int stop_command(){
	if(user_commnad[0]=='O'&&user_commnad[1]=='K'&&user_commnad[2]==0) return 1;
	return 0;

}

int transmit_command(){
	if(user_commnad[0]=='R'&&user_commnad[1]=='S'&&user_commnad[2]=='T'&&user_commnad[3]==0) return 1;
	return 0;

}

void accept_print(){

	uint8_t * newLine = (uint8_t *)"\r\n";
	if(temp==*newLine){
		uart_status=SEND_VALUE;
		setTimer2(50);

		print_commnad=0;
	}


}

void check_commnad(){


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


}
