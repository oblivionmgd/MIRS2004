#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "request.h"

int main(){
	int speed, dist;
	run_state_t state,state_conv;

  if(arduino_open() != 0) return -1;


  //while(1){
		speed = 30;
		dist = 300;

		request_set_runmode(STR, 30, 100);
    //request_set_convmode(ROT);
		while(1){
			request_get_runmode(&state, &speed, &dist);
      //request_get_convmode(&state_conv);
			if( state == STP ){
        request_set_convmode(STP);
        //request_set_convmode(STP);
        break;
      }
			usleep(10*1000);
		}

		usleep(1000*1000);

	//}

	arduino_close();
	return 0;
}
