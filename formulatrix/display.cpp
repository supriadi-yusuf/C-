#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char **argv){
  char c[] = "00";

  cout << c << endl;

  c[0]=1;c[1]=2;
  cout << c << endl; 
  
  return 0;
}



