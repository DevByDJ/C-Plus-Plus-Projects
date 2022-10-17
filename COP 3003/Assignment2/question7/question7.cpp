/* 
*   Using dynamic memory function sort numbers between 1 and 100. (use the keyword: new and delete)
?   Hint: Use the function new to create memory space and delete it after completion of the program.
?         Get how many numbers you are going to sort from 1 to 100
?         Get the inputs
?         Perform sorting operation.
**/

#include<iostream>
#include<algorithm>

using namespace std;

// -- PROTOTYPE FUNCTIONS --
double getMedianEven (double num[], int sizeOfArray);
double getMedianOdd (double num[], int sizeOfArray);

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
    * Creating an array using DYNAMIC MEMORY ALLOCATION!
    * Assign the number of elements to the array and collect the user inputs
    * in a loop until the user reaches the maximum amount of elements.
    ! REQ: ONLY ACCEPT NUMBERS BETWEEN 1 and 100
    **/
    double* arrayOfInputs = NULL;
    arrayOfInputs = new double[numberOfElements];
    
    for(int i = 0; i < numberOfElements ; i++)
    {
        cout << endl << "Please enter a number: ";
        cin >> arrayOfInputs[i];

        // -- CATCH ERROR BASED ON REQ --
        while(cin.fail() || arrayOfInputs[i] < 1 || arrayOfInputs[i] > 100)
        {
            cout << endl << "Err: You must enter a number!" << endl << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> arrayOfInputs[i];
        }

    }
    
    // -- SORTS THE ARRAY FROM LOWEST TO HIGHEST VALUES --
    sort(arrayOfInputs, arrayOfInputs + numberOfElements);


    // -- OUTPUT --
    cout << "Your sorted array: ";

    for(int i = 0; i < numberOfElements; i++)
    {
        cout << " " << arrayOfInputs[i];
    }

    cout << endl;

    // -- DYNAMICALLY REMOVE MEMORY ALOCATION --
    delete [] arrayOfInputs;

    return 0;

}