#include<iostream>
#include<cmath>
#include<string>

using namespace std;

// -- Converts integer inputs into Calendar names for logic --
enum calendarNames{
    Names = 0, January, February, March, April, May, June, July, August, September,
    October, November, December
};

int main () 
{
    // -- Declaration --
    int userInput, amountOfDays;
    string answer, month;
    bool isLeapYear, validInput;
    
    // -- Validates correct input --
    while(!validInput)
    {
        cout << endl << "Enter a month (MM): " << endl;
        cin >> userInput;

        if(userInput > 0 && userInput < 13)
        {
            validInput = true;
        }
        else
        {
            cout << endl << "ERROR: INCORRECT INPUT! TRY AGAIN" << endl;
        }

    }

    // -- Handles Logic based on user input --
    if(userInput)
    {
        switch (userInput) 
        {
            case January:
            month = "January";
            amountOfDays = 31;
            break;

            case February:
            month = "February";

            cout << "Is it a Leap Year (Y/n): " << endl;
            cin >> answer;

            if(answer == "Y" || answer == "y")
            {
                isLeapYear = true;
            }

            if(isLeapYear)
            {
                amountOfDays = 29;
            }
            else 
            {
                amountOfDays = 28;
            }
            break;

            case March:
            month = "March";
            amountOfDays = 31;
            break;

            case April:
            month = "April";
            amountOfDays = 30;
            break;

            case May:
            month = "May";
            amountOfDays = 31;
            break;

            case June:
            month = "June";
            amountOfDays = 30;
            break;

            case July:
            month = "July";
            amountOfDays = 31;
            break;

            case August:
            month = "August";
            amountOfDays = 31;
            break;

            case September:
            month = "September";
            amountOfDays = 30;
            break;

            case October:
            month = "October";
            amountOfDays = 31;
            break;

            case November:
            month = "November";
            amountOfDays = 30;
            break;

            case December:
            month = "December";
            amountOfDays = 31;
            break;

        }
    }

    // -- OUTPUT -- 
    cout << endl << month << " has " << amountOfDays << " days!"
    << endl;

}