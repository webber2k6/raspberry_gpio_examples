/**********************************************************************
* Filename    : BtnAndLed.c
* Description : Controlling an led by button.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <pigpio.h>
#include <stdio.h>

#define LedPin    17
#define ButtonPin 18

int main(void)
{
	if(gpioInitialise() < 0){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1;
	}

	gpioSetMode(LedPin, PI_OUTPUT);
	gpioSetMode(ButtonPin, PI_INPUT);

	gpioSetPullUpDown(ButtonPin, PI_PUD_UP);  //pull up to 3.3V,make GPIO1 a stable level
	while(1){
		gpioWrite(LedPin, 1);
		if(gpioRead(ButtonPin) == 0){ //indicate that button has pressed down
			gpioWrite(LedPin, 0);   //led on
		}
	}

	return 0;
}

