#include <iostream>

using namespace std;

class Induk1{
  public:
    Induk1(){
      cout << "Constructor kelas Induk1" << endl;
    }

    ~Induk1(){
      cout << "Destructor kelas Induk1" << endl;
    }
};

class Induk2{
  public:
    Induk2(){
      cout << "Constructor kelas Induk2" << endl;
    }

    ~Induk2(){
      cout << "Destructor kelas Induk2" << endl;
    }
};

class Anak : public Induk1, public Induk2{
  public:
    Anak(){
      //Induk1::Induk1(); // error
      cout << "Constructor kelas Anak" << endl;
    }
    ~Anak(){
      cout << "Destructor kelas Anak" << endl;
    }   
};

int main(){
  //Anak anak;

  Anak *p = new Anak();

  delete p;

  return 1;
}




