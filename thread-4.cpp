/************************************************************
we need lock to synchonize thread.
************************************************************/

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define TOTAL_THREAD 15

pthread_mutex_t lock;

void* do_something(void * thread_arg){
  long arg = (long) thread_arg;

  for(int i=0; i < 10; i++){
    sleep(1);

    pthread_mutex_lock(&lock);//lock

    cout << "hello ... " << i << " thread " << arg << endl;

    pthread_mutex_unlock(&lock);//release
  }

  //pthread_exit(NULL);
}

int main(void){
  pthread_t threads[TOTAL_THREAD];
  int rc;

  if( pthread_mutex_init(&lock, NULL) ){
     cout << "mutex init failed " << endl;
     return 1;
  }

  for(int i=0; i < TOTAL_THREAD; i++){
    cout << "main() : creating thread " << i << endl;
    rc = pthread_create( &threads[i], NULL, do_something, (void*) i);
    if( rc ){
       cout << "failure to create thread " << endl;
       //exit(-1);
    }

  }

  cout << " all threads have been created." << endl;

  for(int i=0; i < TOTAL_THREAD; i++)
    rc = pthread_join( threads[i], NULL); 

  cout << " all threads have been joined." << endl;

  pthread_mutex_destroy(&lock);

  cout << " lock has been destroyed." << endl;

  return 0;
}
