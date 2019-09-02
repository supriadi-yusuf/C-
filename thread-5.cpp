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
  cout << "inside threadFn function\n";
}

void threadFn2(int value){
  cout << "inside threadFn2 function, value = " << value << endl;
}

void threadFn3(int& value){
  cout << "inside threadFn3 function, value = " << value << endl;
  value++;
}

int main(int argc, char* argv[]){
  thread t1(threadFn);
  thread t2{threadFn};

  t1.join(); 
  t2.join(); 

  return 0;
}
