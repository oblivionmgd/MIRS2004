#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "arduino.h"
#include "request.h"

int main(){
    int mode;
    run_state_t state;
    conv_state_t conv_state;
    
    if(arduino_open() != 0) return -1;

    usleep(1000*1000);
    
    printf("stop\n");
    mode = 1;
    
    usleep(1000*1000);
    
    switch(mode){
    case 1:
	request_set_runmode(STP, 0, 0);
	request_set_convmode(ST);
	printf("set\n");
	while(1){
		request_get_runmode(&state, &speed, &dist);
		request_get_convmode(&conv_state);
		if( state == STP ){
		request_set_runmode(STP, 0, 0);
		request_set_convmode(ST);
		break;
	    }
	}
	break;
    }
}
