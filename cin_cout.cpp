#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){
  //char buffer[256];
  string buffer;
  cout << "Enter Name : "; 
  //cin >> buffer; 
  getline(cin,buffer);
  cout << "Your name is " << buffer << endl;
  cout << "Your name has " << buffer.length() << " characters." << endl;
  cout << "Your name has " << buffer.size() << " characters." << endl;
  cout << "Your name has " << sizeof(buffer) << " characters." << endl;
  cout << "Your name is " << buffer << endl;
  return 0;
}
