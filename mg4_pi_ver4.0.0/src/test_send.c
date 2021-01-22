#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "C_send.h"

/* main function */
int main(){
	//double volt;
	char passbuf[] = "python3 /home/pi/MIRS2004/MIRSFace/test_face.py &"; //実行ファイルのパス
	int mode;

	system(passbuf); //main.py実行
	sleep(5);

	while(1){
		// 処理を記述
		mode = 0;
		printf("1:sumairu  2:nyounyo \n");
		scanf("%d",&mode);
		//printf("send:%d\n",mode);
		C_send(mode);
	}

	return 0;
}
