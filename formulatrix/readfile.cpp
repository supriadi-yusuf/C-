#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char **argv){
  char c;

  if( argc < 2 ) return 1;

  ifstream ifile(argv[1]);

  if( !ifile)
     return 2;

  while(true){
    ifile >> c;
    if( ifile.eof() )
       return 3;

    cout << c << endl;
    //cout << c << "::" << (int)1000 << endl;
  }

  ifile.close();

  return 0;
}



