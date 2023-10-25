/**********************************************************************
* Filename    : led.c
* Description : Make an led blinking.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <pigpio.h>
#include <stdio.h>
#include <unistd.h>

#define  LedPin    17

int main(void)
{
	if (gpioInitialise() < 0)
        { //when initialize failed, print message
		printf("setup wiringPi failed !");
		return 1;
	}

	printf("linker LedPin : GPIO %d(wiringPi pin)\n", LedPin);
	gpioSetMode(LedPin, PI_OUTPUT);

	while(1){
			gpioWrite(LedPin, 0);  //led on
			printf("led on...\n");
			sleep(5);
			gpioWrite(LedPin, 1);  //led off
			printf("...led off\n");
			sleep(5);
	}

	return 0;
}

