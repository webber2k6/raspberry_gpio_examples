/**********************************************************************
* Filename    : rotaryEncoder.c
* Description : make a rotaryEncoder work.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <pigpio.h>
#include <unistd.h>

#define  RoAPin    17
#define  RoBPin    18
#define  RoSPin    27

static volatile int globalCounter = 0 ;

unsigned char flag;
unsigned char Last_RoB_Status;
unsigned char Current_RoB_Status;

void rotaryDeal(void)
{
	Last_RoB_Status = gpioRead(RoBPin);

	while(!gpioRead(RoAPin)){
		Current_RoB_Status = gpioRead(RoBPin);
		flag = 1;
	}

	if(flag == 1){
		flag = 0;
		if((Last_RoB_Status == 0)&&(Current_RoB_Status == 1)){
			globalCounter ++;
			printf("globalCounter : %d\n",globalCounter);
		}
		if((Last_RoB_Status == 1)&&(Current_RoB_Status == 0)){
			globalCounter --;
			printf("globalCounter : %d\n",globalCounter);
		}

	}
}

void rotaryClear(void)
{
	if(gpioRead(RoSPin) == 0)
	{
		globalCounter = 0;
		printf("globalCounter : %d\n",globalCounter);
		sleep(1);
	}
}

int main(void)
{
	if(gpioInitialise() < 0){
		fprintf(stderr, "Unable to setup wiringPi:%s\n",strerror(errno));
		return 1;
	}

	gpioSetMode(RoAPin, PI_INPUT);
	gpioSetMode(RoBPin, PI_INPUT);
	gpioSetMode(RoSPin, PI_INPUT);

	gpioSetPullUpDown(RoSPin, PI_PUD_UP);

	while(1){
		rotaryDeal();
		rotaryClear();
	}

	return 0;
}
