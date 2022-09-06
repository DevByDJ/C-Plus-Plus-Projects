#include <ios>
#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

// The defining variables that make up a 'Currency'
struct Currency {
    double conversionRate;
    double amountOfCurrency;
    string nameOfCurrency;
};

// ========== PROTOTYPE FUNCTIONS ===================

double getUSDAmount(double &userDollarAmount, bool validUSDInput);

int* getUserChoices(int userChoices[], bool validCurrencyChoices, bool validUserChoice);

double* currencyConverter(double &userDollarAmount, int userChoices[], double foreignValues[], Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble); 

string* currencyAssignment(int userChoices[], string foreignTypes[], Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble);

void results(double &userDollarAmount, string foreignTypes[], double foreignValues[], Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble);

bool getEndProgram (string keepRunningProgram, bool &runningProgram);

// =========== END OF PROTOTYPE FUNCTIONS =====================


// -- Simplifies user choices to readable selections --
enum NameForCurrency {
    Names = 0, Mexican_Pesos, Japenese_Yen, Euros, Canadian_Dollar,
    Indian_Rupees, Belize_Dollar, CFP_Franc, Chinese_Yuan, Haitian_Gourde,
    Russian_Ruble
};


int main () 
{
    bool runningProgram = true;

    // -- RUN PROGRAM --
    while(runningProgram)
    {
        // --Initialization of program variables!--
        double userDollarAmount, foreignValues[5];
        int userChoices[5];
        bool validUSDInput, validCurrencyChoices, validUserChoice;
        string foreignTypes[5], keepRunningProgram;

        // -- New Currency --
        Currency mexicanPesos, japeneseYen, euros, canadianDollar, indianRupees,
        belizeDollar, cfpFranc, chineseYuan, haitianGourde, russianRuble;

        // -- Get User Input for USD Amount --
        getUSDAmount(userDollarAmount, validUSDInput);

        // -- Get Users Choice of which Foreign Currencies to compare --
        getUserChoices(userChoices, validCurrencyChoices, validUserChoice);
        
        // -- Calculates the value of each currency based off the USD amount --
        currencyConverter(userDollarAmount, userChoices, foreignValues ,mexicanPesos, japeneseYen, euros, canadianDollar, indianRupees, belizeDollar,
        cfpFranc, chineseYuan, haitianGourde, russianRuble);

        // -- Assigns the currency string values based of userChoices to be displayed in chart --
        currencyAssignment(userChoices, foreignTypes, mexicanPesos, japeneseYen, euros, canadianDollar, indianRupees, belizeDollar,
        cfpFranc, chineseYuan, haitianGourde, russianRuble);

        // -- Displays RESULTS --
        results(userDollarAmount,foreignTypes, foreignValues, mexicanPesos, japeneseYen, euros, canadianDollar, indianRupees, belizeDollar,
        cfpFranc, chineseYuan, haitianGourde, russianRuble);
        
        // -- DETERMINES WHETHER TO CLOSE OR RUN THE PROGRAM AGAIN --
        getEndProgram(keepRunningProgram, runningProgram);
        
    }

    return 0;

}

/**
* * getUSDAmount()
* ? This Function gets user input as [userDollarAmount] and stores as a 'double'.
* ! [IF THE USER INPUTS ANYTHING BELOW ZERO IT WILL RESTART INPUT LOOP] 

* @param userDollarAmount - Referenced variable that will store user input 
* @param validUSDInput - Determines if the input is valid. True: Breaks Loop || False: Restarts Loop
*/
double getUSDAmount(double &userDollarAmount, bool validUSDInput)
{
    while(!validUSDInput)
        {
            cout << "Enter USD amount: $";
            cin >> userDollarAmount;

            if(userDollarAmount > 0)
            {
                validUSDInput = true;
            }
            else 
            {
                cout << endl << "INCORRECT USD AMOUNT! TRY AGAIN!" << endl;
            }
        }

    return userDollarAmount;
}


/**
* TODO : FILL IN PARAMS!
* * int getUserChoices()
* ? This Function gets user input as [userDollarAmount] and stores as a 'double'.
* ! [IF THE USER INPUTS ANYTHING BELOW ZERO IT WILL RESTART INPUT LOOP] 

* @param userChoices[] -  
* @param validCurrencyChoices - 
* @param validUserChoice -
*/
int* getUserChoices(int userChoices[], bool validCurrencyChoices, bool validUserChoice)
{
    while(!validCurrencyChoices)
        {
            cout << endl << "Foreign Currencies";
            cout << endl << "------------------" << endl;
            cout << endl << "1.) Mexican Pesos" << endl << "2.) Japenese Yen" << endl << "3.) Euros" << endl
                        << "4.) Canadian Dollar" << endl << "5.) Rupees" << endl << "6.) Belize Dollar" << endl
                        << "7.) CFP Franc" << endl << "8.) Chinese Yuan" << endl << "9.) Haitian Gourde" << endl
                        << "10.) Russian Ruble" << endl << endl;

            cout << endl << "Please choose 5 types of currenices: " << endl;

            for(int i = 0; i < 5; i++)
            {
                // Create a while loop to test if the input given matches criteria.
                validUserChoice = false;
                while(!validUserChoice)
                {
                    cin >> userChoices[i];

                    if(userChoices[i] > 0 && userChoices[i] < 11)
                    {
                        validUserChoice = true;
                    }
                    else 
                    {
                        cout << endl << "INVALID CHOICE! TRY AGAIN!" << endl;
                    }
                }
                
            }
            
            validCurrencyChoices = true;
        }
    return userChoices;
}

