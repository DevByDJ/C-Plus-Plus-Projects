#include <ios>
#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

struct Currency {
    double conversionRate;
    double amountOfCurrency;
    string nameOfCurrency;
};

void currencyConverter(double userDollarAmount, Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble); 

void results(double userDollarAmount, Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble);

enum NameForCurrency {
    Names = 0, Mexican_Pesos, Japenese_Yen, Euros, Canadian_Dollar,
    Indian_Rupees, Belize_Dollar, CFP_Franc, Chinese_Yuan, Haitian_Gourde,
    Russian_Ruble
};

int main () 
{
    double userDollarAmount;
    int userChoices[5];
    bool validUSDInput, validCurrencyChoices;


    Currency mexicanPesos, japeneseYen, euros, canadianDollar, indianRupees,
    belizeDollar, cfpFranc, chineseYuan, haitianGourde, russianRuble;

    
    while(!validUSDInput)
    {
        cout << "Enter USD amount: " << endl;
        cin >> userDollarAmount;

        if(userDollarAmount > 0)
        {
            validUSDInput = true;
        }
        else 
        {
            cout << endl << "INCORRECT INPUT! TRY AGAIN!";
        }
    }


    while(!validCurrencyChoices)
    {
        cout << endl << "Foreign Currencies" << endl;
        cout << endl << "------------------" << endl;
        cout << endl << "1.) Mexican Pesos" << endl << "2.) Japenese Yen" << "3.) Euros" << endl
                     << "4.) Canadian Dollar" << endl << "5.) Rupees" << endl << "6.) Belize Dollar" << endl
                     << "7.) CFP Franc" << endl << "8.) Chinese Yuan" << endl << "9.) Haitian Gourde" << endl
                     << "10.) Russian Ruble" << endl << endl;

        cout << endl << "Please choose 5 types of currenices: " << endl;

        for(int i = 0; i < 5; i++)
        {
            // Create a while loop to test if the input given matches criteria.
            cin >> userChoices[i];
        }
        
        validCurrencyChoices = true;
    }

    currencyConverter(userDollarAmount, mexicanPesos, japeneseYen, euros, canadianDollar, indianRupees, belizeDollar,
     cfpFranc, chineseYuan, haitianGourde, russianRuble);

    results(userDollarAmount, mexicanPesos, japeneseYen, euros, canadianDollar, indianRupees, belizeDollar,
     cfpFranc, chineseYuan, haitianGourde, russianRuble);

    return 0;


}

void currencyConverter(double userDollarAmount, Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble) 
{

    mexicanPesos.conversionRate = 19.95f;
    japeneseYen.conversionRate = 140.31f;
    euros.conversionRate = 1.0f;
    canadianDollar.conversionRate = 1.31f;
    indianRupees.conversionRate = 79.87f;
    belizeDollar.conversionRate = 2.01f;
    cfpFranc.conversionRate = 120.23f;
    chineseYuan.conversionRate = 6.94f;
    haitianGourde.conversionRate = 120.58f;
    russianRuble.conversionRate = 61.01f;

    mexicanPesos.nameOfCurrency = "Mexican Pesos";
    japeneseYen.nameOfCurrency = "Japanese Yen";
    euros.nameOfCurrency = "Euros";
    canadianDollar.nameOfCurrency = "Canadian Dollar";
    indianRupees.nameOfCurrency = "Indian Rupees";
    belizeDollar.nameOfCurrency = "Belize Dollar";
    cfpFranc.nameOfCurrency = "CFP FRANC";
    chineseYuan.nameOfCurrency = "Chinese Yuan";
    haitianGourde.nameOfCurrency = "Haitian Gourde";
    russianRuble.nameOfCurrency = "Russian Ruble";

    mexicanPesos.amountOfCurrency = mexicanPesos.conversionRate * userDollarAmount;
    japeneseYen.amountOfCurrency = japeneseYen.conversionRate * userDollarAmount;
    euros.amountOfCurrency = euros.conversionRate * userDollarAmount;
    canadianDollar.amountOfCurrency = canadianDollar.conversionRate * userDollarAmount;
    indianRupees.amountOfCurrency = indianRupees.conversionRate * userDollarAmount;
    belizeDollar.amountOfCurrency = belizeDollar.conversionRate * userDollarAmount;
    cfpFranc.amountOfCurrency = cfpFranc.conversionRate * userDollarAmount;
    chineseYuan.amountOfCurrency = chineseYuan.conversionRate * userDollarAmount;
    haitianGourde.amountOfCurrency = haitianGourde.conversionRate * userDollarAmount;
    russianRuble.amountOfCurrency = russianRuble.conversionRate * userDollarAmount;

}


/* Convert double to string with specified number of places after the decimal
   and left padding. */
std::string prd(const double x, const int decDigits, const int width) {
    stringstream ss;
    ss << fixed << right;
    ss.fill(' ');        // fill space around displayed #
    ss.width(width);     // set  width around displayed #
    ss.precision(decDigits); // set # places after decimal
    ss << x;
    return ss.str();
}

/* Convert double to string with specified number of places after the decimal
   and left padding. */
std::string prs(const string s, const int width) {
    stringstream ss;
    ss << fixed << right;
    ss.fill(' ');        // fill space around displayed #
    ss.width(width);     // set  width around displayed #
    ss << s;
    return ss.str();
}



/*! Center-aligns string within a field of width w. Pads with blank spaces
    to enforce alignment. */
std::string center(const string s, const int w) {
    stringstream ss, spaces;
    int padding = w - s.size();                 // count excess room to pad
    for(int i=0; i<padding/2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str();    // format with padding
    if(padding>0 && padding%2!=0)               // if odd #, add 1 space
        ss << " ";
    return ss.str();
}

void results(double userDollarAmount, Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble)
{

    std::cout << center("USD",10)       << " | "
          << center("FOREIGN TYPE",15)     << " | "
          << center("FOREIGN VALUE",16) << "\n";

    std::cout << std::string(10*4 + 2*4, '-') << "\n";

    for(double x=1.5; x<200; x +=x*2) 
    {
        std::cout   << prd(userDollarAmount,2,10) << " | "
                    << prs(euros.nameOfCurrency,15)    << " | "
                    << prd(x*x/8.0,2,16) << "\n";
    }

}

