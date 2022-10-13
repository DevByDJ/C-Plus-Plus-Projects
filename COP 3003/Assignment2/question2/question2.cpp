/**
**  Q2: Find the factorial of a number using
*   @param recursive_function
*   @param Call_by_reference_function
*?  Hint: Write it as two separate programs one for recursive and the other for call by reference.
*/

#include <iostream>
#include <cmath>

using namespace std;

// -- Function Prototypes --
double factorialOfNumber(double number);


int main()
{
    // -- Variable Declaration --
    double number, result;

    // -- INPUT --
    cout << "Enter a number: ";
    cin >> number;

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
    
}