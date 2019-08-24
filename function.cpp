#include <iostream>

using namespace std;

void test(int a=1, int b=2, int c=3){
  cout << "params : " << a << ", " << b << ", " << c << endl;
}

//void test(int a, int b, int c){
//  cout << "params : " << a << ", " << b << ", " << c << endl;
//}

int main(int argc, char* argv[]){
  test(1,2,3);
  test(1,2);
  test(1);
  test();
  //test(b=10,a=1,c=3);//error
  return 0;
}
