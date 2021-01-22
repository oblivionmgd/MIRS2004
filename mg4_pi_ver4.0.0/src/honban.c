#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "arduino.h"
#include "request.h"
#include "deg.h"
#include "uss.h"

int main(){
  int mode, speed, dist, motor_mode, ball_deg;
  double volt;
  run_state_t state;
  conv_state_t conv_state;
  long uss_l, uss_r;//各変数定義

  if(arduino_open() != 0) return -1;
	if(uss_open_l() != 0) return -1;//arduinoと超音波センサ起動
  if(uss_open_r() != 0) return -1;

  request_set_runmode(STP, 0, 0);
  request_set_convmode(RT);//コンベア始動
        request_get_convmode(&conv_state);
  usleep(500*1000);

while(1){
/*ボールを見つけるまで回転する　ここから*/
  while(1){
    //ball_deg = deg();//ボールの角度算出
        deg(&ball_deg);
    if(ball_deg == 200){//見つからなかったら
      request_set_runmode(ROT, 45, 30); //30°回転
      while(1){
        request_get_runmode(&state, &speed, &dist);
        if( state == STP ) break;
      }
    }else{//見つかったら
            ball_deg = -ball_deg*0.75;
      request_set_runmode(ROT, 45, ball_deg);//ボールのほうを向く
      while(1){
        request_get_runmode(&state, &speed, &dist);
        if( state == STP ) break;
      }
      break;//かつ、ループ抜け出し
    }
    usleep(500*1000);
  }
/*ボールを見つけるまで回転する　ここまで*/

/*ボールのほうに向かう ここから*/
  usleep(500*1000);
  request_set_runmode(STR, 40, 150);//150cm進む
  request_set_convmode(RT);
    request_get_convmode(&conv_state);
  while(1){
    request_get_runmode(&state, &speed, &dist);//150cm進むまでループ

    if( state == STP ) break;

    uss_l = uss_get_l();
    uss_r = uss_get_r();//超音波センサ取得
    if((uss_l < 50) || (uss_r < 50)){//50センチ以下になったら
      request_set_runmode(STP, 0, 0);//一度止まる
      break;
    }
  }
  if()
      request_set_runmode(STR, 40, -30);//少し下がる
      while(1){
        request_get_runmode(&state, &speed, &dist);
        if( state == STP ) break;
      }
      usleep(500*1000);
      request_set_runmode(ROT, 45, 180);//180°回転
      while(1){
        request_get_runmode(&state, &speed, &dist);
        if( state == STP ) break;
      }
      break;
    }
    usleep(8000*1000);
    request_set_convmode(ST);
    request_get_convmode(&conv_state);

  }
/*ボールのほうに向かう ここまで*/
}
}
