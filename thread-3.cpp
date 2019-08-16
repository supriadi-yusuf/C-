#include <iostream>
#include <cstdlib> //header file for exit(x)
#include <pthread.h>
#include <unistd.h> // header file for sleep(x)

using namespace std;

#define TOTAL_THREAD 15

void* do_something(void * thread_arg){
  long arg = (long) thread_arg;

  for(int i=0; i<10; i++){
    sleep(1);
    cout << "hello ... : " << i << " thread " << arg << endl;
  }

  pthread_exit(NULL);
}

int main(void){
  pthread_t threads[TOTAL_THREAD];
  int rc;

  for( int i=0; i<TOTAL_THREAD; i++){ 
     cout << "main() : creating thread, " << i << endl;
     rc = pthread_create( &threads[i], NULL, do_something, (void *)i);
     if( rc ){
       cout << "creating thread is failure" << endl;
       exit(-1);
     }

  }

  cout << "main() : almost finish." << endl;

  pthread_exit(NULL);

  cout << "main() : finish." << endl;

  return 0;
}

/******************************************************************
Messages are displayed so messy. We need to syncronize thread.
******************************************************************/
