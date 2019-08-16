#include <iostream>

using namespace std;

int bagi( int angka, int pembagi){
   if( pembagi == 0){
       throw "Pembagi tidak boleh nol!"; 
   }

   return angka/pembagi;
}

int main( int argc, char** argv){
  int angka, pembagi;

  cout << "Angka : "; cin >> angka;
  cout << "Pembagi : "; cin >> pembagi;
  try{
    cout << bagi(angka, pembagi) << endl;
  }catch( const char* msg){
    cout << msg << endl;
  }
   
}
