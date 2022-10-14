/*
* Write a program for finding Fibonacci series for a given input using recursive 
* functions.
**/

#include <iostream>

using namespace std;


int fibSequence(int n);

int main()
{
    // -- INPUT --
    int n;
	cout << endl << "Please enter a number: ";
    cin >> n;

    // -- CATCH ERROR --
    while(cin.fail())
    {
        cout << endl << "Err: You must enter a number!" << endl << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> n;
    }

    // -- OUTPUT --
	cout << endl << "The result is: " << fibSequence(n) << endl;
	return 0;
}

/*
* fibSequence() returns the value of the number inputted by the user using
* the fib formula.
**/
int fibSequence(int n)
{
	if (n <= 1)
		return n;
	return fibSequence(n - 1) + fibSequence(n - 2);
}


