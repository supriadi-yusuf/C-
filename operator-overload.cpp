#include <iostream>

using namespace std;

class Balok {
  private:
    int panjang, lebar, tinggi;

  public:
    Balok( int pjg, int lbr, int tg);
    void setPanjang( int panjang);
    void setLebar( int lebar);
    void setTinggi( int tinggi);
    int getPanjang(void);
    int getLebar(void);
    int getTinggi(void);
    int getVolume(void);

    //overload operator
    void operator++(void);//overload prefix ++ operator
    void operator++(int);//overload suffix ++ operator
    Balok operator+( int inc);
    Balok operator+( const Balok &obj);//Balok3 = Balok1 + Balok2
    void operator=( const Balok &obj);
};

Balok::Balok( int pjg, int lbr, int tg): panjang(pjg), lebar(lbr), tinggi(tg){}

void Balok::setPanjang(int panjang){
  this->panjang = panjang;
}

void Balok::setLebar(int lebar){
  this->lebar = lebar;
}

void Balok::setTinggi(int tinggi){
  this->tinggi = tinggi;
}

int Balok::getPanjang(void){
  return panjang;
}

int Balok::getLebar(void){
  return lebar;
}

int Balok::getTinggi(void){
  return tinggi;
}

int Balok::getVolume(void){
  return panjang * lebar * tinggi;
}

void Balok::operator++(void){
  cout << "prefix operator ++ is executed" << endl;
  panjang++;
  lebar++;
  tinggi++;
}

void Balok::operator++(int){
  cout << "suffix operator ++ is executed" << endl;
  panjang++;
  lebar++;
  tinggi++;
}

Balok Balok::operator+(int inc){
  int pjg, lbr, tg;
  cout << "operator + (int) is executed" << endl;

  pjg = panjang + inc;
  lbr = lebar + inc;
  tg = tinggi + inc;

  return Balok(pjg,lbr,tg);
}

Balok Balok::operator+(const Balok &obj){
   Balok balok( 0, 0, 0);

   cout << "operator + (const Balok &) is executed" << endl;

   balok.panjang = panjang + obj.panjang;
   balok.lebar = lebar + obj.lebar;
   balok.tinggi = tinggi + obj.tinggi;

   return balok;
}

void Balok::operator=(const Balok &obj){
  cout << "operator = (const Balok &) is executed" << endl;

  panjang = obj.panjang;
  lebar = obj.lebar;
  tinggi = obj.tinggi;
}

int main( int argc, char** argv){
  Balok balok1(3,4,5);
  Balok balok2(10,20,30);
  Balok balok3(15,25,35);

  cout << "balok1" << endl;
  cout << "panjang : " << balok1.getPanjang() << endl;
  cout << "lebar : " << balok1.getLebar() << endl;
  cout << "tinggi : " << balok1.getTinggi() << endl << endl;

  cout << "balok2" << endl;
  cout << "panjang : " << balok2.getPanjang() << endl;
  cout << "lebar : " << balok2.getLebar() << endl;
  cout << "tinggi : " << balok2.getTinggi() << endl << endl;

  cout << "balok3" << endl;
  cout << "panjang : " << balok3.getPanjang() << endl;
  cout << "lebar : " << balok3.getLebar() << endl;
  cout << "tinggi : " << balok3.getTinggi() << endl << endl;

  cout << "balok1++" << endl << endl;

  balok1++;

  cout << endl;

  cout << "balok1" << endl;
  cout << "panjang : " << balok1.getPanjang() << endl;
  cout << "lebar : " << balok1.getLebar() << endl;
  cout << "tinggi : " << balok1.getTinggi() << endl << endl;

  cout << "++balok1" << endl << endl;

  ++balok1;

  cout << endl;

  cout << "balok1" << endl;
  cout << "panjang : " << balok1.getPanjang() << endl;
  cout << "lebar : " << balok1.getLebar() << endl;
  cout << "tinggi : " << balok1.getTinggi() << endl << endl;

  cout << "balok3 = balok1 + balok2" << endl << endl;

  balok3 = balok1 + balok2;

  cout << endl;

  cout << "balok3" << endl;
  cout << "panjang : " << balok3.getPanjang() << endl;
  cout << "lebar : " << balok3.getLebar() << endl;
  cout << "tinggi : " << balok3.getTinggi() << endl << endl;
 
  cout << "balok2 = balok1 + 5" << endl << endl;

  balok2 = balok1 + 5;

  cout << "balok2" << endl;
  cout << "panjang : " << balok2.getPanjang() << endl;
  cout << "lebar : " << balok2.getLebar() << endl;
  cout << "tinggi : " << balok2.getTinggi() << endl << endl;

  
  return 0;
}
