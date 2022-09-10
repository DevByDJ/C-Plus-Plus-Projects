#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() 
{
  int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int results[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
          for (int u = 0; u < 3; u++)
              results[i][j] += matrix1[i][u] * matrix2[u][j];
      }

  cout << endl << "Output Matrix: " << endl;

  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          cout << results[i][j] << ".";
      }
      cout << endl;
  
}