#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int digitCounter(int userInput, int digitCount);

int main() {

    int userInput;
    int digitCount;
    int newNumberCount;
    int currentElement;
    int solution[0];
    
    cout << "Enter a number: ";
    cin >> userInput;

    digitCounter(userInput, digitCount);

    for(int i = digitCount; i == 0; i--)
    {
        int solution [i];
        currentElement = i - 1;

        solution[currentElement] = userInput % 10;
        userInput = userInput / 10;

        newNumberCount++;

        return solution[i];
    }

    for(int i = 0; i < newNumberCount; i++)
    {
        currentElement = i - 1;
        int newSolution[i];
        newSolution[0] = solution[i] + solution[currentElement];
    }


}

int digitCounter(int userInput, int digitCount)
{

    while(digitCount != 0)
    {
        userInput = userInput / 10;
        digitCount++;
    }

    return digitCount;

}