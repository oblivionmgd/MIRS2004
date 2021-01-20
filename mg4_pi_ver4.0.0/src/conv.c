#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "arduino.h"
#include "request.h"
#include "conv_run.h"

int main(){
    int mode;
    
    if(arduino_open() != 0) return -1;
    
    printf("test\n");
    mode = 1;
    
    switch(mode){
    case 1:
	while(1){
	    conv_run();
	}
	break;
    }
}
