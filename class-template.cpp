#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack{

  private:
    vector<T> elems;//elements

  public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const{
      return elems.empty();
    }

};

template <class T>
void Stack<T>::push(T const& elem){
  //append copy of passed element
  elems.push_back(elem);
}

template <class T>
void Stack<T>::pop(){
  if( elems.empty())
     throw out_of_range("Stack<>::pop(): empty stack");

  //remove last element
  return elems.pop_back();
}

template <class T>
T Stack<T>::top() const {
  if( elems.empty())
     throw out_of_range("Stack<>::top(): empty stack");

  //return copy of last element
  return elems.back();
}

int main( int argc, char **argv){

  try{
    Stack<int> intStack;
    Stack<string> stringStack;

    //manipulate intStack
    intStack.push(10);
    cout << intStack.top() << endl;

    //manipulate stringStack
    stringStack.push("hello supri");
    cout << stringStack.top() << endl;

    stringStack.pop();

    stringStack.pop();//exception should be raised here

  }catch(exception const &ex){
    cerr << "Exception: " << ex.what() << endl;
  }
  
  return 0;
}


