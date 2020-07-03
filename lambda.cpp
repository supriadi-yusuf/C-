#include <iostream>
/****************************************************************
lambda is anynomous fuction. 
Format :
1. [scope](parameter)->return_type{body} 
2. [scope](parameter){body} 

scope specifies local variables those can be accessed by lambda function.
& means local variable is accessed by reference
= means local variable is accessed by value


compile : g++ lambda.cpp -o lambda -std=c++11
****************************************************************/

using namespace std;

template <typename T> 
void tukar(T& x, T& y){
  T tmp = x;
  x = y;
  y = tmp;
}

int main(){
  
  int (* tambah)(int, int) = [](int x, int y)->int{ return x + y;};
  int (* tambah_x)(int, int) = [](int x, int y){ return x + y;};
  int (* kali)(int,int);

  kali = [](int a, int b){return a * b;};

  cout << "5 + 10 = " << tambah(5,10) << endl;
  cout << "5 + 10 = " << tambah_x(5,10) << endl;
  cout << "5 * 10 = " << kali(5,10) << endl;

  int x=10;
  int y=5;

  cout << "x is " << x << endl;
  cout << "y is " << y << endl;

  tukar( x, y);

  cout << "x is " << x << endl;
  cout << "y is " << y << endl; 

}
