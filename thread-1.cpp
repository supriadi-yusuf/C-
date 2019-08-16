/********************************************************************
thread
compile : g++ thread-1.cpp -lpthread -o thread-1
********************************************************************/

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *printHello(void *arg){
  long thread_id = (long) arg;

  cout << "Hello, thread id : " << thread_id << endl;
  pthread_exit(NULL);
}


int main(int argc, char **argv){
  pthread_t threads[NUM_THREADS];  
  int rc;

  for(int i=0; i<NUM_THREADS; i++){
     cout << "main() : creating thread, " << i << endl;
     rc = pthread_create( &threads[i], NULL, printHello, (void *) i);

     if(rc){
        cout << "Error : unable to create thread, " << i << endl;
        exit(-1);
     }
  }
  
  pthread_exit(NULL);
  return 0;
}

