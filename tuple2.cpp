#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

tuple<string,int> get_name_age(){
  return make_tuple("supriadi", 40);
}

int main(){
  string name;
  int age;

  // transfer data
  tie(name, age) = get_name_age();

  cout << name << endl;
  cout << age << endl;

  tuple<int, int, int> t1, t2; // hour, minute, second
  
  t1 = tuple<int, int, int>(9,20,40);
  t2 = make_tuple( 12, 0, 5);

  // comparison two tuples
  if( t1 < t2 )
     cout << "t2 is later than t1" << endl;
  else
     cout << "t2 is not later than t1" << endl;     

  // multiple index map 
  map<tuple<int, char, float>, string> m;

  m[make_tuple( 0, 'a', 1.5)] = "Faith will move montain";

  cout << m[make_tuple( 0, 'a', 1.5)] << endl;

  string s1="supri", s2="yuyun", s3="herawati", s4="mulianto";

  cout << endl;
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  cout << s4 << endl;

  //swap value
  tie(s2,s1,s4,s3) = make_tuple(s1,s2,s3,s4);
  
  cout << endl;
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  cout << s4 << endl; 
  
  return 1;
}
