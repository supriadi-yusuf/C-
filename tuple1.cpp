#include <iostream>
#include <string>
#include <tuple>
#include <thread> // header for ref()
#include <typeinfo>

using namespace std;

int main(){
  tuple<string, int, string> penduduk("supri",40,"jakarta");
  tuple<string, char, string, int> mahasiswa("yudi", 'A', "ilmu komunikasi", 2000);
  tuple<int, string, string> t1,t2;

  t1 = tuple<int, string, string>(1,"supriadi","tanjung pandan");
  t2 = make_tuple(2, "herman abdullah", "bandung");

  cout << get<0>(t1) << endl;//index is compile time constant
  cout << get<1>(t1) << endl;
  cout << get<2>(t1) << endl;

  string& nama = get<1>(t1);
  nama = "jajang kurnia";

  cout << endl;
  cout << get<0>(t1) << endl;
  cout << get<1>(t1) << endl;
  cout << get<2>(t1) << endl;

  if( t1 < t2){ //lexico graphical comparison
     cout << endl << "t2 larger than t1" << endl;
     t1 = t2; // member by member copy
  }

  // tuple can store reference
  string title = "Ujung kuku";
  tuple<string&> t3(title);
  t3 = make_tuple(ref(title));//we can also use this

  cout << endl;
  cout << title << endl;
  get<0>(t3) = "Bukan orang biasa";
  cout << title << endl;

  int _no;
  string _nama, _kota;

  make_tuple(ref(_no), ref(_nama), ref(_kota)) = t1;
  cout << endl;
  cout << _no << endl;//2
  cout << _nama << endl;//herman abdullah
  cout << _kota << endl;//bandung

  tie(_no, _nama, _kota) = t1;// do same thing with : make_tuple(ref(_no), ref(_nama), ref(_kota)) = t1;
  cout << endl;
  cout << _no << endl;//2
  cout << _nama << endl;//herman abdullah
  cout << _kota << endl;//bandung

  int _no2;
  string _nama2, _kota2;

  tie(_no2, ignore, _kota2) = t1;

  cout << endl;
  cout << _no2 << endl;//2
  cout << _nama2 << endl;//empty{}
  cout << _kota2 << endl;//bandung

  // tuple concatenation
  auto t4 = tuple_cat( t2, t3);// t4 is tuple<int, string, string,string&>
  
  cout << endl;
  cout << get<0>(t4) << endl;
  cout << get<1>(t4) << endl;
  cout << get<2>(t4) << endl;
  cout << get<3>(t4) << endl;

  // type traits
  cout << endl;
  cout << tuple_size<decltype(t4)>::value << endl;// 4

  tuple_element<0, decltype(t4)>::type d;// d is variable of integer ( first element of t4
  cout << endl;
  cout << typeid(d).name() << endl;  

  return 0;
}
