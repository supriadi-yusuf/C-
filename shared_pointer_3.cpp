#include <iostream>
#include <memory>

using namespace std;

/****************************************************************************
compile : 
   g++ shared_pointer_3.cpp -o test -std=c++11
****************************************************************************/

class Test1{
  private:
    int instance_no = 10;// non static member can be initialized here. the value is only random.
    //static int total_instance = 0; // error, static member can not be initialized here.
    static int total_instance; // static member can be initialized outside instead.

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

    void greeting(string say="hello apa kabar?"){
      cout << "instance ke " << instance_no << " : " << say << endl;
    }
};

int Test1::total_instance = 0;// initialization of static member
//int Test1::instance_no = 10;// error, non-static member can not be initialized outside of class

Test1* getTest1(){ // compile and running ... ok. 
   return new Test1();
}

shared_ptr<Test1> getTest1x(){
   shared_ptr<Test1> p(new Test1());

   return p;
}

int main(){
  shared_ptr<Test1> t1(new Test1());
  shared_ptr<Test1> t2(getTest1()); 

  // create array of object
  //shared_ptr<Test1> t3(new Test1[3]);//error when running
  shared_ptr<Test1> t3(new Test1[3], [](Test1* t){delete [] t;}); // correct for objects array of shared pointer

  shared_ptr<Test1> t4, t5;
  shared_ptr<Test1> t6=getTest1x();//ok
  shared_ptr<Test1> t7(getTest1x());//ok

  t1->greeting();

  t4 = t5 = t2;  
  cout << "this object is owned by " << t4.use_count() << " pointers" << endl; 
  t4->greeting();

  cout << "Total instances : " << t1->getTotalInstances() << endl;

  return 0;
}
