#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "arduino.h"
#include "request.h"
#include "conv_run.h"

void conv_run(){
    int mode;
    //char passbuf[] = "python3 /home/pi/MIRS2004/MIRSFace/face.py &";
    //double volt;
    //char buf[256];
    //run_state_t state;
    conv_state_t conv_state;
    
    //if(arduino_open() != 0) return -1;

    //scanf("%d",&mode);
    
    printf("test\n");
    mode = 1;
    
    switch(mode){
    case 1:
	//request_set_runmode(STP, 0, 0);
	request_set_convmode(RT);
	printf("set\n");
	while(1){
		//request_get_runmode(&state, &speed, &dist);
		request_get_convmode(&conv_state);
		printf("get\n");
		/*if( conv_state == ST ){
		//request_set_runmode(STP, 0, 0);
		request_set_convmode(ST);
		printf("stop\n");
		break;
	    }*/
	}
	break;
    }
}
