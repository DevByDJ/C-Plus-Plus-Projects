/**
 * * Q3: Write a program to demonstrate function 
 * *     overriding with detailed explanation on every 
 * *     logic you use in the program.
*/

#include<iostream>

using namespace std;

//First function that requires no parameters.
int add()
{
  int a = 1; 
  int b = 2;

  //Returns the sum of a and b
  return a+b;
}

//2nd function that requires three parameters
int add(int a, int b, int c)
{
  //Returns the sum then the product of a, b and c
  return a+b*c;
}

//Third function that requires four parameters
int add(int a, int b, int c, int d)
{
  //Returns the sum of a, b and c and the difference of d
  return a+b+c-d;
}


int main ()
{

  int a = 4;
  int b = 5;
  int c = 6;
  int d = 7;

  cout<<endl<<"1st function result: "<<add();

  cout<<endl<<"2nd function result: "<<add(a, b, c);

  cout<<endl<<"3rd function result: "<<add(a, b, c, d)<<endl;

  return 0;
}