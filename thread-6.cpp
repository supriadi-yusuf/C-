#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex my_mutex;

void threadFn(const char* nama){
 
  my_mutex.lock();

  for(int i=1; i <= 10; i++){
     cout << nama << ":" << i << endl;    
  }

  my_mutex.unlock();

}

int main(){

  thread t1(threadFn, "supri");
  thread t2(threadFn, "joko");
  thread t3(threadFn, "amir");

  t1.join();
  t2.join();
  t3.join();


}
