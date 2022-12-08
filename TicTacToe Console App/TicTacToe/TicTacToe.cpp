/*---------------------------------------------------------
 *    File: TicTacToe.cpp
 *  Author: Danny Joseph
 * Purpose: Make a playable TicTacToe game via the console.
 * ---------------------------------------------------------*/


#include <iostream> 
#include <string>       // create a string variable for my name

using namespace std;

void startMenu();

int playerDecision();

bool tileAvailability(int selectedTile);

int main() {

	startMenu();

	int playerChoice = playerDecision();
	while (!tileAvailability(playerChoice)) {
		cout << "Tile not available. Please choose another tile: ";
		cin >> playerChoice;
	}

	return 0;
}

void startMenu() {
	
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

	cout << gameTitle << endl;
	cout << titleDivider << endl;
	cout << firstRow << endl;
	cout << secondRow << endl;
	cout << thirdRow << endl;
	cout << divider << endl;
	cout << endl;
	cout << gameRules << endl;
	cout << endl;
}

int playerDecision() {
	
	/*
	[Player Decision]
	This function will prompt the player to enter a tile 
	choice and return the value to the main function...
	*/

	int playerChoice;
	cout << "Choose a tile: ";
	cin >> playerChoice;

	return playerChoice;
}

bool tileAvailability(int selectedTile) {

	// Define an array of available tiles
	int currentAvailableTiles[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	// Check if the selected tile is in the array of available tiles
	for (int i = 0; i < sizeof(currentAvailableTiles); i++) {
		if (selectedTile == currentAvailableTiles[i]) {
			// If the tile is available, remove it from the array and return true
			currentAvailableTiles[i] = 0;
			return true;
		}
	}

	// If the tile is not in the array, it is not available and the function returns false
	return false;
}

