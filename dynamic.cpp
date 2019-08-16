#include <iostream>

using namespace std;

int main( int argc, char** argv){
   int *pInt, *pInt2;

   pInt = pInt2 = NULL;
 
   cout << "pInt = " << pInt << endl;
   cout << "pInt2 = " << pInt2 << endl;

   cout << endl << "allocate int" << endl << endl;

   pInt = new int;
   pInt2 = new int;

   cout << "pInt = " << pInt << endl;
   cout << "pInt2 = " << pInt2 << endl;

   *pInt = 5;
   *pInt2 = 20;

   cout << *pInt << endl;
   cout << *pInt2 << endl;

   cout << endl << "Release memory" << endl;

   delete pInt;
   delete pInt2;

   cout << "pInt = " << pInt << endl;
   cout << "pInt2 = " << pInt2 << endl;

   cout << endl << "alocate memory 5X" << endl;

   pInt = new int[5];
   pInt2 = new int[5];

   cout << "pInt = " << pInt << endl;
   cout << "pInt2 = " << pInt2 << endl;

   pInt[0]=pInt[1]=pInt[2]=pInt[3]=pInt[4]=10;
   pInt2[0]=pInt2[1]=pInt2[2]=pInt2[3]=pInt2[4]=15;

   cout << pInt[0] << pInt[1] << pInt[2] << pInt[3] << pInt[4] << endl;
   cout << pInt2[0] << pInt2[1] << pInt2[2] << pInt2[3] << pInt2[4] << endl; 

   cout << endl << "release memory" << endl;

   delete [] pInt;
   delete [] pInt2;

   cout << "pInt = " << pInt << endl;
   cout << "pInt2 = " << pInt2 << endl;  
   
}
