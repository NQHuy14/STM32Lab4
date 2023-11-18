/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2023
 *      Author: Huy
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
int timer1_counter;
int timer2_counter;

void setTimer1(int duration);
void setTimer2(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
