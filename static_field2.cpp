#include <iostream>
 
using namespace std;

class Test1{
  public:
    Test1(){
      instance_id = ++total_instance;
      cout << "Instance ke " << instance_id << " is created" << endl;
    }

    ~Test1(){
      cout << "Instance ke " << instance_id << " is destroyed" << endl;
    }

  private:
    int instance_id;
    static int total_instance;
};

int Test1::total_instance=0; // initialization 

int main(void) {
   Test1 t1, t2, t3, t4[5];

   return 0;
}
