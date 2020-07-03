#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const char* get_name(){
  char name[100];
  string my_name;
  strcpy(name, "wijaya adhisurya");

  my_name = name;

  //return name;
  return my_name.c_str();
  //return (char *) name;
}

int main(){
  //char* name = get_name();
  cout << "hello" << endl;
  cout << ((char*) get_name()) << endl;
  //cout << name << endl;
}
