#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

extern void emergency_thread();
extern void func_thread();

int main(void){
  pthread_t tid_A, tid_B;
  pthread_create( &tid_A, NULL, &emergency_thread, NULL );
  pthread_create( &tid_B, NULL, &func_thread, NULL );

  pthread_join(tid_A);
  pthread_join(tid_B);

  return 0;
}
