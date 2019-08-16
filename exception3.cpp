#include <iostream>
#include <exception>

using namespace std;

struct MyException:public exception{
  private:
     char* msg;

  public:
    MyException(char* msg){
      this->msg=msg;
    }

    const char* what() const throw(){
      return msg;
    }
};

int main( int argc, char** argv){
  try{
     throw MyException((char*)"C++ exception");
     //throw exception();
  }catch(MyException& e){
     cout << "MyException caught - 3" << endl;
     cout << e.what() << endl;
  }catch(exception& e){
     cout << e.what() << endl;
  }

  return 0;
}
