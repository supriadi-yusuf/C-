#include <iostream>

using namespace std;
/******************************************************************** 
 1. const <type> and <type> const are same :
    const int c = 10; //const <type>
    int const d = 20; //<type> const

 2. array is constant pointer
    int a[10]; // a is constant pointer for integer values
    int* & b = a; // error because b is reference to pointer not constant pointer
    int* const & c = a; // correct because c is reference to constant pointer for integer value

 3. we can create array of constant value
    const int a[] = {1,2,3}; a is constant pointer to constant integer value
    a[0] = 10; // error, the value can not be changed because it is constant

 4. constant pointer
    int a = 10;
    int b = 11;
    int * const c = &a; // c is constant pointer to a
    c = & b; //error because c is constant pointer so it cannot point to others
    *c = 10; //correct, c is constant pointer but it doesn't point to constant value.

 5. pointer for constant value
    const int a = 10;
    const int b = 11;
    const int * c = &a; // c is pointer to constant integer value
    *c = 100; //error because c is pointer to constant value so it can not change the value it points to
    c = &b; //correct because c is not constant pointer so it can point to anything
    int d = 20;
    const int * e = &d; //correct, pointer for constant value is allowed to point non constant value
    *e = 1000; //error, the value can not be changed via this pointer because this pointer is for constant value.

 6. constant pointer for constant value
    int a = 10;
    int b = 11;
    const int * const c = &a;// a is constant pointer pointing to constant value
    *c = 200; // error, c is pointer pointing to constant value
    c = &b; // error, c is constant pointer 
  
********************************************************************/
void proc1(const int a, int const b);

int main(void){

  int a = 10; 
  int& a_ = a;
  const int & a__ = a;  
  int const & a___ = a;
  
  const int b = 100;
  //int& b_ = b; // error
  const int& b__ = b;
  int const& b___ = b;

  int const c = 200;
  //int& c_ = c; // error
  const int& c__ = c;
  int const& c___ = c;

  int d[] = {1,2,3}; // d is contant pointer to integer value
  int* const & d_ = d; 

  const int * const e = &a;
  int const * const ee = &a;
  //const int*& e_ = e;

  const int f = 10;
  //int & f_ = f; // error
  const int & f_ = f;
  //int * f__ = &f; // error
  const int * f__ = &f;
  
  a = 11;
  a_ = 12; 
  //a__ = 13; // error
  //a___ = 14;  // error 

  cout << "a adalah " << a << endl;
  cout << "b adalah " << b << endl;
  cout << "d = {" << d[0] << ", " << d[1] << ", " << d[2] << "}" << endl;

  proc1( a, b);

  return 0;
}

void proc1(const int a, int const b){
  cout << a << " ," << b << endl;
}
