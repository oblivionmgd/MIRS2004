#include <stdlib.h>
#include <stdio.h>

int main() {
  printf("1");
  char passbuff[] = "python /home/pi/MIRS2004/mg4_pi_ver4.0.0/deg.py";
  //char passbuff[] = "python /home/pi/MIRS2004/mg4_pi_ver4.0.0/hoge.py &";
  printf("2");
  system(passbuff);
  printf("3");
  FILE *fpi;
  printf("4");
  int deg;
  printf("5");
  fpi=fopen("test.txt","r");
  printf("6");
  fscanf(fpi,"%d",&deg);
  printf("7");
  printf("%d\n",deg);
  printf("8");
  return 0;
}
