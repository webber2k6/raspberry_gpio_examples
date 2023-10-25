/**********************************************************************
* Filename    : beep.c
* Description : make a buzzer sound.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <pigpio.h>
#include <stdio.h>
#include <unistd.h>

#define BeepPin 18

int main(void)
{
	if(gpioInitialise() < 0){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1;
	}

	gpioSetMode(BeepPin, PI_OUTPUT);   //set GPIO0 output

	while(1){
		printf("Beep!");
		gpioWrite(BeepPin, 0);  //beep on
		sleep(1);                  //delay

		printf("Stop!");
		gpioWrite(BeepPin, 1); //beep off
		sleep(2);                  //delay
	}

	return 0;
}

