#include<iostream>
#include<cmath>
#include<string>

using namespace std;

// -- Converts an integer value to a Letter Grade for Logic --
enum letterGrades {
    Letters = 0, A, B, C, D, F
};

int main () 
{
    // -- Declaration --
    int userInput, letterIndicator;
    string answer, grade, gradeSymbol, vowel;
    bool validInput, isVowel;
    
    // -- Validates correct input --
    while(!validInput)
    {
        cout << endl << "Enter your grade average: " << endl;
        cin >> userInput;

        if(userInput >= 0 && userInput <= 100)
        {
            validInput = true;

            if(userInput >= 90 && userInput <= 100)
            {
                letterIndicator = 1;
            }
            else if (userInput >= 80 && userInput < 90) 
            {
                letterIndicator = 2;
            }
            else if (userInput >= 70 && userInput < 80)
            {
                letterIndicator = 3;
            }
            else if(userInput >= 60 && userInput < 70)
            {
                letterIndicator = 4;
            }
            else 
            {
                letterIndicator = 5;
            }
            
        }
        else
        {
            cout << endl << "ERROR: INCORRECT INPUT! TRY AGAIN" << endl;
        }

    }

    // -- Handles Logic based on user input --
    if(letterIndicator)
    {
        switch (letterIndicator) 
        {
            case A:
            grade = "A";

            isVowel = true;
            
            if(userInput >= 90 && userInput < 94)
            {
                gradeSymbol = "-";
            }
            else if(userInput >= 94 && userInput < 98)
            {
                gradeSymbol = "";
            }
            else 
            {
                gradeSymbol = "+";
            }
            break;

            case B:
            grade = "B";

            if(userInput >= 80 && userInput < 84)
            {
                gradeSymbol = "-";
            }
            else if(userInput >= 84 && userInput < 88)
            {
                gradeSymbol = "";
            }
            else 
            {
                gradeSymbol = "+";
            }
            break;

            case C:
            grade = "C";

            if(userInput >= 70 && userInput < 74)
            {
                gradeSymbol = "-";
            }
            else if(userInput >= 74 && userInput < 78)
            {
                gradeSymbol = "";
            }
            else
            {
                gradeSymbol = "+";
            }

            break;

            case D:
            grade = "D";

            if(userInput >= 60 && userInput < 64)
            {
                gradeSymbol = "-";
            }
            else if(userInput >= 64 && userInput < 68)
            {
                gradeSymbol = "";
            }
            else
            {
                gradeSymbol = "+";
            }

            break;

            case F:
            grade = "F";
            isVowel = true;
            break;

        }
    }

    // -- Displays for grammatical reasons --
    if(isVowel)
    {
        vowel = "an";
    }
    else 
    {
        vowel = "a";
    }

    // -- OUTPUT -- 
    cout << endl << "You received " << vowel << " " << grade << gradeSymbol
    << endl << endl;

}