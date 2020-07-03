#include <iostream>
 
using namespace std;

class Test1{
  public:
    static int total_instance;

    Test1(){
      total_instance++;
      cout << "Instance ke " << total_instance << " is created" << endl;
    }

    ~Test1(){
      cout << "Instance ke " << total_instance << " is destroyed" << endl;
    }

};

// static field must be initiated first before it is used
//Test1::total_instance = 0; // error, type data type must be mentioned
int Test1::total_instance = 0; // correct

int main(void) {
   // initiation must be outside main() function
   //Test1::total_instance = 0; // error
   //int Test1::total_instance = 0; // error also
   Test1 t1, t2, t3, t4[5];

   return 0;
}
