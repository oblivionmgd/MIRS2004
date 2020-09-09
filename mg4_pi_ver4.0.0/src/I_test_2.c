#include <stdio.h>
#include "arduino.h"
#include "I_test_2.h"

int main(){
	int mode, speed, dist, dist_a;
	run_state_t state;
	int num[4];
	
	if(arduino_open() != 0) return -1;

	for( int i=0 ; i<4 ; i++ ){
		if( i == 0 || i == 2 ) dist_a = 40;
		if( i == 1 || i == 3 ) dist_a = 100;
		num[i] = number_detect(dist_a);
		if(num[i]==-1)return -1;
		request_set_runmode(ROT, 45, 90);
		while(1){
			request_get_runmode(&state, &speed, &dist);
			if( state == STP ) break;
		}
	}
	
	int a;
	if( num[0] > num[1] && num[0] > num[2] && num[0] > num[3] ){a=0;}
	else if( num[1] > num[2] && num[1] > num[3] ){a=1;}
	else if( num[2] > num[3] ){a=2;}
	else{a=3;}
	
	int deg = a*90;
	request_set_runmode(ROT, 45, deg);
	while(1){
		request_get_runmode(&state, &speed, &dist);
		if( state == STP ) break;
	}

	arduino_close();
	return 0;
}
