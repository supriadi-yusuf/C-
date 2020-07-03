#include <iostream>

using namespace std;

class Induk1{
  private:
    char* name;

  public:
    Induk1(char* myname){
      name = myname;
      cout << "Constructor kelas Induk1 " << name << endl;
    }

    ~Induk1(){
      cout << "Destructor kelas Induk1 " << name << endl;
    }
};

class Induk2{
  private:
    char *name;

  public:
    Induk2(char* myname){
      name = myname;
      cout << "Constructor kelas Induk2 " << name << endl;
    }

    ~Induk2(){
      cout << "Destructor kelas Induk2 " << name << endl;
    }
};

class Anak : public Induk1, public Induk2{
  public:
    Anak(char* induk1, char* induk2) : Induk1(induk1), Induk2(induk2){  
      cout << "Constructor kelas Anak" << endl;
    }
    ~Anak(){
      cout << "Destructor kelas Anak" << endl;
    }   
};

int main(){
  //Anak anak;

  Anak *p = new Anak( const_cast<char*> ("induk1"), const_cast<char*> ("induk2"));

  delete p;

  return 1;
}




