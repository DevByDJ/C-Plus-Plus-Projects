/*
* Write a function that computes average (I will call this the arithmetic mean or simply 
* the mean) and standard deviation of four scores. The average or mean, avg, is computed 
* as ...
 
? Hint:  avg = ( x1 + x2 + x3 + x4 ) / 4
 
? The standard deviation is computed as
  
? N-> total number of scores entered
? µ-> mean or average of the input scores.
! Output: standard deviation and mean.
**/

#include<iostream>
#include<cmath>

using namespace std;

double getAverage(double array[], int sizeOfArray);
double getStandardDeviation(double array[], double average, int sizeOfArray);

int main () 
{
    int numberOfElements = 4;

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

    double average = getAverage(arrayOfInputs, numberOfElements);

    double stdDeviation = getStandardDeviation(arrayOfInputs, average, numberOfElements);


    cout << endl << "The average is: " << average;

    cout << endl << "The standard deviation is: " << stdDeviation << endl;

    return 0;

}

double getAverage(double array[], int sizeOfArray)
{
    double result, average;

    for(int i = 0; i < sizeOfArray; i++)
    {
        result += array[i];
    }

    average = result / sizeOfArray;

    return average;

}


double getStandardDeviation(double array[], double average, int sizeOfArray)
{
    double variance, stdDeviation;

    for(int i = 0; i < sizeOfArray; ++i)
    {
        variance += pow(array[i] - average, 2);
    }

    variance = variance / sizeOfArray;

    stdDeviation = sqrt(variance);

    return stdDeviation;
    
}