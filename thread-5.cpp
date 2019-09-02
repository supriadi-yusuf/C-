/***********************************
Compile :

g++ thread-5.cpp -pthread -std=c++11 -o thread-5

or

g++ thread-5.cpp -pthread -std=gnu++11 -o thread-5

***********************************/
#include <iostream> 
#include <thread> 

using namespace std;
 
void threadFn(){
  cout << "hello ... from inside thread function" << endl;
}

int main(int argc, char* argv[]){
  thread t1(threadFn);

  t1.join(); 

  return 0;
}
