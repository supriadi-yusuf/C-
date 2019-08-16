#include <iostream>
//#include <string>

using namespace std;

class Permutasi {
  private:
    int jmlElemen;
    int jmlSusunan;
    int *susunan=NULL;
    bool findInSusunan( int posisi, int obj);
    void displaySusunan(void);  
    void aksi(int posisi);

  public:
    Permutasi(void);
    void setJmlElemen(int jumlahElemen);
    void setJmlSusunan(int jumlahSusunan);
    void doPermutasi(void);
    ~Permutasi();
};

Permutasi::Permutasi(void){
  //cout << "Constructor dieksekusi" << endl;
}

bool Permutasi::findInSusunan( int posisi, int obj){
  int index = posisi - 1;
  while(index){//pencarian mundurr
    if(susunan[index-1] == obj)
        return true;

    index--;    
  }

  return false;
}

void Permutasi::displaySusunan(void){
  for( int i=0; i<jmlSusunan; i++){
    cout << susunan[i] << ".";
  }

  cout << endl;
}

void Permutasi::aksi(int posisi){
  int obj;

  for( obj=1; obj<=jmlElemen; obj++){
     if( findInSusunan( posisi, obj))
        continue;

     susunan[posisi-1] = obj;

     if(posisi != jmlSusunan)
       aksi(posisi+1);
     else
       displaySusunan();
  }

}

void Permutasi::setJmlElemen(int jumlahElemen){
  jmlElemen = jumlahElemen;  
}

void Permutasi::setJmlSusunan(int jumlahSusunan){
  jmlSusunan = jumlahSusunan;
}

void Permutasi::doPermutasi(void){
  if(jmlElemen < jmlSusunan){
     cout << "jumlah elemen hrs lebih besar atau sama dg jml susunan" << endl;
     return;
  }

  if( susunan != NULL ){
     delete [] susunan;
     susunan = NULL;
  }

  susunan = new int[jmlSusunan];

  aksi(1);


}

Permutasi::~Permutasi(void){
  if( susunan != NULL)
     delete [] susunan;

  //cout << "Destructor dieksekusi" << endl;
}

int main(int argc, char** argv){
  Permutasi permutasi;

  permutasi.setJmlElemen(10);
  permutasi.setJmlSusunan(5);
  permutasi.doPermutasi();

  return 0;
}
