/********************************************************************
thread with argument
compile : g++ thread-2.cpp -lpthread -o thread-2
********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <pthread.h>
//#include <sstream>

using namespace std;

#define NUM_THREADS 5

struct pthread_dt {
  int id;
  string msg;
};

void *printHello(void *pThreadArg){
  struct pthread_dt *arg = (struct pthread_dt *) pThreadArg;
 
  cout << "Hello, thread id : " << arg->id;// << endl;
  cout << " Message : " << arg->msg << endl;

  pthread_exit(NULL);
}

int main( int argc, char **argv){
  pthread_t threads[NUM_THREADS];
  struct pthread_dt thread_dt[NUM_THREADS];
  int rc;
  //ostringstream ss;

  for(int i=0; i<NUM_THREADS; i++){
     cout << "main() : creating thread, " << i << endl;

     thread_dt[i].id = i;
     //ss << i; 
     thread_dt[i].msg = "this is message " ;//+ ss.str();
     //cout << thread_dt[i].msg << endl;

     rc = pthread_create( &threads[i], NULL, printHello, (void *) &thread_dt[i]);

     if(rc){
        cout << "Error : unable to create thread " << i << endl;
        exit(-1);
     }

  }

  pthread_exit(NULL);

  return 0;
}
