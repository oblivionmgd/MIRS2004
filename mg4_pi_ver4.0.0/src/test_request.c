#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "arduino.h"
#include "request.h"
#include "deg.h"

int main(){
    int mode, speed, dist, motor_mode, dg;
    //char passbuf[] = "python3 /home/pi/MIRS2004/MIRSFace/face.py &";
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
        request_set_convmode(ST);
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
        }
				break;
			case 7:
        printf("1入れて\n");
        scanf("%d",&mode);
        switch(mode){
          case 1:
            //一個目
            request_set_runmode(ROT, 45, -20);
            request_set_convmode(ST);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
                usleep(10*1000);
            }
            usleep(1000*1000);

            request_set_runmode(STR, 30, 100);
            request_set_convmode(RT);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
              usleep(10*1000);
            }
            usleep(1000*1000);

            //二個目
            request_set_runmode(ROT, 45, 80);
            request_set_convmode(RT);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
              usleep(10*1000);
            }
            usleep(1000*1000);

            request_set_runmode(STR, 30, 80);
            request_set_convmode(RT);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
              usleep(10*1000);
            }
            usleep(1000*1000);

            //三個目
            request_set_runmode(ROT, 45, -90);
            request_set_convmode(RT);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
              usleep(10*1000);
            }
            usleep(1000*1000);

            request_set_runmode(STR, 30, 50);
            request_set_convmode(RT);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
              usleep(10*1000);
            }
            usleep(1000*1000);

            request_set_runmode(ROT, 45, 25);
            request_set_convmode(RT);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
                usleep(10*1000);
            }
            usleep(1000*1000);

            request_set_runmode(STR, 30, 150);
            request_set_convmode(RT);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
              usleep(10*1000);
            }
            usleep(1000*1000);

            request_set_convmode(ST);
            request_get_convmode(&conv_state);
            break;
          }
            break;

      case 8:
        printf("speed? [cm/s]\n");
        scanf("%d",&speed);
        printf("dist? [cm]\n");
        scanf("%d",&dist);

        request_set_runmode(STR, speed, dist);
        request_set_convmode(RT);
        //system(passbuf);
        while(1){
          request_get_runmode(&state, &speed, &dist);
          request_get_convmode(&conv_state);
          if( state == STP ) break;
        }

        break;
      case 9://teisi
        printf("speed? [cm/s]\n");
        scanf("%d",&speed);
        printf("dist? [cm]\n");
        scanf("%d",&dist);

        request_set_runmode(STR, speed, dist);
        request_set_convmode(RT);
        while(1){
          request_get_runmode(&state, &speed, &dist);
          request_get_convmode(&conv_state);
          if( state == STP ){
            request_set_convmode(ST);
            break;
          }
        }
        break;
      case 10:
        printf("speed? [cm/s]\n");
        scanf("%d",&speed);
        printf("dist? [cm]\n");
        scanf("%d",&dist);

        request_set_runmode(STR, 30, 50);
            request_set_convmode(ST);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
              usleep(10*1000);
            }
            usleep(1000*1000);

        request_set_runmode(ROT, 45,95 );
            request_set_convmode(ST);
            while(1){
              request_get_runmode(&state, &speed, &dist);
              request_get_convmode(&conv_state);
              if( state == STP ) break;
              usleep(10*1000);
            }
            usleep(1000*1000);

        request_set_runmode(STR, 30, 50);
        request_set_convmode(RT);
        while(1){
          request_get_runmode(&state, &speed, &dist);
          request_get_convmode(&conv_state);
          if( state == STP ){
            request_set_convmode(ST);
            break;
          }
        }
        break;

      case 11:
        request_set_runmode(STP, 0, 0);
        request_set_convmode(ST);
        //scanf("%d",&mode);
        //dg = deg();
        printf("%d",dg);
        if(dg != 200){
	  dg = -dg;
          printf("%d",dg);
	        usleep(100*1000);
          request_set_runmode(ROT, 45, dg);
          while(1){
            request_get_runmode(&state, &speed, &dist);
            request_get_convmode(&conv_state);
            if( state == STP ) break;
            usleep(10*1000);
          }
          usleep(1000*1000);

          request_set_runmode(STR, 40, 150);
          request_set_convmode(RT);
          while(1){
            request_get_runmode(&state, &speed, &dist);
            request_get_convmode(&conv_state);
            if( state == STP )  break;
            usleep(10*1000);
          }
	        request_set_convmode(ST);
        }
        break;
      }
      arduino_close();
      return 0;
    }
}
