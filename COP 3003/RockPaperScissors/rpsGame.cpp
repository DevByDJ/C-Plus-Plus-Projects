#include <iostream>
#include <string>

using namespace std;

int userScore, cpuScore;

// -- Function Initialization --
void displayMainScreen ();
int userDecisionMaking(int &userChoice);
int cpuDecisionMaking(int &cpuChoice, int randomChoice, string cpu);
int decisionMade(int &userChoice, int &cpuChoice, int &userScore, int &cpuScore);
void displayScore(int &userScore, int &cpuScore);

int main () 
{

    bool gameOver = false;

    while(!gameOver)
    {

        // -- Values that will control the logic and display the score. --
        int randomChoice, userChoice, cpuChoice;

        string cpu, userDecision;


        displayMainScreen();

        // -- Function handles the input given by the user --
        userDecisionMaking(userChoice);

        // -- Function handles the input given by the cpu --
        cpuDecisionMaking(cpuChoice, randomChoice, cpu);

        // -- DETERMINES WHO WINS BASED ON 'userChoice and cpuChoice' --
        decisionMade( userChoice, cpuChoice, userScore, cpuScore);

        // -- DISPLAY SCORE --
        displayScore(userScore, cpuScore);

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

void displayMainScreen() 
{
    // -- GAME TITLE AND DISPLAY --

    cout << endl << endl << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "----------------------------------" << endl;
    cout << "R - Rock | P - Paper | S - Scissors" << endl << endl;
    
}

/*
    @param int userChoice: referenced variable passed along functions that retrieves and assigns the users decision.

    @description: This function requires an integer variable "userChoice" as a parameter. We first determine
                  the users input given by a R, P or S then assign that string into an integer variable so we
                  can compare it later. We then return the "userChoice" value.

    @requirements: The user has to enter R, P or S! If they do not, restart the input loop until they do!
*/
int userDecisionMaking(int &userChoice)
{

    // -- Input values to be compared --
    string user;

    bool successfulResponse;

    // -- USER RESPONSE LOOP: WILL ONLY BREAK IF USER INPUTS ALLOWED REPONSES. --
    while (!successfulResponse)
    {
        cout << "Please select your choice: " ;
        cin >> user;

        if(user == "R")
        {
            userChoice = 1;
            successfulResponse = true;
        }
        else if(user == "P")
        {
            userChoice = 2;
            successfulResponse = true;
        }
        else if(user == "S")
        {
            userChoice = 3;
            successfulResponse = true;
        }
        else
        {
            cout << endl << "INVALID RESPONSE! TRY AGAIN!" << endl << endl;
            successfulResponse = false;
        }  
    }

    return userChoice;

}

/*
    @param int cpuChoice: referenced variable passed along functions that retrieves and assigns the cpu decision.
           int randomChoice: used to generate a random integer between 1-3 which we use to determine the Rock,Paper, Scissor.
           string cpu: Display purposes!

    @description: This function requires an integer variable "cpuChoice" as a parameter. We first determine
                  the cpu's decision by randomly generating a number between 1 and 3. We then use that value to determine a
                  Rock(1), Paper(2), Scissors(3) decision and return that value.

*/
int cpuDecisionMaking(int &cpuChoice, int randomChoice, string cpu)
{
    randomChoice = rand() % 3 + 1;

    cpuChoice = randomChoice;

    // -- Assign the random choice to a R.P.S string value --

    if(cpuChoice == 1)
    {
        cpu = "R";
    }
    else if(cpuChoice == 2)
    {
        cpu = "P";
    }
    else if(cpuChoice == 3)
    {
        cpu = "S";
    }

    return cpuChoice;

}

/*
    @param int userChoice: referenced variable passed along functions that retrieves and assigns the users decision.
           int cpuChoice: referenced variable passed along functions that retrieves and assigns the cpu decision.
           int userScore: used to store the score of the user which is incremented by 1 each win.
           int cpuScore: used to store the score of the cpu which is incremented by 1 each win.

    @description: This function determines the logic of how a user or cpu can win the game. Then it increments the
                  winners score by 1 and returns the value of both the user and cpu.

    @requirements: [Winning Combinations] - Rock(1) beats Scissors(3)
                                          - Paper(2) beats Rock(1)
                                          - Scissors(3) beats Paper(2)

                    ANYTHING ELSE         - DRAW!
*/
int decisionMade(int &userChoice, int &cpuChoice, int &userScore, int &cpuScore)
{

    // Rock Beats Scissors!
    if(userChoice == 1 && cpuChoice == 3)
    {
        cout << "User chose: Rock" << endl;
        cout << "Cpu chose: Scissors" << endl << endl;
        cout << "USER WINS!";
        userScore++;
    }

    // Paper Beats Rock
    else if(userChoice == 2 && cpuChoice == 1)
    {
        cout << "User chose: Paper" << endl;
        cout << "Cpu chose: Rock" << endl << endl;
        cout << "USER WINS!";
        userScore++;
    }

    // Scissors beats Paper
    else if(userChoice == 3 && cpuChoice == 2)
    {
        cout << "User chose: Scissors" << endl;
        cout << "Cpu chose: Paper" << endl << endl;
        cout << "USER WINS!";
        userScore++;
    }

    // IT'S A TIE!
    else if(userChoice == cpuChoice)
    {
        cout << "YOU CHOSE THE SAME AS THE CPU!" << endl << endl;
        cout << "ITS DRAW!";
    }

    // USER LOST!
    else 
    {
        // -- Lost By Rock --
        if(cpuChoice == 1)
        {
            cout << "User chose: Scissors" << endl;
            cout << "Cpu chose: Rock" << endl << endl;
            cout << "CPU WINS!";
            cpuScore++;
        }
        // -- Lost By Paper --
        else if (cpuChoice == 2)
        {
            cout << "User chose: Rock" << endl;
            cout << "Cpu chose: Paper" << endl << endl;
            cout << "CPU WINS!";
            cpuScore++;
        }
        // -- Lost By Scissors --
        else 
        {
            cout << "User chose: Paper" << endl;
            cout << "Cpu chose: Scissors" << endl << endl;
            cout << "CPU WINS!";
            cpuScore++;
        }

    }

    cout << endl;    

    return userScore;
    return cpuScore;
}

void displayScore(int &userScore, int &cpuScore)
{
    cout << endl << "---------------";
    cout << endl << "_____Score_____" << endl << endl;

    cout << "USER: " << userScore << endl;
    cout << "CPU: " << cpuScore << endl << endl;

}