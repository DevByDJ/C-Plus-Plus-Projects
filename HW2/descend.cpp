/*---------------------------------------------------------
 *    File: descend.cpp
 *  Author: Danny Joseph
 *   Class: COP 2001, Spring 2022
 * Purpose: Display user generated input in descending order.
 * ---------------------------------------------------------*/

#include <iostream> 
#include <string> 

using namespace std;

int main() {

    int firstInput, secondInput, thirdInput;

    int firstResult, secondResult, thirdResult;

    // [Collecting User Input]

    std::cout << "First Input: ";
    std::cin >> firstInput;
    std::cout << "Second Input: ";
    std::cin >> secondInput;
    std::cout << "Third Input: ";
    std::cin >> thirdInput;

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


    // [Displaying User Input]

    std::cout << "=================" << endl;
    std::cout << "" << endl;
    std::cout << firstResult << endl;
    std::cout << secondResult << endl;
    std::cout << thirdResult << endl;
    std::cout << "" << endl;
    std::cout << "=================" << endl;

    return 0;
}


