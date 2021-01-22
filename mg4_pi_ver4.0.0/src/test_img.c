#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*void open_img(){
	FILE	*fp;
	char	buf[1024];
	int		i,size;
	fp = fopen("../MIRSFace/smile.png","rb");
	if(fp != NULL){
		while(size = fread( buf, sizeof(unsigned char), 1024, fp )){
			for(i = 0 ; i < size ; i++){
				printf("%c", buf[i]);
			}
		}
		fclose(fp);
	}
}*/

int main(){
	//int count;
	//printf("content-type: image/peng\n\n");
	//open_img();
	FILE *fp;
	while(1){
	fp = fopen("../MIRSFace/senden.jpg", "rb");
} 
	return 0;
}
