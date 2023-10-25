/**********************************************************************
* Filename    : PwmLed.c
* Description : Make a breathing led with soft PWM.
* Author      : Cavon
* E-mail      : service@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2017/10/17
**********************************************************************/

#include <pigpio.h>
#include <stdio.h>
#include <unistd.h>

#define LedPin    18

int main(void)
{
	int i;

	if(gpioInitialise() < 0){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1;
	}

	while(1){
		for(i=0;i<=255;i++){
			gpioPWM(LedPin, i);
			sleep(1);
		}
		sleep(1);
		for(i=255;i>=0;i--){
			gpioPWM(LedPin, i);
			sleep(1);
		}
	}

	return 0;
}

