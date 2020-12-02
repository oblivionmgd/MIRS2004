#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include "request.h"
#include "stop.h"
#include "C_send.h"
// ピン配置
static const int pin_sw_stop  = 7;

int stop_open(){
	// GPIOデバイスのオープン
	if(wiringPiSetupGpio() != 0){
		printf("failed to open GPIO\n");
		return -1;
	}else{
		// ピン設定
		pinMode(pin_sw_stop, INPUT);
		pullUpDnControl(pin_sw_stop, PUD_DOWN);
		printf("GPIO opened\n");
		
		wiringPiISR(pin_sw_stop,INT_EDGE_FALLING,stop);
		return 0;
	}
}

void stop(){
	int mode = 11;
	//int sw_stop;
	//sw_stop = digitalRead(pin_sw_stop);
	//printf("switch_stop = %d\n", sw_stop);
	//usleep(100*1000);
	request_set_runmode(STP, 0, 0);
	C_send(mode);
	_exit(0);
}
