/*---------------------------------------------------------
 *    File: einstein.cpp
 *  Author: Danny Joseph
 *   Class: COP 2001, Spring 2022
 * Purpose: Convert any 3 Digit input into the result 1089
 * ---------------------------------------------------------*/

#include <iostream>

#include <string>

using namespace std;

int main()
{
    bool gameOver = false;

    // The Instructions..
    cout << "\nEnter a 3-digit number where the first and last digits differ by two or more: 541";
    cout << "\n541 -- 1) original";
    cout << "\n145 -- 2) reversed";
    cout << "\n396 -- 3) difference of #1 and #2";
    cout << "\n693 -- 4) reverse of #3";
    cout << "\n1089 - 5) sum #3 and #4\n";



    do
    {
        /*
            Step 1: Verify the Original Number follows these requirements.
            a.) Between the values of 100 and 999
            b.) The input value's first and last digit must differ by two or more.

            Once the requirements are met, the loop will end.
        */

        bool originalNumberVerified = false;
        int savedOriginalNumber = 0;

        do 
        {
            int originalNumber = 0;
            cout << "\nPlease Enter a 3 Digit Number: ";
            cin >> originalNumber;

            savedOriginalNumber = originalNumber;

            // Verify the original number is a 3 digit number

            if ((originalNumber < 100) || (originalNumber > 999))
            {
                cout << "\nYour number must be three digits!";
            }
            else
            {
                // Convert the integer value into separate array elements
                int originalNumberArray[3];
                for (int i = 2; i >= 0; i--)
                {
                    originalNumberArray[i] = originalNumber % 10;
                    originalNumber /= 10;
                }

                /*
                    Verify the first and third digit are more or less than 2
                    but comparing the first and last element of the array.
                    if ) break loop.
                    else ) Prompt error and start again
                */ 

                int checkOriginalNumberDifference = 0;

                checkOriginalNumberDifference = originalNumberArray[2] - originalNumberArray[0];

                if ((checkOriginalNumberDifference >= 2) || (checkOriginalNumberDifference <= -2))
                {

                    originalNumberVerified = true;

                }
                else
                {

                    cout << "\nFirst and third digit must differ by at least 2! Try again!" << endl;

                }

            }

        } while (!originalNumberVerified);


        
        /*
            Step 2: Reversing the original number.
            a.) Create a for loop that runs only till  every element of 'i' from the string is added to the new string.
            b.) Store each element of the original string in reverse order into the new string.
            c.) Convert this string into the new int variable 'reversedNumber'
        */

        std::string originalNumberString = std::to_string(savedOriginalNumber);
        std::string reverseNumberString = "";
        for (int i = originalNumberString.length() - 1; i >= 0; i--)
        {
            reverseNumberString += originalNumberString[i];
        }

        int reversedNumber = 0;
        reversedNumber = stoi(reverseNumberString);

        cout << "\n" << reversedNumber << "  -- 2) reversed";




        /*
            Step 3: Difference of Step 1 and Step 2.
            a.) Find the difference
            b.) Convert it into its absolute value.
        */ 

        int differenceResult = savedOriginalNumber - reversedNumber;

        cout << "\n" << abs(differenceResult) << "  -- 3) difference of #1 and #2";




        /*
           Step 4: Reversing the difference number.
           a.) Create a for loop that runs only till  every element of 'i' from the string is added to the new string.
           b.) Store each element of the original string in reverse order into the new string.
           c.) Convert this string into the new int variable 'reversedDifference'
           d.) Convert into its absolute value
       */

        std::string differenceString = std::to_string(differenceResult);

        std::string reversedDifferenceString = "";

        for (int i = differenceString.length() - 1; i >= 0; i--)
        {
            reversedDifferenceString += differenceString[i];
        }

        int reversedDifferenceValue = 0;

        reversedDifferenceValue = stoi(reversedDifferenceString);

        cout << "\n" << abs(reversedDifferenceValue) << "  -- 4) reverse of #3";



        // Step 5: Sum of Step 3 and Step 4
        int totalResult = 0;

        totalResult = abs(differenceResult) + abs(reversedDifferenceValue);

        cout << "\n" << abs(totalResult) << "  - 5) sum #3 and #4\n";



        // Try again?
        string tryAgain;

        cout << "\nWould you like to try another number (Y/N): ";

        cin >> tryAgain;


        // If players decides not to try again
        if ((tryAgain == "n") || (tryAgain == "N"))
        {
            gameOver = true;
        }


    } while (!gameOver);
        
    return 0;
}
