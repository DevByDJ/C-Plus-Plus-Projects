/*---------------------------------------------------------
 *    File: TicTacToe.cpp
 *  Author: Danny Joseph
 * Purpose: Make a playable TicTacToe game via the console.
 * ---------------------------------------------------------*/


#include <iostream> 
#include <string>       // create a string variable for my name

using namespace std;

int startMenu();

int playerDecision();

int main() {

	startMenu();

	playerDecision();
	
	return 0;
}

int startMenu() {
	
	/*
	Defining the TicTacToe game board by using console outputs
	that will change over time due to player input by replacing the
	string values assigned in the variables...
	*/

	string gameTitle = "Welcome to Tic Tac Toe!";
	string titleDivider = "=====================";
	string firstRow = "  1  |  2  |  3  ";
	string secondRow = "  4  |  5  |  6  ";
	string thirdRow = "  7  |  8  |  9  ";
	string divider = "--------------------";
	string gameRules = "Choose 3 connecting tiles to win";

	std::cout << gameTitle << endl;
	std::cout << titleDivider << endl;
	std::cout << firstRow << endl;
	std::cout << secondRow << endl;
	std::cout << thirdRow << endl;
	std::cout << divider << endl;
	std::cout << endl;
	std::cout << gameRules << endl;
	std::cout << endl;

	return 0;
}

int playerDecision() {
	
	/*
	[Available Tile Logic]
    This while loop will check available tiles and handle whether
    the player can proceed or need to re-enter a new input. 
	*/

	int playerDecisionMade;
	std::cout << "Choose a tile: ";
	std::cin >> playerDecisionMade;

	return 0;
}

int tileAvailability() {

	int currentAvailableTiles[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	



}

