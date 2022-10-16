/*
* Using Bubble sort algorithm functions write a program to arrange the numbers  
* in descending order.
**/

#include<iostream>

using namespace std;

void bubbleSort(int arr[], int numberOfElements);

int main ()
{
    /*
    * The following will have the user determine the size of the array
    * and collect the amount of inputs according the the size of the array.
    ! REQ: The user canot input a negative number during the size of the array.
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
    ! REQ: OnLY ACCEPT nUMBERS
    **/
    int arrayOfInputs[numberOfElements];
    
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
    
    bubbleSort(arrayOfInputs, numberOfElements);

    // -- OUTPUT --
    cout<< endl << "Sorted Array : ";
    for(int i=0;i<numberOfElements;i++)
        cout<<arrayOfInputs[i]<<" ";
    
    cout << endl;

    return 0;
}


void bubbleSort(int arr[], int numberOfElements)
{
    int i, j;
    bool isSwap;
    // Checking each original element position
    for(i = 0; i < numberOfElements; i++)
    {
        isSwap = false;                                
        for(j = 0; j < numberOfElements-i-1; j++)
        {
            // Compare values
            if( arr[j] < arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        
        // If no to elements are swapped then
        // array is sorted. Hence Break the loop.
        if(!isSwap)
        {
            break;
        }

    }
}