static conv_state_t conv_ctrl_state = STOP;


void motor_conveyor_open(){
  pinMode(PIN_CON_DIR, OUTPUT);
  pinMode(PIN_CON_PWM, OUTPUT);
  analogWrite(PIN_CON_PWM, 0);
  }

void conv_ctrl_execute(){
  switch (conv_ctrl_state) {
    case STOP:
      digitalWrite(PIN_CON_DIR, LOW);
      analogWrite(PIN_CON_PWM, 0);
      break;
    case ROTE:
      digitalWrite(PIN_CON_DIR, HIGH);
      analogWrite(PIN_CON_PWM, 100);
      break;
  }
  
}

void conv_ctrl_set(conv_state_t conv_state) {
  conv_ctrl_state = conv_state;
}

void conv_ctrl_get(conv_state_t *conv_state) {
  *conv_state = conv_ctrl_state;
}

void motor_conveyor_set(int pwm_c) {
  // モータ回転方向の補正
  pwm_c *= -1;

  if (pwm_c >  255) pwm_c =  255;
  if (pwm_c < -255) pwm_c = -255;

  if (pwm_c > 0) {
    digitalWrite(PIN_CON_DIR, HIGH);
    analogWrite(PIN_CON_PWM, pwm_c);
  } else {
    digitalWrite(PIN_CON_DIR, LOW);
    analogWrite(PIN_CON_PWM, -pwm_c);
  }
}
