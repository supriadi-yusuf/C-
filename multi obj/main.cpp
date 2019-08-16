#include <iostream>
#include "kendaraan.h"
#include "pesawat.h"

using namespace std;

int main( int argc, char** argv){
   Kendaraan kendaraan;
   Pesawat pesawat;
   Kendaraan *kendaraan2 = &pesawat;

   kendaraan.bergerak();
   pesawat.bergerak();
   kendaraan2->bergerak();
}
