#include <pigpio.h>
#include <stdio.h>
#include <unistd.h>

//make led_n on
void led_on(int n)
{
	gpioWrite(n, 0);
}

//make led_n off
void led_off(int n)
{
	gpioWrite(n, 1);
}

int leds[8] = { 17, 18, 27, 22, 23, 24, 25, 4 };
int main(void)
{
	int i;

	if(gpioInitialise() < 0){ //when initialize wiring failed,print messageto screen
		printf("setup failed !");
		return 1;
	}

	for(i=0;i<8;i++){
		printf("linker LedPin : GPIO %d(wiringPi pin) -> %d\n",i, leds[i]); //when initialize wiring successfully,print message to screen
	}

	for(i=0;i<8;i++){       //make 8 pins' mode is output
		gpioSetMode(leds[i], PI_OUTPUT);
		led_off(leds[i]);
	}

	while(1){
		for(i=0;i<8;i++){   //make led on from left to right
			led_on(leds[i]);
			sleep(1);
			led_off(leds[i]);
		}
		sleep(1);
		for(i=8;i>=0;i--){  //make led off from right to left
			led_on(leds[i]);
			sleep(1);
			led_off(leds[i]);
		}
	}

	return 0;
}

