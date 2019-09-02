#include <iostream>
#include <string>

using namespace std;

class Student{
  private:    
    int no;
    string nama;

  public:
  Student(string name){
    static int s_no=0;
    no = ++s_no;
    nama = name;
    cout << "create " << nama << no << endl;
  }

  ~Student(){
      cout << "delete " << nama << no << endl;
   }
};

int main(int argc, char* argv[]){
  
  //Student students("")[10];//error
  //Student students[10]("");//error
  Student s("supri");
  s = Student("mukidi");
  
  Student* student;
  //student = Student("aa");//error
  student = new Student("aa");
  delete student;

  return 0;
}
