#include <stdio.h>
#include <unistd.h>
#include "arduino.h"
#include "request.h"

int main(){
    int mode, speed, dist, motor_mode;
  double volt;
  //char buf[256];
  run_state_t state;
  conv_state_t conv_state;

    if(arduino_open() != 0) return -1;


  while(1){
    printf("0:stop  1:straight  2:rotate  3:get_mode  4:get_volt  5:quit\n");
    scanf("%d",&mode);

    switch(mode){
      case 0:
        request_set_runmode(STP, 0, 0);
        break;
      case 1:
        printf("speed? [cm/s]\n");
        scanf("%d",&speed);
        printf("dist? [cm]\n");
        scanf("%d",&dist);

        request_set_runmode(STR, speed, dist);
        while(1){
          request_get_runmode(&state, &speed, &dist);
          if( state == STP ) break;
        }

        break;
      case 2:
        printf("speed? [deg/s]\n");
        scanf("%d",&speed);

        printf("angle? [deg]\n");
        scanf("%d",&dist);

        request_set_runmode(ROT, speed, dist);
        while(1){
          request_get_runmode(&state, &speed, &dist);
          if( state == STP ) break;
        }
        break;
      case 3:
        request_get_runmode(&state, &speed, &dist);
        printf("state = %s\n",((state == STR) ? "STR" : (state == ROT) ? "ROT" : "STP"));
        break;
      case 4:
        request_get_batt(&volt);
        printf("batt = %4.2lf\n", volt);
        break;
      case 5:
        return 0;
      default:
        break;
      case 6:
        printf("mode\n");
        scanf("%d",&motor_mode);
        request_set_runmode(STP, 0, 0);
        request_set_convmode(RT);
        printf("set\n");
        while(1){
          request_get_runmode(&state, &speed, &dist);
          request_get_convmode(&conv_state);
          printf("get\n");
          if( conv_state == ST ){
            request_set_runmode(STP, 0, 0);
            request_set_convmode(ST);
            printf("stop\n");
            break;
          }
          break;
        }
			case 7:
				//printf("mode\n");
				//scanf("%d",&motor_mode);
				request_set_runmode(STR, 30, 100);
				printf("set\n");
				while(1){
					request_get_runmode(&state, &speed, &dist);
					printf("get\n");
					if( state == STP ){
						request_set_runmode(STP, 0, 0);
						printf("stop\n");
						break;
					}
					usleep(10*1000);
				}
				usleep(1000*1000);

				request_set_runmode(STR, 30, -100);
				printf("set\n");
				while(1){
					request_get_runmode(&state, &speed, &dist);
					printf("get\n");
					if( state == STP ){
						request_set_runmode(STP, 0, 0);
						printf("stop\n");
						break;
					}
					usleep(10*1000);
				}
				usleep(1000*1000);

				request_set_runmode(ROT, 45, 360);
				printf("set\n");
				while(1){
					request_get_runmode(&state, &speed, &dist);
					printf("get\n");
					if( state == STP ){
						request_set_runmode(STP, 0, 0);
						printf("stop\n");
						break;
					}
					usleep(10*1000);
				}
				break;
    }
  }
  arduino_close();
  return 0;
}
