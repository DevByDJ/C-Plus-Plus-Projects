#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sumOfDigits(int n);

int main()
{
	int n;
	cout << "Enter in a number: ";
	cin >> n;

	cout << endl << sumOfDigits(n) << endl;
	return 0;
}

int sumOfDigits(int n)
{
	int sum = 0;
	
	while(n > 0 || sum > 9)
	{
		if(n == 0)
		{
			n = sum;
			sum = 0;
		}
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
