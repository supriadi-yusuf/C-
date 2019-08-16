#include <iostream>
#include <string>

using namespace std;

class Objek{

  public:
    Objek(void);
    void setInt(int i);
    string getStatus(void);
    int getInt(void);
    Objek( const Objek &obj);//copy constructor
    ~Objek(void);

  private:
    string status;
    int *pInt;

};

Objek::Objek(void){
  pInt = new int;
  *pInt = 10;
  status = "original";
  cout << "constructor is executed" << endl;
}

void Objek::setInt(int i){
  *pInt = i;
}

string Objek::getStatus(void){
  return status;
}

int Objek::getInt(void){
  return *pInt;
}

Objek::Objek(const Objek &obj){
  status = "cloning";
  pInt = new int;
  *pInt = *obj.pInt;
  cout << "copy constructor is executed" << endl;
}

Objek::~Objek(void){
  cout << "Destructor is called" << endl;
  delete pInt;
}

int main(int argc, char** argv){
  Objek obj1;
  Objek obj2 = obj1;//copy constructor is called
  Objek *obj3 = new Objek;

  cout << "status obj1 : " << obj1.getStatus() << endl;
  cout << "status obj2 : " << obj2.getStatus() << endl;
  cout << "status *obj3 : " << obj3->getStatus() << endl;
  
  obj1.setInt(10);
  obj2.setInt(20);
  obj3->setInt(30);

  cout << "obj1 int : " << obj1.getInt() << endl;
  cout << "obj2 int : " << obj2.getInt() << endl;
  cout << "*obj3 int : " << obj3->getInt() << endl;

  cout << "*obj3 = obj1" << endl;

  *obj3 = obj1;//copy constructor is not called

  cout << "status obj1 : " << obj1.getStatus() << endl;
  cout << "status *obj3 : " << obj3->getStatus() << endl;

  cout << "obj1 int : " << obj1.getInt() << endl;
  cout << "*obj3 int : " << obj3->getInt() << endl;
  
  delete obj3;
}

