#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() 
{
  int matrixOne[3][3] = {{7, 13, 30}, {2, 12, 61}, {6, 9, 68}};
  int matrixTwo[3][3] = {{6, 17, 3}, {11, 26, 5}, {1, 8, 9}};
  int results[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
          for (int u = 0; u < 3; u++)
              results[i][j] += matrixOne[i][u] * matrixTwo[u][j];
      }

  cout << endl << "Resulting Matrix: " << endl << endl;

  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          cout << results[i][j] << ".";
      }
      cout << endl; 
  }

  cout << endl;

  return 0;
  
}