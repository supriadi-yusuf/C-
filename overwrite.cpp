#include <iostream>

using namespace std;

class Induk{ 
  public:
  void hello(){
    cout << "hello from induk" << endl;
  }
};

class Anak : public Induk {
  private:
    typedef Induk super;

  public:
  void hello(){
    super::hello();
    Induk::hello();
    cout << "hello from anak" << endl;
  }  
};

int main(){
  //Anak anak;

  Anak *p = new Anak();

  p->hello();

  delete p;

  return 1;
}




