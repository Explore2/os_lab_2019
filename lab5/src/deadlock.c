#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


pthread_mutex_t lock1, lock2;

void *proccess1(){

      pthread_mutex_lock(&lock1);

      printf("Proccess1 starts\n");
      sleep(2);

      printf("trying to get proccess2 resources\n");
      pthread_mutex_lock(&lock2);
      printf("Getting proccess2 recources\n");
      pthread_mutex_unlock(&lock2);

      printf("Proccess1 stops\n");

      pthread_mutex_unlock(&lock1);

      pthread_exit(NULL);

}

void *proccess2(){

      pthread_mutex_lock(&lock2);

      printf("Proccess2 starts\n");
      sleep(2);

      printf("trying to get proccess1 resources\n");
      pthread_mutex_lock(&lock1);
      printf("Getting proccess1 recources\n");
      pthread_mutex_unlock(&lock1);

      printf("Proccess2 stop\n");

      pthread_mutex_unlock(&lock2);

      pthread_exit(NULL);

}

int main() {

      pthread_mutex_init(&lock1,NULL);
      pthread_mutex_init(&lock2,NULL);

      pthread_t t1,t2;

      pthread_create(&t1,NULL,proccess1,NULL);
      pthread_create(&t2,NULL,proccess2,NULL);

      pthread_join(t1,NULL);
      pthread_join(t2,NULL);

      return 0;

}
