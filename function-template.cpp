#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T const& maksimum( T const &a, T const &b){
  return a > b ? a : b;
}

int main( int argc, char **argv){
  int i=39, j=20;
  cout << "maksimum(" << i << "," << j << ")=" << maksimum(i,j) << endl;

  double f1=13.5, f2=20.7;
  cout << "maksimum(" << f1 << "," << f2 << ")=" << maksimum(f1,f2) << endl;

  string s1="hello", s2="world";
  cout << "maksimum(" << s1 << "," << s2 << ")=" << maksimum(s1,s2) << endl;

  const int &maxValue = maksimum(i,j);
  cout << "const int &maxValue = maksimum(i,j)" << endl;
  cout << "maxValue=" << maxValue << endl;

  cout << "i=" << i << endl;

  cout << "i=50" << endl;
  i=50;

  cout << "maxValue=" << maxValue << endl;

  //int &maxVal = maksimum(50,45);//error

  return 0;
}
