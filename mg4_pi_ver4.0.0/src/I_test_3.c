#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "arduino.h"
#include "I_test_3.h"

int main(){
	int speed, dist;
	int sw_f, sw_l, sw_r;
	long uss_l, uss_r;
	run_state_t state;
	
	if(arduino_open() != 0) return -1;
	if(uss_open_l() != 0) return -1;
	if(uss_open_r() != 0) return -1;
	if(io_open() != 0) return -1;

	while(1){
		speed = 30;
		dist = 400;
	
		request_set_runmode(STR, speed, dist);
		while(1){
			request_get_runmode(&state, &speed, &dist);
			if( state == STP ) break;

			io_get_sw(&sw_f, &sw_l, &sw_r);
			printf("%d\n",sw_f);
			if( sw_f == 0 ){
				request_set_runmode(STP, 0, 0);
				break;
			}
			usleep(10*1000);

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

		srand((unsigned int)time(NULL));
		int randam;
		float deg_1, deg_2;
		randam = rand();
		printf("%d\n",randam);

		deg_1= (float)randam/(float)RAND_MAX;
		printf("%f\n",deg_1);
		if(deg_1 > 0.5){deg_1 = 1;}
		else{deg_1 = -1;}

		randam = rand();

		deg_2 = (float)(90.0 + (90.0*(float)randam/(float)RAND_MAX));
		printf("%f\n",deg_2);

		speed = 40;
		dist = (int)deg_1 * (int)deg_2;

		request_set_runmode(ROT, speed, dist);
		while(1){
			request_get_runmode(&state, &speed, &dist);
			if( state == STP ) break;
		}
	}
	
	arduino_close();
	return 0;
}
