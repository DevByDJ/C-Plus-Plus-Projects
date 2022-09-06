#include <ios>
#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

void currencyConverter(double userDollarAmount);

int main () 
{
    double userDollarAmount;
    bool validInput;

    while(!validInput)
    {
        cout << "Enter USD amount: " << endl;
        cin >> userDollarAmount;

        if(userDollarAmount > 0)
        {
            validInput = true;
        }
        else 
        {
            cout << endl << "INCORRECT INPUT! TRY AGAIN!";
        }
    }

    currencyConverter(userDollarAmount);

    return 0;


}

void currencyConverter(double userDollarAmount)
{
    double pesosAmount, yenAmount,
    eurosAmount, canadianAmount, rupeesAmount;

    pesosAmount = 19.95f * userDollarAmount;
    yenAmount = 140.31f * userDollarAmount;
    eurosAmount = 1.0f * userDollarAmount;
    canadianAmount = 1.31f * userDollarAmount;
    rupeesAmount = 79.87f * userDollarAmount;

    cout << "Pesos : $" << fixed << setprecision(2) << pesosAmount << endl;
    cout << "Yen: $" << fixed << setprecision(2) << yenAmount << endl;
    cout << "Euros: $" << fixed << setprecision(2) << eurosAmount << endl;
    cout << "Canadian: $" << fixed << setprecision(2) << canadianAmount << endl;
    cout << "Rupees: $" << fixed << setprecision(2) << rupeesAmount << endl;

}