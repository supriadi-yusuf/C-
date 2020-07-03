#include <iostream>
#include <memory>

using namespace std;

/****************************************************************************
compile : 
   g++ shared_pointer_1.cpp -o test -std=c++11
****************************************************************************/

class Test1{
  private:
    int instance_no; 
       
    static int createInstance(){
      static int loc_instance_no = 0; //x1=0; // how to access static field??
      return ++loc_instance_no; 
    }

  public:
    Test1(){
      instance_no = createInstance();
      cout << "Instance Test ke : " << instance_no << " is created." << endl;
    }

    ~Test1(){
      cout << "Instance Test ke : " << instance_no << " is deleted." << endl;
    }

    void say(){
      cout << "Instance -" << instance_no << " : hello apa kabar?" << endl;
    }
};

Test1* getTest1(){
   return new Test1();
}

shared_ptr<Test1> getManyTest(int x){
  shared_ptr<Test1> p(new Test1[x], [](Test1* t){delete [] t;});

  return p;
}

int main(){
  shared_ptr<Test1> t1(new Test1());
  shared_ptr<Test1> t2(getTest1()); 
  shared_ptr<Test1> t3(new Test1[10], [](Test1* t){delete [] t;});
  shared_ptr<Test1> t4 = getManyTest(5);
  shared_ptr<Test1> t5 = (shared_ptr<Test1>) new Test1();  
  
  t1.get()->say(); // t1.get() returns pointer to Test1 object type
  t1.get()[0].say(); // we can also use this form  
  t1->say(); // or we can simply use this form. "->" is operator

  (t3.get() + 3 )->say(); 
  t3.get()[3].say(); 

  //cout << __LINE__ << endl; 
  //cout << __FILE__ << endl;

  shared_ptr<Test1> t6;
  t6 = make_shared<Test1>(/* parameters */);

  return 0;
}
