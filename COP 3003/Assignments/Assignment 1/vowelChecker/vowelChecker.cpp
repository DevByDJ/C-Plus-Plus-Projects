#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() 
{

    string vowels[10] = {"a", "A", "e", "E", "i", "I", "o", "O", "u", "U"};
    string userInput;
    bool isVowel;

    cout << "Enter a letter: ";
    cin >> userInput;

    for(int i = 0; i < 10; i++ )
    {
        if(userInput == vowels[i])
        {
            isVowel = true;
            break;
        }
        else 
        {
            isVowel = false;
        }

    }
    
    if(isVowel)
    {
        cout << userInput << " is a vowel" << endl;
    }
    else 
    {
        cout << userInput << " is not a vowel" << endl;
    }

    return 0;
     
}