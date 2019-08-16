#include <iostream>

using namespace std;

class One{
  private:
    int count;

  public:
    void setCount(int count){
      this->count = count;
    }

    friend int getCount(One one);
    friend class Two;
};

int getCount(One one){ //friend function of class One
  return one.count;
}

class Two{
  public:
    int getCount(One one);
};

int Two::getCount(One one){
   return one.count;
}

int main( int argc, char** argv){
   One c1;
   Two c2;

   c1.setCount(15);
   
   cout << getCount(c1) << endl;
   cout << c2.getCount(c1) << endl; 
}
