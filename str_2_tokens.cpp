/***********************************************************************************
split string into tokens with strtok( string, delimiter) function.
************************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
  char kal[]="I am a farmer. I have cat, dog, sheep, etc.";
  char* ptoken;

  cout << "kal : " << kal << endl;
  //cout << "ptoken : " << ptoken << endl;

  ptoken = strtok( kal, " ,.-");// split string based on one of character in delimeter. strtok(string, delimeter).
  while( ptoken != NULL ){
    cout << "kal : " << kal << endl;
    cout << "ptoken : " << ptoken << endl;

    ptoken = strtok( NULL, " ,.-");
  }


  return 0;
}
