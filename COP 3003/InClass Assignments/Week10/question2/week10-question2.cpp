/**
 * * Q2:Write a program to demonstrate operator 
 * *    overloading with detailed explanation on every 
 * *    logic you use in the program.
*/

#include<iostream>

using namespace std;
 
class Complex {
private:
    //data members
    int real, imaginery;
public:
  Complex(int r = 0, int i = 0) 
  {
    real = r;   
    imaginery = i;
  }
    
  // This is automatically called when '+' is used with
  // between two Complex objects
  Complex operator + (Complex const &obj) 
  {
        Complex result;

        result.real = real + obj.real;
        result.imaginery = imaginery + obj.imaginery;

        return result;
  }

  void display() 
  { 
    cout <<endl<< real << " + " << imaginery << "(i) " << '\n' <<endl; 
  }
  
};
 
int main()
{
    Complex firstComplexNumber(50, 2), secondComplexNumber(10, 20);

    Complex thirdComplexNumber = firstComplexNumber + secondComplexNumber;
    
    thirdComplexNumber.display();

    return 0;
}