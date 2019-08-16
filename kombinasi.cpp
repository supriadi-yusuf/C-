#include <iostream>
//#include <string>

using namespace std;

class Kombinasi {
  private:
    int jmlElemen;
    int jmlSusunan;
    int *susunan=NULL;
    //bool findInSusunan( int posisi, int obj);
    void displaySusunan(void);  
    void aksi(int posisi, int initVal);

  public:
    Kombinasi(void);
    void setJmlElemen(int jumlahElemen);
    void setJmlSusunan(int jumlahSusunan);
    void doKombinasi(void);
    ~Kombinasi();
};

Kombinasi::Kombinasi(void){
  //cout << "Constructor dieksekusi" << endl;
}

//bool Kombinasi::findInSusunan( int posisi, int obj){
//  int index = posisi - 1;
//  while(index){//pencarian mundurr
//    if(susunan[index-1] == obj)
//        return true;
//
//    index--;    
//  }
//
//  return false;
//}

void Kombinasi::displaySusunan(void){
  for( int i=0; i<jmlSusunan; i++){
    cout << susunan[i] << ".";
  }

  cout << endl;
}

void Kombinasi::aksi(int posisi, int initVal){
  int obj;
  int limit = jmlElemen - jmlSusunan + posisi;

  for( obj=initVal; obj<=limit; obj++){
     //if( findInSusunan( posisi, obj))
     //   continue;

     susunan[posisi-1] = obj;

     if(posisi != jmlSusunan)
       aksi(posisi+1, obj+1);
     else
       displaySusunan();
  }

}

void Kombinasi::setJmlElemen(int jumlahElemen){
  jmlElemen = jumlahElemen;  
}

void Kombinasi::setJmlSusunan(int jumlahSusunan){
  jmlSusunan = jumlahSusunan;
}

void Kombinasi::doKombinasi(void){
  if(jmlElemen < jmlSusunan){
     cout << "jumlah elemen hrs lebih besar atau sama dg jml susunan" << endl;
     return;
  }

  if( susunan != NULL ){
     delete [] susunan;
     susunan = NULL;
  }

  susunan = new int[jmlSusunan];

  aksi(1,1);


}

Kombinasi::~Kombinasi(void){
  if( susunan != NULL)
     delete [] susunan;

  //cout << "Destructor dieksekusi" << endl;
}

int main(int argc, char** argv){
  Kombinasi kombinasi;

  kombinasi.setJmlElemen(10);
  kombinasi.setJmlSusunan(5);
  kombinasi.doKombinasi();

  return 0;
}
