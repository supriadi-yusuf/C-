#include <iostream>
#include <memory>

using namespace std;

/****************************************************************************
compile : 
   g++ shared_pointer_2.cpp -o test -std=c++11
****************************************************************************/

class Test1{
  private:
    static int total_instance;
    int instance_no;

  public:
    Test1(){
      instance_no = ++total_instance;
      cout << "Instance Test ke : " << instance_no << " is created." << endl;
    }

    ~Test1(){
      cout << "Instance Test ke : " << instance_no << " is deleted." << endl;
    }

    static int getTotalInstances(){
      return total_instance;
    }
};

int Test1::total_instance = 0;// initialization of static member

Test1* getTest1(){
   return new Test1();
}

int main(){
  shared_ptr<Test1> t1(new Test1());
  shared_ptr<Test1> t2(getTest1()); 
  shared_ptr<Test1> t3(new Test1[3], [](Test1* t){delete [] t;});
  shared_ptr<Test1> t4, t5, t6, t7;

  cout << "create object for t4" << endl;
  t4 = (shared_ptr<Test1>) new Test1(); 

  cout << "reset t4" << endl;
  t4.reset(); // is t4 deleted?
  cout << "after t4 is reset" << endl;

  cout << "create object for t5" << endl;
  t5 = (shared_ptr<Test1>) new Test1();

  cout << "this object is owned by " << t5.use_count() << " pointer/s'." << endl;
  cout << "make t6 points to t5" << endl;
  t6 = t5; 
  cout << "this object is owned by " << t5.use_count() << " pointer/s'." << endl;

  cout << "reset t5" << endl;
  t5.reset(); // is t5 deleted?
  cout << "after resetting t5" << endl;

  cout << "Total instances : " << t1->getTotalInstances() << endl;

  return 0;
}
