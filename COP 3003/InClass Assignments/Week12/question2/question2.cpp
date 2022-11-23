#include <iostream>

using namespace std;

template <class T>

class Calculator
{
  public:
  
  T add(T a, T b)
  {
    return a + b;
  }

  T subtract(T a, T b)
  {
    return a - b;
  }

  T multiply(T a, T b)
  {
    return a * b;
  }

  T divide(T a, T b)
  {
    return a / b;
  }
};

int main ()
{

  Calculator<int> newCalculator;

  cout << newCalculator.add(25,50) << endl;

  cout << newCalculator.subtract(25,50) << endl;

  cout << newCalculator.multiply(25,50) << endl;

  cout << newCalculator.divide(25,25) << endl;


  return 0;
}