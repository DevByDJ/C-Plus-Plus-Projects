/**
 * *Q4: Write a program to demonstrate abstract 
 * *    class and pure virtual function with detailed 
 * *    explanation on every logic you use in the 
 * *    program.
*/
#include<iostream>

using namespace std;
  
class Base
{
  int a;

  public:
    //Establishes the virtual function
    virtual void doNothing() = 0;

    int getA() 
    { 
      return a; 
    }
};
  
// This class inherits from Base and implements doNothing()
class Derived: public Base
{
  int b;

  public:
    void doNothing() 
    { 
      cout << endl << "doNothing() was called"<< '\n' << endl; 
    }
    
};
  
int main(void)
{
    Derived derivedClass;

    derivedClass.doNothing();

    return 0;
}