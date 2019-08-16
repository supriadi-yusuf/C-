#include <iostream>
#include <csignal>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void signalHandler(int signum){
  cout << "Interupt signal (" << signum << ") received.\n"; 
  exit(signum);
}

int main(int argc, char **argv){
  int i=0;

  //register signal
  signal(SIGINT, signalHandler);

  while(++i){
    cout << "Going to sleep ..." << endl;

    if( i== 3){
       raise(SIGINT);
    }

    sleep(5);
  }
  
  return 0;
}
