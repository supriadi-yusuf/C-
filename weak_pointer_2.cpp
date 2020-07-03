#include <iostream>
#include <memory>

using namespace std;

class Dog{

  private:
    string _name;    
    weak_ptr<Dog> _friend; 

  public:

    Dog(string name){
      _name = name; 
      cout << _name << " is created." << endl;
    }

    ~Dog(){
      cout << _name << " is deleted." << endl;
    }

    void make_friend(shared_ptr<Dog> dog){ 
       _friend = dog;
    }

    void remove_friend(){
       _friend.reset();
    }

    void show_friend(){ 
      cout << "My name is " << _name << ". ";

      if( !_friend.expired()){
         cout << "My friend is " << _friend.lock()->_name << ". ";
         cout << "He is owned by " << _friend.use_count() << " ponters." << endl;
      }else
         cout << "I have no friend." << endl;      
    }
};

int main(){
  shared_ptr<Dog> d1(new Dog("Gunner"));

  shared_ptr<Dog> d2;
  d2 = make_shared<Dog>("Smoker");

  d1->make_friend(d2);
  //d2->make_friend(d1);

  d1->show_friend();
  d2->show_friend();

  d1->remove_friend();
  d2->remove_friend();

  d1->show_friend();
  d2->show_friend();

  return 0;
}
