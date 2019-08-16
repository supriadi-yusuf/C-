#include <iostream>
#include <exception>

using namespace std;

struct MyException:public exception {
  const char* what() const throw(){
     return "C++ Exception";
  }
};

int main( int argc, char** argv){
  try{
    throw MyException(); 
    //throw exception();
  }catch(MyException& e){
    cout << "MyException caught - 2" << endl;
    cout << e.what() << endl;
  }catch(exception& e){
    cout << e.what() << endl;
  }

  return 0;
}


