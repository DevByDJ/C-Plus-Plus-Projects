/*
*   Write a C++ Program to find Sum and Product of 5 numbers using inline function.
?   Hint: Write two separate inline functions one for sum and the other for product of
?   five numbers.
**/

#include<iostream>
#include<cmath>

using namespace std;

inline double getSum(double array[], int sizeOfArray);
inline double getProduct(double array[], int sizeOfArray);

int main () 
{
    int numberOfElements = 5;

    /*
    * Assign the number of elements to the array and collect the user inputs
    * in a loop until the user reaches the maximum amount of elements.
    ! REQ: OnLY ACCEPT NUMBERS
    **/
    double arrayOfInputs[numberOfElements];
    
    for(int i = 0; i < numberOfElements ; i++)
    {
        cout << endl << "Please enter a number: ";
        cin >> arrayOfInputs[i];

        // -- CATCH ERROR --
        while(cin.fail())
        {
            cout << endl << "Err: You must enter a number!" << endl << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> arrayOfInputs[i];
        }

    }


    cout << endl << "The sum is: " << getSum(arrayOfInputs, numberOfElements);

    cout << endl << "The product is: " << getProduct(arrayOfInputs, numberOfElements) << endl;

    return 0;

}

inline double getSum(double array[], int sizeOfArray)
{
    double result;

    for(int i = 0; i < sizeOfArray; i++)
    {
        result += array[i];
    }

    return result;

}


inline double getProduct(double array[], int sizeOfArray)
{
    double result;
    bool readyForProduct;

    for(int i = 0; i < sizeOfArray; ++i)
    {
        if(!readyForProduct)
        {
            result = array[i];
            readyForProduct = true;
        }

        else
        result *= array[i];
    }

    return result;
    
}