/**
* TODO: FILL IN PARAMS!
* * double currencyConverter()

* ? This function declares the values of 'conversion rate', 'name of the currency' and 'the amount after conversion' for each currency,
* ?     then it assigns the amount after conversion into an array [foriegnValues] to be displayed in the results() function.

* @param userDollarAmount -
* @param userChoices[] -
* @param foreignValues -
* @param Currency -
*/
double* currencyConverter(double &userDollarAmount, int userChoices[], double foreignValues[], Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
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

    for(int i = 0; i < 5; i++)
    {

        if(userChoices[i])
        {

            switch(userChoices[i])
            {
                case Mexican_Pesos:
                foreignValues[i] = mexicanPesos.amountOfCurrency;  
                break;

                case Japenese_Yen:
                foreignValues[i] = japeneseYen.amountOfCurrency;
                break;

                case Euros:
                foreignValues[i] = euros.amountOfCurrency;
                break;

                case Canadian_Dollar:
                foreignValues[i] = canadianDollar.amountOfCurrency;
                break;

                case Indian_Rupees:
                foreignValues[i] = indianRupees.amountOfCurrency;  
                break;

                case Belize_Dollar:
                foreignValues[i] = belizeDollar.amountOfCurrency;
                break;

                case CFP_Franc:
                foreignValues[i] = cfpFranc.amountOfCurrency;
                break;

                case Chinese_Yuan:
                foreignValues[i] = chineseYuan.amountOfCurrency;
                break;

                case Haitian_Gourde:
                foreignValues[i] = haitianGourde.amountOfCurrency;
                break;

                case Russian_Ruble:
                foreignValues[i] = russianRuble.amountOfCurrency;
                break;

            }
        }
    }

    return foreignValues;

}

/**
* TODO: FILL IN PARAMS!
* * string currencyAssignment()

* ? This function converts the [userChoices] into a switch case that stores the 'name of Currency' selected in an array [foreignTypes]
* ?      to be displayed in the results() function within the chart.

* @param userChoices[] -
* @param foreignTypes[] -
* @param Currency -
*/
string* currencyAssignment(int userChoices[], string foreignTypes[], Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble)
{
    for(int i = 0; i < 5; i++)
    {

        if(userChoices[i])
        {

            switch(userChoices[i])
            {
                case Mexican_Pesos:
                foreignTypes[i] = mexicanPesos.nameOfCurrency;  
                
                break;

                case Japenese_Yen:
                foreignTypes[i] = japeneseYen.nameOfCurrency;
                break;

                case Euros:
                foreignTypes[i] = euros.nameOfCurrency;
                break;

                case Canadian_Dollar:
                foreignTypes[i] = canadianDollar.nameOfCurrency;
                break;

                case Indian_Rupees:
                foreignTypes[i] = indianRupees.nameOfCurrency;  
                break;

                case Belize_Dollar:
                foreignTypes[i] = belizeDollar.nameOfCurrency;
                break;

                case CFP_Franc:
                foreignTypes[i] = cfpFranc.nameOfCurrency;
                break;

                case Chinese_Yuan:
                foreignTypes[i] = chineseYuan.nameOfCurrency;
                break;

                case Haitian_Gourde:
                foreignTypes[i] = haitianGourde.nameOfCurrency;
                break;

                case Russian_Ruble:
                foreignTypes[i] = russianRuble.nameOfCurrency;
                break;

            }
        }
    }
    return foreignTypes;
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

/**
* TODO: FILL IN PARAMS
* * void results()

* ? This function displays the results in a chart format (described in prd, prs, and center functions) by using a For-Loop
* ?      that will cycle through each decision by the user and display the categories until the 5 choices are displayed.

* @param userDollarAmount -
* @param foreignTypes[] -
* @param foreignValues[] -
* @param Currency -
*/
void results(double &userDollarAmount, string foreignTypes[], double foreignValues[], Currency &mexicanPesos, Currency &japeneseYen, Currency &euros, 
Currency &canadianDollar, Currency &indianRupees, Currency &belizeDollar, Currency &cfpFranc, Currency &chineseYuan,
Currency &haitianGourde, Currency &russianRuble)
{

    cout << endl << center("USD",10)       << " | "
         << center("FOREIGN TYPE",15)     << " | "
         << center("FOREIGN VALUE",18) << "\n";

    cout << std::string(10*4 + 2*4, '-') << "\n";

    for(int i = 0; i < 5; i++) 
    {
        cout   << prd(userDollarAmount,2,10) << " | "
               << prs(foreignTypes[i],15)    << " | "
               << prd(foreignValues[i],2,16) << "\n";
    }

    cout << endl;

}

/**
* * bool getEndProgram()

* ? This function asks the user if they would like to continue or end the program

* @param keepRunningProgram - the user's answer will be stored as a string variable to be compared in a loop that will determine their choice.
* @param runningProgram - this bool variable determines whether to keep the program running or not based on the user's input.
*/
bool getEndProgram (string keepRunningProgram, bool &runningProgram)
{
    cout << "Try Again (Y/n): ";
        cin >> keepRunningProgram;
        cout << endl;
        if(keepRunningProgram == "Y" || keepRunningProgram == "y")
        {
            runningProgram = true;
        }
        else 
        {
            runningProgram = false;
        }

    return runningProgram;
}

