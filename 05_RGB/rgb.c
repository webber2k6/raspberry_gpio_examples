/**********************************************************************
* Filename    : rgb.c
* Description : Make a rgb led emits a various color.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <pigpio.h>
#include <stdio.h>
#include <unistd.h>

#define uchar unsigned char

#define LedPinRed    17
#define LedPinGreen  18
#define LedPinBlue   27

void ledColorSet(unsigned r_val, unsigned g_val, unsigned b_val)
{
	printf("R - %d, G - %d, B - %d\n", r_val, g_val, b_val);
	gpioPWM(LedPinRed,   r_val);
	gpioPWM(LedPinGreen, g_val);
	gpioPWM(LedPinBlue,  b_val);
}

int main(void)
{
	int i;

	if(gpioInitialise() < 0){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1;
	}
	//printf("linker LedPin : GPIO %d(wiringPi pin)\n",LedPin); //when initialize wiring successfully,print message to screen

	while(1){
		ledColorSet(255,0,0);   //red
		sleep(1);
		ledColorSet(0,255,0);   //green
		sleep(1);
		ledColorSet(0,0,255);   //blue
		sleep(1);

		ledColorSet(255,255,0);   //yellow
		sleep(1);
		ledColorSet(255,0,255);   //pick
		sleep(1);
		ledColorSet(192,255,62);
		sleep(1);

		ledColorSet(148,0,211);
		sleep(1);
		ledColorSet(118,238,0);
		sleep(1);
		ledColorSet(0,197,205);
		sleep(1);

	}

	return 0;
}
