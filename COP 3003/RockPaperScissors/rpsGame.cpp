#include <iostream>
#include <string>

using namespace std;

int userScore, cpuScore;

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

        userDecisionMaking(userChoice);

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