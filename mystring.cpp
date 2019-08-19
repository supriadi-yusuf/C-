#include <iostream>
#include <string>
#include <cstring> //to call strcpy

using namespace std;

int main(int argc, char* argv[]){
  char buffer[256];
  string str_nama = "supriadi yusuf";
  char c_nama[] = "Abdullah Muhammad";

  //convert string to char
  strcpy( buffer, str_nama.c_str());

  cout << buffer << endl;  

  //convert array of char to string
  str_nama = c_nama;

  cout << str_nama << endl;
  
  return 0;
}
