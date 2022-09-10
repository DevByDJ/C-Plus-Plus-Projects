#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() 
{
  int solution, userInput;

  cout << "Enter a number: ";
  cin >> userInput;

  for(int i = 1; i < 13 ; i++)
  {
    solution = userInput * i;
    cout << userInput << " x " << i << " = " << solution << endl;
  }

  return 0;
  
}