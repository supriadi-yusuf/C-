/***********************************
Compile :

g++ thread-5.cpp -pthread -std=c++11 -o thread-5

or

g++ thread-5.cpp -pthread -std=gnu++11 -o thread-5

***********************************/
#include <iostream> 
#include <sstream>
#include <thread> 

using namespace std;
 
void threadFn1(){
  cout << "inside threadFn1 function\n";
}

void threadFn2(int prm){
  stringstream sprm;
  sprm << prm;

  string s="inside threadFn2 function, prm = " + sprm.str() +"\n";
  cout << s;
}

void threadFn3(int prm1, int prm2){
  stringstream sprm1;
  sprm1 << prm1;

  stringstream sprm2;
  sprm2 << prm2;

  string s="inside threadFn3 function, prm1 = " + sprm1.str() + ", prm2 = " + sprm2.str() + "\n";
  cout << s;
}

void threadFn4(int& prm){
  stringstream sprm;
  sprm << prm;

  string s="inside threadFnx function, prm = " + sprm.str() +"\n";
  cout << s;

  prm++;
}

int main(int argc, char* argv[]){
  int v1=10;
  int v2=100;

  // before threads are executed
  cout << "v1 = " << v1 << endl;
  cout << "v2 = " << v2 << endl;

  thread t1(threadFn1);
  thread t2{threadFn1};
  thread t3(threadFn2, 5);
  thread t4{threadFn2, v1};
  thread t5(threadFn3, v1, v2);
  thread t6{threadFn4, ref(v2)};
  thread t7([](const char* nama){ // lambda
           cout << "hello " << nama << ", how are you doing? from lambda" << endl;
         }, "supriadi");

  t1.join(); 
  t2.join(); 
  t3.join(); 
  t4.join(); 
  t5.join(); 
  t6.join(); 
  t7.join();


  // after threads are executed
  cout << "v1 = " << v1 << endl;
  cout << "v2 = " << v2 << endl;

  return 0;
}
