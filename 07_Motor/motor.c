/**********************************************************************
* Filename    : motor.c
* Description : Controlling a motor.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <pigpio.h>
#include <stdio.h>
#include <unistd.h>

#define MotorPin1    17
#define MotorPin2    18
#define MotorEnable  27

int main(void)
{
	if(gpioInitialise() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1;
	}

	gpioSetMode(MotorPin1, PI_OUTPUT);
	gpioSetMode(MotorPin2, PI_OUTPUT);
	gpioSetMode(MotorEnable, PI_OUTPUT);

	int i;

	while(1){
		gpioWrite(MotorEnable, 1);
		gpioWrite(MotorPin1, 1);
		gpioWrite(MotorPin2, 0);
		for(i=0;i<3;i++){
			sleep(1);
		}

		gpioWrite(MotorEnable, 0);
		sleep(1);

		gpioWrite(MotorEnable, 1);
		gpioWrite(MotorPin1, 0);
		gpioWrite(MotorPin2, 1);
		for(i=0;i<3;i++){
			sleep(1);
		}

		gpioWrite(MotorEnable, 0);
                sleep(1);
	}

	return 0;
}
