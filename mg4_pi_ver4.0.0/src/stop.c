#include <stdio.h>
#include <unistd.h>
#include "request.h"
#include "stop.h"

int stop_open(){
	request_get_batt(volt);
		if( volt < 1 ){
			request_set_runmode(STP, 0, 0);
			_exit(0);
			break;
		}
}

/*void stop(){
	int mode = 11;
	//int sw_stop;
	//sw_stop = digitalRead(pin_sw_stop);
	//printf("switch_stop = %d\n", sw_stop);
	//usleep(100*1000);
	request_set_runmode(STP, 0, 0);
	_exit(0);
}*/
