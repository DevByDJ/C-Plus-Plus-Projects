/*
* Write a C++ program to find the square of an integer number and 
* square of a double number and count number of times a function is called.
? Hint:
?  - You may have one class square and many methods like getting input, 
?    calculation of square, displaying the output etc.,
?  - Use static variable to count the all the methods you called in the main function.
**/

#include<iostream>
#include<cmath>

enum nameOfChoices
{
  Names = 0, choseDouble, choseInteger
};

using namespace std;

class UserInput
{
  public:

  /*
  * Defines the path the user will take to calculate the square of a number
  @param userSelection: determines the menu selection route and follows a case-switch logic
  ! REQ: MUST BE A 1 or 2 answer for the logic to work correctly
  **/
  void getUserMenuChoice()
  {
    int userSelection;

    cout << endl << "Make a selection:";
    cout << endl << "1.) Square a Double";
    cout << endl << "2.) Square an Integer";
    cout << endl << endl << "Choose option 1 or 2: ";
    cin >> userSelection;

    // -- CATCH ERROR --
    while(cin.fail() || userSelection < 1 || userSelection > 2)
    {
        cout << endl << "Err: You must enter either 1 or 2!" << endl << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> userSelection;
    }

    if(userSelection)
    {
      switch(userSelection)
      {
        case choseDouble:
        // -- INPUT --
        double resultOfDub;
        resultOfDub = getSquareUsingDouble();
         // -- OUTPUT --
        cout << endl << "The result is: " << resultOfDub << endl << endl;
        break;

        case choseInteger:
        // -- INPUT --
        int resultOfInt;
        resultOfInt = getSquareUsingInteger();
         // -- OUTPUT --
        cout << endl << "The result is: " << resultOfInt << endl << endl;
        break;
      };
    };
  }
   
  // Takes a double value and squares then returns by value.
  double getSquareUsingDouble()
  {
    double value;

    cout << endl << "Enter a number: ";
    cin >> value;

    // -- CATCH ERROR --
    while(cin.fail())
    {
        cout << endl << "Err: You must enter a number!" << endl << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> value;
    }

    return pow(value, 2);

  };

  // Takes a int value and squares then returns by value.
  double getSquareUsingInteger()
  {
    int value;

    cout << endl << "Enter a number: ";
    cin >> value;

    // -- CATCH ERROR --
    while(cin.fail())
    {
        cout << endl << "Err: You must enter a number!" << endl << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> value;
    }

    return pow(value, 2);

  };

  // Determines if the user would like to try again.
  bool playAgain(bool &userChoice)
  {
    string userDecision;
    cout << "Try Again? Y/n ";
    cin >> userDecision;
    cout << endl;

    // -- CATCH ERROR --
    while(cin.fail())
    {
        cout << endl << "Err: You must enter a (Y or N)!" << endl << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> userDecision;
    }

    // ---- PLAY AGAIN? ----
    if(userDecision == "Y" || userDecision == "y")
    {
      // repeat loop
      userChoice = true;
    }
    else
    {
      userChoice = false;
    }

    return userChoice;
  }
};

using namespace std;

int main()
{

  UserInput userInput;

  bool runningProgram = 1;

  while(runningProgram)
  {
    userInput.getUserMenuChoice();

    userInput.playAgain(runningProgram);
  }

  return 0;
}