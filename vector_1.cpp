#include <iostream>
#include <vector>
#include <algorithm> // header for : count, remove, find

/******************************************************************
compile :
    g++ vector.cpp -o test -std=c++11
******************************************************************/

using namespace std;

template<class T>
void print( T v, string msg){
  cout << msg << " { ";
  for( typename T::iterator it = v.begin(); it != v.end(); it++) cout << *it << ", ";
  cout << " }" << endl;  
}

int main(){
  vector<int> v = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,15,16,17,18,19,20,0,0,0,0,0,0,0,0,0,30,40,50};

  print(v, "awal : ");
  
  int index;

  // find 10 in vector
  vector<int>::iterator pos = find(v.begin(), v.end(), 10);
  if( pos == v.end() )
     cout << "Not found" << endl;
  else{
     index = distance( v.begin(), pos);
     cout << "found " << *pos << " at position " << index << endl;
  }

  // count 0 in vector
  int jml = count(v.begin(), v.end(), 0);
  cout << jml << " buah angka 0 telah ditemukan" << endl;

  cout << "erase 5th element" << endl;

  // delete 5th element
  v.erase( v.begin() + 4);

  print(v, "after 5th element is erased : ");

  cout << "erase 10th to 15th element" << endl;

  // delete 10th to 15th element
  v.erase( v.begin() + 9, v.begin() + 14);

  print(v, "after 10th to 15th element are erased : ");

  cout << "Remove 0 value from vector" << endl;

  // remove 0 from vector
  vector<int>::iterator removed = remove( v.begin(), v.end(), 0);
  v.erase( removed, v.end());

  print(v, "after 0 value is removed");

  cout << "vector size : " << v.size() << endl;
  cout << "vector capacity : " << v.capacity() << endl;

  cout << "call shrink_to_fit() method" << endl;

  v.shrink_to_fit();

  cout << "vector size now : " << v.size() << endl;
  cout << "vector capacity now : " << v.capacity() << endl;
  
  return 0;
}
