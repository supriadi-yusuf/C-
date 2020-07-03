#include <iostream>
#include <string>

/*******************************************************
compile :
   g++ oop-2.cpp -o test -std=c++11
*******************************************************/

using namespace std;

class MyObject{
  public:
    MyObject(string nama, int umur){
      _id = ++_sequence;
      _nama = nama;
      _umur = umur;

      cout << "Object " << _id << " is created." << endl;
    }

    ~MyObject(){
      cout << "Object " << _id << " is deleted." << endl;
    }

  private:
    int _id, _umur;
    string _nama;
    static int _sequence;
};

int MyObject::_sequence = 0;

int main(){
  MyObject supri("supri",41);
  MyObject pelajar1{"irma", 10};
  MyObject pelajar2 = {"yuyu", 10};
  MyObject pelajar3[2] = {{"irma", 30},{"uda",20}};
  MyObject penduduk[2] = {MyObject("kikan",44),MyObject("hasan",30)}; 
  MyObject* mahasiswa = new MyObject[2]{{"eko",20},{"iwan",22}}; 

  delete [] mahasiswa;

  return 0;
}
