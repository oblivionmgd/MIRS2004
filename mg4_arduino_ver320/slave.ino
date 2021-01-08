void slave() {
  double speed, dist, dist_l, dist_r;
  run_state_t state;
  conv_state_t conv_state;
  command_data_t command_data;
  
  while (1) {
    if (raspi_receive(&command_data) == 0) {
      switch (command_data.val[0]) {
        case 1:
          run_ctrl_set(STP, 0, 0);
          break;
        case 2:
          run_ctrl_set(STR, command_data.val[1], command_data.val[2]);
          break;
        case 3:
          run_ctrl_set(ROT, command_data.val[1], command_data.val[2]);
          break;
        case 4:
          conv_ctrl_set(ST);
          break;
        case 5:
          conv_ctrl_set(RT);
          break;
        case 10:
          run_ctrl_get(&state, &speed, &dist);
          command_data.val[0] = ((state == STR) ? 2 : (state == ROT) ? 3 : 1);
          command_data.val[1] = (short)speed;
          command_data.val[2] = (short)dist;
          raspi_send(command_data);
          break;
        case 11:
          distance_get(&dist_l, &dist_r);
          command_data.val[0] = (short)dist_l;
          command_data.val[1] = (short)dist_r;
          raspi_send(command_data);
          break;
        case 12:
          command_data.val[0] = (short)(io_get_batt() * 100.0);
          raspi_send(command_data);
          break;
        case 13:
          conv_ctrl_get(&conv_state);
          command_data.val[0] = ((conv_state == RT) ? 5 : 4);
          raspi_send(command_data);
          break;
        default:
          break;
      }
    }
    run_ctrl_execute();
    vel_ctrl_execute();
    conv_ctrl_execute();
    delay(T_CTRL);
  }
}
