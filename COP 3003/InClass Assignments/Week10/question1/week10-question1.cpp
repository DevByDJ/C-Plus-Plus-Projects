/**
 * * Q1: Write a program to demonstrate function 
 * *     overloading with detailed explanation on every 
 * *     logic you use in the program.
*/

#include<iostream>

using namespace std;

class BaseClass
{
public:
  //Establishes the virtual function
	virtual void displayFunction()
	{
		cout << endl << "This is displayFunction() method of BaseClass";
	}
	void showFunction()
	{
		cout << endl << "This is showFunction() method of BaseClass" << "\n" << endl;
	}
};

class DerivedClass : public BaseClass
{
public:
	// Overriding method that overrides the
	// base class's displayFunction method
	void displayFunction()
	{
		cout << endl << "This is displayFunction() method of DerivedClass" << "\n";
	}

};


int main()
{
	DerivedClass newDerivedClass;

	BaseClass &newBaseClass = newDerivedClass;

	newBaseClass.displayFunction();

	newDerivedClass.showFunction();
  
}
