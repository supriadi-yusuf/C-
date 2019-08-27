#include <iostream> 

using namespace std;

int tambah(int a, int b){
  return a + b;
}


int kurang(int a, int b){
  return a - b;
}


int kali(int a, int b){
  return a * b;
}


int xor_opt(int a, int b){
  return a ^ b;
}

int main(){
  int (*func1)(int,int);

  func1 = tambah;

  int (* func2)(int,int) = kurang;
  int (* const func3)(int,int) = kali;
  int (& func4)(int,int) = xor_opt;

  cout << " 3 + 2 = " << (*func1)(3,2) << endl;
  cout << " 3 - 2 = " << (*func2)(3,2) << endl;
  cout << " 3 * 2 = " << (*func3)(3,2) << endl;
  cout << " 3 ^ 2 = " << (*func4)(3,2) << endl;
 
  return 0;
}
