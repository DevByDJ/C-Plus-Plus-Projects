/*
* Write a C++ Program to Reverse an Array of Strings.
?   Hint: Input as many strings you would like to reverse.
?             Get each string input as an array and
?             Reverse each string.
**/

#include <bits/stdc++.h>

using namespace std;

void reverseString(string array[], int sizeOfArray);

int main () 
{
    /*
    * The following will have the user determine the size of the array
    * and collect the amount of inputs according the the size of the array.
    ! REQ: The user cannot input a negative number during the size of the array.
    **/
    int numberOfElements;
    cout << "Enter how the amount of numbers to compare: ";
    cin >> numberOfElements;

    // -- CATCH ERROR --
    while(cin.fail() || numberOfElements <= 0)
    {
        cout << endl << "Err: Invalid number! Must be greater than 0!" << endl << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> numberOfElements;
    }

    /*
    * Assign the number of elements to the array and collect the user inputs
    * in a loop until the user reaches the maximum amount of elements.
    ! REQ: OnLY ACCEPT NUMBERS
    **/
    string arrayOfInputs[numberOfElements];
    
    for(int i = 0; i < numberOfElements ; i++)
    {
        cout << endl << "Please enter a string: ";
        cin >> arrayOfInputs[i];

        // -- CATCH ERROR --
        while(cin.fail())
        {
            cout << endl << "Err: You must enter a string!" << endl << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> arrayOfInputs[i];
        }

    }

    reverseString(arrayOfInputs, numberOfElements);
    
    return 0;

}

void reverseString(string array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        reverse(array[i].begin(), array[i].end());
        cout << endl << "Reversed String(s): " << array[i] << endl;
    }
    
}
