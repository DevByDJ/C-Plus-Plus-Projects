/*---------------------------------------------------------
 *    File: descend.cpp
 *  Author: Danny Joseph
 *   Class: COP 2001, Spring 2022
 * Purpose: Display user generated input in descending order.
 * ---------------------------------------------------------*/

#include <iostream>  

using namespace std;

int main() {
    
    int firstInput, secondInput, thirdInput;

    int firstResult, secondResult, thirdResult;

    // [Collecting User Input]
    
    cout << "First Input: ";
    cin >> firstInput;
    cout << "Second Input: ";
    cin >> secondInput;
    cout << "Third Input: ";
    cin >> thirdInput;

    /*
    
    [Input Logic]
    Using nested Loops to compare the first input variable collected
    by the user to determine if it has a greater value than the other two.
    Then storing the values in descending order into the 'result' variables,
    to be displayed at the end.

    */

    if ((firstInput > secondInput) && (firstInput > thirdInput))
    {
        firstResult = firstInput;
        if (secondInput > thirdInput)
        {
            secondResult = secondInput;
            thirdResult = thirdInput;
        }
        else
        {
            secondResult = thirdInput;
            thirdResult = secondInput;
        }

    }

    else if ((firstInput < secondInput) && (firstInput > thirdInput))
    {

        firstResult = secondInput;
        secondResult = firstInput;
        thirdResult = thirdInput;

    }

    else if ((firstInput < secondInput) && (firstInput < thirdInput))
    {

        thirdResult = firstInput;
        if (secondInput > thirdInput)
        {

            firstResult = secondInput;
            secondResult = thirdInput;
        }

        else
        {

            firstResult = thirdInput;
            secondResult = secondInput;

        }
    }
    
    else if ((firstInput == secondInput) && (firstInput > thirdInput))
    {
   
        firstResult = firstInput;
        secondResult = secondInput;
        thirdResult = thirdInput;

    }

    else if ((firstInput == secondInput) && (firstInput < thirdInput))
    {

        firstResult = thirdInput;
        secondResult = secondInput;
        thirdResult = firstInput;

    }

    else if ((firstInput > secondInput) && (firstInput == thirdInput))
    {

        firstResult = firstInput;
        secondResult = thirdInput;
        thirdResult = secondInput;

    }

    else if ((firstInput < secondInput) && (firstInput == thirdInput))
    {

        firstResult = secondInput;
        secondResult = thirdInput;
        thirdResult = firstInput;

    }

    else if ((secondInput == thirdInput) && (firstInput > secondInput))
    {

        firstResult = firstInput;
        secondResult = secondInput;
        thirdResult = thirdInput;
    }

    else if ((secondInput == thirdInput) && (firstInput < secondInput))
    {

        firstResult = secondInput;
        secondResult = thirdInput;
        thirdResult = firstInput;
    }
    
    else if ((firstInput == secondInput) && (firstInput == thirdInput) && (secondInput == thirdInput))
    {

        firstResult = firstInput;
        secondResult = secondInput;
        thirdResult = thirdInput;
    }


    // [Displaying User Input]

    cout << "=================" << endl;
    cout << "" << endl;
    cout << firstResult << endl;
    cout << secondResult << endl;
    cout << thirdResult << endl;
    cout << "" << endl;
    cout << "=================" << endl;

    return 0;
}


