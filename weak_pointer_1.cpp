#include <iostream>
#include <memory>

using namespace std;

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

int main(){
  shared_ptr<Test1> t0(new Test1());
  unique_ptr<Test1> tx(new Test1());
  weak_ptr<Test1> t1(t0);
  weak_ptr<Test1> t2 = t0;
  //weak_ptr<Test1> t3(tx);//error
  //weak_ptr<Test1> t4 = tx;//eror
  shared_ptr<Test1> t5(new Test1[5], [](Test1* p){ delete [] p;});
  weak_ptr<Test1>  t6 = t5;
  weak_ptr<Test1> t7 = t6;

  //t2->say();// error
  t2.lock()->say();// ok

  t6.lock().get()[1].say();

  t7.lock()->say();

  return 0;
}
