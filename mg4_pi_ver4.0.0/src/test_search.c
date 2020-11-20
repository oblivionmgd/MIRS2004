#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "request.h"
#include "position.h"
#include "test_search.h"

int main(){
	int speed, dist;
	double dist_l, dist_r, d_l, d_r, d_l2, d_r2, xl, yl, x, y, dir;
	run_state_t state;

  if(arduino_open() != 0) return -1;

  position_set_first(0, 0, 90);

  request_set_runmode(ROT, 45, 360);
	request_get_dist(&dist_l, &dist_r);
	d_l = dist_l;
	d_r = dist_r;
  while(1){
    request_get_runmode(&state, &speed, &dist);
    if( state == STP ) break;
    if(){
      request_set_runmode(STP, 0, 0);
      break;
    }
    usleep(10*1000);
  }

  usleep(1000*1000);

	request_get_dist(&dist_l, &dist_r);
	d_l = dist_l - d_l;
	d_r = dist_r - d_r;
	position_set_coord(d_l, d_r);

  speed = 30;
	dist = 400;

	position_get_field(&xl, &yl);
  request_set_runmode(STR, speed, dist);
	request_get_dist(&dist_l, &dist_r);
  d_l = dist_l;
  d_r = dist_r;
  while(1){
    request_get_runmode(&state, &speed, &dist);
		request_get_dist(&dist_l, &dist_r);
		d_l2 = dist_l - d_l;
		d_r2 = dist_r - d_r;
		position_set_coord(d_l2, d_r2);
		position_get_coord(&x, &y, &dir);
		if( x > xl || x < 0){
			//反転して探索に戻る

		}
		if( y > yl || y < 0){


		}
    if( state == STP ) break;
    if(){
      request_set_runmode(STP, 0, 0);
      break;
    }
    usleep(10*1000);
  }

	usleep(1000*1000);

	request_get_dist(&dist_l, &dist_r);
	d_l = dist_l - d_l;
	d_r = dist_r - d_r;
	position_set_coord(d_l, d_r);

  arduino_close();
	return 0;
}
