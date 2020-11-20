#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "request.h"
#include "uss.h"
#include "test_avoid.h"

//回避動作のテストプログラム
int main(){
	int speed, dist;
	long uss_l, uss_r;
	run_state_t state;

  if(arduino_open() != 0) return -1;
	if(uss_open_l() != 0) return -1;
	if(uss_open_r() != 0) return -1;

  //while(1){
		speed = 30;
		dist = 400;

		request_set_runmode(STR, speed, dist);
		while(1){
			request_get_runmode(&state, &speed, &dist);
			if( state == STP ) break;

			uss_l = uss_get_l();
			uss_r = uss_get_r();
			printf("%d,%d\n",uss_l,uss_r);
			if((uss_l < 51) || (uss_r < 51)){
				request_set_runmode(STP, 0, 0);
				break;
			}
			usleep(10*1000);
		}

		usleep(1000*1000);

		request_set_runmode(ROT, 90, 180);
		while(1){
			request_get_runmode(&state, &speed, &dist);
			if( state == STP ) break;
		}
    request_set_runmode(STR, 30, 60);
		while(1){
			request_get_runmode(&state, &speed, &dist);
			if( state == STP ) break;
		}
	//}

	arduino_close();
	return 0;
}
