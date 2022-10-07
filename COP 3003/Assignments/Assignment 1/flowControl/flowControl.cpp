#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() 
{
  int solution;

  // flow controlled loop that outputs six different solutions
  for(int i = 0; i < 6 ; i++)
  {
    solution = 5 * i;
    cout << "5 x " << i << " = " << solution << endl;
  }

  return 0;
  
}