#include <iostream>

using namespace std;

class Array1{
  private:
    char a[10];
  public:
    Array1(void);
    char &operator[](int idx);
    int get(int idx);
    friend ostream &operator<<( ostream &output, const Array1 &arr);
    friend istream &operator>>( istream &input, Array1 &arr);
};

Array1::Array1(void){
  register int i;
  for( i=0; i<10; i++){
       a[i]= '0' + i;
       //cout << (int)a[i] << endl;
  }
}

char &Array1::operator[](int idx){

  cout << "overload operator []" << endl;

  if( idx <=0 )
     return a[0];

  if( idx >= 10 )
     return a[0];

  return a[idx];
}

int Array1::get(int idx){
  if( idx <=0 )
     return a[0];

  if( idx >= 10 )
     return a[0];

  return a[idx];
}

ostream &operator<<( ostream &output, const Array1 &arr){
  output << "Array1 contains :" << endl;

  for( int i=0; i<10; i++){
    output << arr.a[i] << endl;
  }

  return output;
}

istream &operator>>( istream &input, Array1 &arr){
  for( int i=0; i<10; i++){
    cout << "isi element ke-" << i << " : ";
    input >> arr.a[i];
  }
}

int main( int argc, char** argv){
   Array1 arr;

   cout << arr;

   cin >> arr;

   cout << arr;

   //cout << arr.get(5) << endl;
   cout << arr[5] << endl;
   arr[5] = 'z';
   //cout << arr.get(5) << endl;
   cout << arr[5] << endl;
   

}




