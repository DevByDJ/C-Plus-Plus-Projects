#include <iostream> 
#include <string>

using namespace std;

int main () {

    bool gameOn = true;                    
    

    // ---- Coin Values ----
    const float quarters = .25f;            
    const float dimes = .1f;
    const float nickles = .05f;
    const float pennies = .01f;


    // ---- Gane Logic ----
    while(gameOn)
    {

        string gameDecision; // the condition that continues the game


        float totalChange;
        float totalQuarters;
        float totalDimes;
        float totalNickles;
        float totalPennies;

        float userQuarters;
        float userDimes;
        float userNickles;
        float userPennies;

        cout << endl;
        cout << "How many Quarters: ";
        cin >> userQuarters;
        cout << "How many Dimes: ";
        cin >> userDimes;
        cout << "How many Nickels: ";
        cin >> userNickles;
        cout << "How many Pennies: ";
        cin >> userPennies;

        // ---- TOTAL = USER INPUT x CONSTANT COIN VALUES ----
        totalQuarters = userQuarters * quarters;
        totalDimes = userDimes * dimes;
        totalNickles = userNickles * nickles;
        totalPennies = userPennies * pennies;

        // ---- SUM ----
        totalChange = totalQuarters + totalDimes + totalNickles + totalPennies;


        // ---- OUTPUT ----
        cout << "Your total is $" << totalChange << endl;
        cout << "Try Again? Y/n ";
        cin >> gameDecision;
        cout << endl;

        // ---- PLAY AGAIN? ----
        if(gameDecision == "Y" || gameDecision == "y"){

        }
        else{
            gameOn = false;
        }

    }

    return 0;

}