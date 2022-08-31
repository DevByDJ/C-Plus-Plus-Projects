#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// -- GLOBAL VARIABLES --
float firstRoot, secondRoot;
bool isImaginery = false;

// -- FUNCTION INTIALIZATION --
float quadraticFormula(float a, float b, float c);


int main() {

    bool gameOver = false;

    while(!gameOver)
    {
        // -- Quadratic Formula Variables --
        float a;
        float b;
        float c;
        float firstStandardSolution;
        float secondStandardSolution;
        string userDecision;


        cout << "Enter a : " << endl;
        cin >> a;

        // -- DO NOT PROCEED WITH PROGRAM IF 'a' = 0.  --
        if(!a)
        {
            cout << endl << "ZERO CANNOT BE USED AS 'a' " << endl;
            gameOver = true;
            break;
        }
        
        cout << "Enter b : " << endl;
        cin >> b;
        cout << "Enter c : " << endl;
        cin >> c;

        // -- Calculates inputs using Quadratic Equation --
        quadraticFormula(a, b ,c);

        
        if(!isImaginery)
        {
            // -- STANDARD SOLUTION = Ax^2 + Bx + C = 0 --
            firstStandardSolution = (a*pow(firstRoot, 2.0) + (b*firstRoot) + c);

            secondStandardSolution = (a*pow(secondRoot, 2.0) + (b*secondRoot) + c);

            // -- OUTPUT --
            cout << endl << "First Standard Solution = " << firstStandardSolution << "     with " << firstRoot
            << " as the first root" << endl;
            cout << "Second Standard Solution = " << secondStandardSolution << "     with " << secondRoot
            << " as the second root" << endl;

            cout << endl;
        }
        else
        {
            // -- CANNOT CALCULATE IMAGINARY NUMBERS --
            cout << "Can NOT solve using Imaginary numbers!" << endl;
            cout << endl;
        }


        cout << "Try Again (Y/n): ";
        cin >> userDecision;
        cout << endl;

        if(userDecision == "Y" || userDecision == "y")
        {
            gameOver = false;
        }
        else {
            gameOver = true;
        }

    }

    return 0;
}

/*
    @float a - userInput
    @float b - userInput
    @float c - userInput
    @float discriminant - The value of the numerator
    @realPart - If there is an imaginary number this is the base value
    @imaginaryPart - this is used to signfy that the base value is imaginery

    This function uses the Quadratic Formula to find if the roots are real, complex or imaginary and
    returns the roots to be used in the main function!
*/
float quadraticFormula (float a, float b, float c)
{
    float discriminant, realPart, imaginaryPart;

    // -- Solve the numerator of the Quadratic equation --
    discriminant = b*b - 4*a*c;
    
    // -- If the roots are real numbers --
    if (discriminant > 0) {
        isImaginery = false;
        firstRoot = (-b + sqrt(discriminant)) / (2*a);
        secondRoot = (-b - sqrt(discriminant)) / (2*a);
    }
    
    // -- If the roots are equal to each other --
    else if (discriminant == 0) {
        isImaginery = false;
        firstRoot, secondRoot = -b/(2*a);
    }

    // -- If the roots are imaginary numbers --
    else {
        isImaginery = true;
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "firsRoot = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "secondRoot = " << realPart << "-" << imaginaryPart << "i" << endl;
    }

    return firstRoot, secondRoot;
}