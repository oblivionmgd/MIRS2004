#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "request.h"
#include "uss.h"
#include "test_avoid.h"

//回避動作のテストプログラム
int main(){
	int speed, dist;
	long uss_l, uss_r, dist_l, dist_r, d_l, d_r, d_lo, d_ro;
	run_state_t state;

  if(arduino_open() != 0) return -1;
	if(uss_open_l() != 0) return -1;
	if(uss_open_r() != 0) return -1;

	position_set_first(0, 0, 90);

  //while(1){
		speed = 30;
		dist = 400;

		request_set_runmode(STR, speed, dist);
		request_get_dist(&dist_l, &dist_r);
		d_l = dist_l;
		d_r = dist_r;
		while(1){
			request_get_runmode(&state, &speed, &dist);
			request_get_dist(&dist_l, &dist_r);
			d_lo = dist_l - d_l;
			d_ro = dist_r - d_r;
			d_l = dist_l;
			d_r = dist_r;
			position_set_coord(d_lo, d_ro);
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

    request_set_runmode(STR, 30, -60);
		request_get_dist(&dist_l, &dist_r);
	  d_l = dist_l;
	  d_r = dist_r;
		while(1){
			request_get_runmode(&state, &speed, &dist);
			if( state == STP ) break;
		}
		request_get_dist(&dist_l, &dist_r);
		d_lo = dist_l - d_l;
		d_ro = dist_r - d_r;
		position_set_coord(d_lo, d_ro);
	//}

	arduino_close();
	return 0;
}
