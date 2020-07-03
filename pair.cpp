#include <iostream> 
#include <string>

using namespace std;

int main(){
  pair<string,int> p1("supri", 40);
  pair<string,int> p2 = make_pair("hasan", 30);

  cout << p1.first << " : " << p1.second << endl;
  cout << p2.first << " : " << p2.second << endl;

  p1.first = "ahmad";
  cout << p1.first << " : " << p1.second << endl;

  string& nama = p2.first;
  nama = "sobirin";
  cout << p2.first << " : " << p2.second << endl;

  return 0;
}
