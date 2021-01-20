#include <stdlib.h>
#include <stdio.h>

int deg() {
  char passbuff[] = "python /home/pi/MIRS2004/mg4_pi_ver4.0.0/deg.py";
  system(passbuff);
  FILE *fpi;
  int deg;
  fpi=fopen("deg.txt","r");
  fscanf(fpi,"%d",&deg);
  deg = -deg;
  return deg;
}
