#include <iostream>
#include <csignal>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void signalHandler(int signum){
  cout << "Interupt signal (" << signum << ") received.\n";

  //clean up and close up stuff here

  //terminate program
  exit(signum);
}

int main(int argc, char **argv){
  //register signal SIGINT and it's handler
  signal( SIGINT, signalHandler);

  while(1){
    cout << "Going to sleep ..." << endl;
    sleep(5);
  }

  return 0;
}
