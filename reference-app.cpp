#include <iostream>

using namespace std;

int main(int argc, char **argv){
  int i;
  int j;
  const int k = 5;
  const int l = 6;

  int &a=i;
  //int &b=k;//wrong, k is constant so b must be constant too
  const int &b=k;
  const int &c=i;//c is constant but i is not. it is ok. i can be modified but c.
  int const &d=j;

  a=j;
  a=k;

  //b=i;//error
  //b=j;//error
  //b=l;//error

  //c=i;//error

  //d=4;//error

  return 0;
}
