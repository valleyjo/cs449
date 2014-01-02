#include <stdio.h>
#include <pthread.h>

void *thread(void* id){

  while(1){
    printf("Hello from thread %d-A\n", *(int *)id);
    pthread_yield();
    printf("Hello from thread %d-B\n", *(int *)id);
  }
}

int main(){

  pthread_t thread1;
  int id1, id2, arg1 = 1, arg2 = 2;

  id1 = pthread_create(&thread1, NULL, thread, (void *)&arg1);

  thread((void *)&arg2);

  return 0;
}
