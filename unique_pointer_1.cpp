#include <iostream>
#include <memory>

using namespace std;

/****************************************************************************
unique pointer is exclusive ownership means an object belongs to a pointer only.

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

Test1* getTest1(){
   return new Test1();
}

unique_ptr<Test1> getTest1x(){
   unique_ptr<Test1> p(new Test1());

   return p;
}

unique_ptr<Test1[]> getManyTest1(int x){
  unique_ptr<Test1[]> p(new Test1[x]);
  
  return p;
}


int main(){
  unique_ptr<Test1> t1(new Test1());
  unique_ptr<Test1> t2(getTest1());

  // create array of object
  //unique_ptr<Test1> t3(new Test1[3]);// error on running
  //unique_ptr<Test1> t3(new Test1[3], [](Test1* t){delete [] t;}); // error on compiling
  unique_ptr<Test1[]> t3(new Test1[3]);// ok
  //unique_ptr<Test1[]> t3(new Test1[3], [](Test1* t){delete [] t;}); // error on compiling

  unique_ptr<Test1> t4, t5;
  
  unique_ptr<Test1> t6 = getTest1x();
  unique_ptr<Test1> t7(getTest1x());

  t1->greeting(); 
  cout << "Total instances : " << t1->getTotalInstances() << endl;

  t3.get()[1].greeting();

  t4 = move(t1); //ownership transfer. now object belongs to t4
  t4->greeting();

  t1 = move(t2); //ownership transfer. now object belongs to t1. previous t1 object is destroyed.
  t1->greeting();

  unique_ptr<Test1> t8 = move(getTest1x());

  t8->greeting();

  unique_ptr<Test1[]> t9 = move(getManyTest1(5));

  unique_ptr<Test1> t10 (new Test1());

  cout << "call reset() method" << endl;

  t10.reset();

  cout << "finish program" << endl;

  unique_ptr<Test1> t11 = (unique_ptr<Test1>) new Test1();

  return 0;
}
