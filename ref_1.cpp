#include <iostream>
#include <thread>

using namespace std;

int main(){
  string s1, s2;

  s1 = "Hello kitty";

  ref(s2) = s1;

  cout << s1 << endl;// s1 contains "Hello kitty"
  cout << s2 << endl;// s2 is empty

  s2= "apa kabar?";

  cout << s1 << endl;// s1 contains "Hello kitty"
  cout << s2 << endl;// s2 contains "apa kabar?"

  s2 = ref(s1);

  cout << s1 << endl;// s1 contains "Hello kitty"
  cout << s2 << endl;// s2 contains "Hello kitty"

  s1= "apa kabar?";

  cout << s1 << endl;// s1 contains "apa kabar?"
  cout << s2 << endl;// s2 contains "Hello kitty"

  //cout << ref(s1) << endl;//error
  //cout << ref(s2) << endl;//error

  return 0;
}
