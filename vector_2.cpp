#include <iostream>
#include <vector>

using namespace std;

/***************************************************************
compile :
  g++ vector_2.cpp -o test -std=c++11
***************************************************************/

void get_param(vector<int> v = {}){
  cout << "size : " << v.size() << endl;
}

int main(){
  get_param({1,2,3,4});
  get_param();
  return 0;
}
