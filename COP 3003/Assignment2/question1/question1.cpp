#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Prototype function
double getSquareUsingRetVal();
double getSquareUsingRetRef(double &value);


int main ()
{

  bool runningProgram = true;
  while(runningProgram)
  {

    // -- intialize variables --
    bool validChoice;
    double value, userSelection;
    string continueProgram;


    while(!validChoice)
    {
      
      cout << endl << "Make a selection:";
      cout << endl << "1.) Return by Value";
      cout << endl << "2.) Return by Reference";
      cout << endl << endl << "Choose option 1 or 2: ";
      cin >> userSelection;

      if(userSelection == 1)
      {
        // -- INPUT --
        double result;
        result = getSquareUsingRetVal();


        // -- OUTPUT --
        cout << endl << "The result is: " << result << endl << endl;
        validChoice = true;

      }
      else if(userSelection == 2)
      {
        // -- INPUT --
        cout << endl << "Enter a number: ";
        cin >> value;

        // -- OUTPUT --
        cout << endl << "The result is: " << getSquareUsingRetRef(value) << endl << endl;
        validChoice = true;
      }
      else
      {
        // repeat loop..
      }
    }

    cout << "Try again? (Y/n): " << endl;
    cin >> continueProgram;


    // -- Handles breaking the loop --
    if(continueProgram == "Y" || continueProgram == "y")
    {
      // reset program
      validChoice = false;

    }
    else
    {
      // close program
      runningProgram = false;
    }
    

  }
  
  return 0;

}

// Takes a double value and squares then returns by value.
double getSquareUsingRetVal()
{
  double value;

  cout << endl << "Enter a number: ";
  cin >> value;

  return pow(value, 2);

}

// Takes a double value and squares then returns by reference.
double getSquareUsingRetRef(double &value)
{
  value = pow(value, 2);

  return value;
}
