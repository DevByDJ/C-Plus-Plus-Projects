/*
* Write a program in C++ to find maximum number and minimum number as  
* two different functions in a given array of size n.
? Hint: Write it as a single program having two functions (max and min)
**/

#include<iostream>

using namespace std;

// -- PROTOTYPE FUNCTIONS --
int getMaxNumber (int num[], int sizeOfArray);
int getMinNumber (int num[], int sizeOfArray);

int main()
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
    ! REQ: ONLY ACCEPT NUMBERS
    **/
    int arrayOfInputs[numberOfElements];
    
    for(int i = 0; i < numberOfElements ; i++)
    {
        cout << endl << "Please enter a number: ";
        cin >> arrayOfInputs[i];

    }


    /*
    * Run the Minimum and Maximum functions by passing the newly created array
    * as an argument and return the values in the new variables minNumber & maxNumber
    **/
    int maxNumber = getMaxNumber(arrayOfInputs, numberOfElements);
    int minNumber = getMinNumber(arrayOfInputs, numberOfElements);


    // -- OUTPUT --
    cout << endl << "The max number within the array provided is: " << maxNumber;
    cout << endl << "The min number within the arrray provided is: " << minNumber << endl;

    return 0;
    
}


/*
* getMaxNumber() takes in an array and the size of the array. It will then run a 
* loop that will check every element in the array and compare each to discover which number
* is the highest, save it, and return as "highNum"
**/
int getMaxNumber(int num[], int sizeOfArray)
{
    int highNum = num[0];
    for(int i = 0; i < sizeOfArray; i++)
    {
        if(num[i] > highNum)
        {
            highNum = num[i];
        }
    }

    return highNum;
}


/*
* getMinNumber() takes in an array and the size of the array. It will then run a 
* loop that will check every element in the array and compare each to discover which number
* is the lowest, save it, and return as "lowNum"
**/
int getMinNumber(int num[], int sizeOfArray)
{
    int lowNum = num[0];
    for(int i = 0; i < sizeOfArray; i++)
    {
        if(num[i] < lowNum)
        {
            lowNum = num[i];
        }
    }

    return lowNum;
}
