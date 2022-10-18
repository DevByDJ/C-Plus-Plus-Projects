/*
* Write a program to find the factorial of a number using methods outside 
* the class
**/

#include<iostream>

using namespace std;

class UserInput
{
    public:

    // -- Variable Declaration --
    double number;

    double getNumber()
    {
        // -- INPUT --
        cout << "Enter a number: ";
        cin >> number;

        return number;
    };

};

double factorialOfNumber(double number);

int main()
{
    // !-- OBJECT & VARIABLE DECLARATION --
    UserInput userInput;
    double number, result;

    // !-- INPUT USING THE CLASS METHOD --
    number = userInput.getNumber();

    // !-- CALCULATIONS USING METHOD OUTSIDE CLASS --
    result = factorialOfNumber(number);

    // -- OUTPUT --
    cout << endl << "The result of " << number << " factorial is = " << result << endl;

    return 0;
}

double factorialOfNumber(double number)
{
    // As long as the number entered isn't one do this..
    if(number > 1)
    {
        //  N x (N - 1) ..
        return number * factorialOfNumber(number - 1);
    }
    else
    {
        // Return 1 if the user chooses any factorial less than 1
        return 1;
    }

};