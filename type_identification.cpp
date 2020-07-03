#include <typeinfo>
#include <iostream>

using namespace std;

int main(){
  int a = 10;
  char b;
  float c;
  double d;
  int* p = reinterpret_cast<int*> (&a);

  cout << "a = " << a << endl;
  cout << "p = " << p << endl;
  cout << "*p = " << (*p) << endl;

  cout << typeid(a).name() << endl;
  cout << typeid(b).name() << endl;
  cout << typeid(c).name() << endl;
  cout << typeid(d).name() << endl;
  cout << typeid(p).name() << endl;
  cout << typeid(*p).name() << endl;

  return 1;
}
