/*---------------------------------------------------------
 *    File: TicTacToe.cpp
 *  Author: Danny Joseph
 * Purpose: Make a playable TicTacToe game via the console.
 * ---------------------------------------------------------*/


#include <iostream> 
#include <string>       // create a string variable for my name

using namespace std;

int updateGameBoard() {

}

int main() {
		
	updateGameBoard();

	return 0;
}

int updateGameBoard() {
	
	string firstRow = "  1  |  2  |  3  ";
	string secondRow = "  4  |  5  |  6  ";
	string thirdRow = "  7  |  8  |  9  ";
	string divider = "--------------------";
	std::cout << firstRow + secondRow + thirdRow + divider;

	return 0;
}
