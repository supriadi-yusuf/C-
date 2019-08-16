#include <iostream>

using namespace std;

int a = 10;
void* b = (void *) &a;
int* c =(int*) b;

int main(void){
  cout << "hai" << endl;
  cout << &a << endl;
  cout << b << endl;
  cout << a << endl;
  cout << *c << endl;
  return 0;
}
