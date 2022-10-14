/* 
* Program to find the median in an unsorted array using separate functions.
? Hint:  Step1: Sort the array
?        Step2: ​Find the number of elements is odd or even.
?        Step3: If ODD the number in the middle is median
?        Step4: If EVEN the average of middle two numbers are the median.
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
    * Assign the number of elements to the array and collect the user inputs
    * in a loop until the user reaches the maximum amount of elements.
    ! REQ: ONLY ACCEPT NUMBERS
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
    
    // -- SORTS THE ARRAY FROM LOWEST TO HIGHEST VALUES --
    sort(arrayOfInputs, arrayOfInputs + numberOfElements);

    bool isOdd = numberOfElements % 2;
    double result;

    // -- DETERMINES IF THE ARRAY IS EVEN OR ODD --
    if (!isOdd)
    {
        result = getMedianEven(arrayOfInputs, numberOfElements);
    }
    else
    {
        result = getMedianOdd(arrayOfInputs, numberOfElements);
    }

    // -- OUTPUT --
    cout << endl << "The Median is: " << result << endl;



    return 0;
}

/*
* getMedianEven() returns the median value by calculating the middle element of the array
* subtracting it by the next element, taking the value and dividing it in half and adding it back
* into the value of the middle element of the array.
! REQ: An array of double values, An integer value of the size of the Array.
**/
double getMedianEven (double num[], int sizeOfArray)
{
    double median; 
    int midElement, midElementOther;

    midElement = (sizeOfArray / 2) - 1;
    midElementOther = midElement + 1;


    median = (((num[midElementOther] - num[midElement])/ 2) + num[midElement]);

    return median;
}

/*
* getMedianOdd() returns the median value by calculating the middle element of the array
* and saving it's value into the median variable.
! REQ: An array of double values, An integer value of the size of the Array.
**/
double getMedianOdd (double num[], int sizeOfArray)
{
    double median; 
    int medianElement;

    medianElement = ((sizeOfArray - 1) / 2);

    median = num[medianElement];

    return median;
}
