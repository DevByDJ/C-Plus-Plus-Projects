/*
* Write a program to find the volume of a rectangle using constructor 
? (with and without passing parameters).
**/

#include <iostream>
#include <cstring>

using namespace std;

class RectangleWithoutParam
{
    public:

    double length, width, height;

    RectangleWithoutParam()
    {
        double result;

        // Title Screen
        cout << endl << "======= Volume Calc without Parameters =======";


        getLength();
        getWidth();
        getHeight();

        result = length * width * height;

        cout << endl << "The Volume is " << result << " square ft." << endl;

        // End Screen
        cout << endl << "======= Volume Calc without Parameters =======" << endl;

    }

    void getLength()
    {
        cout << endl << "Enter Length: " ;
        cin >> length;
    }

    void getWidth()
    {
        cout << endl << "Enter Width: " ;
        cin >> width;
    }

    void getHeight()
    {
        cout << endl << "Enter Height: " ;
        cin >> height;
    }


};

class RectangleWithParam
{
    public:

    RectangleWithParam(double length, double width, double height)
    {
        double result;

        result = length * width * height;

        cout << endl << "The Volume is " << result << " square ft." << endl;


    }

};

int main()
{
    // Variable Declaration
    double length, width, height;

    // Title Screen
    cout << endl << "======= Volume Calc with Parameters =======";

    // Set Values
    cout << endl << "Enter Length: " ;
    cin >> length;

    cout << endl << "Enter Width: " ;
    cin >> width;

    cout << endl << "Enter Height: " ;
    cin >> height;

    // Pass Values through contructor
    RectangleWithParam rectWithParam(length, width, height);

    // End Screen
    cout << endl << "======= Volume Calc with Parameters =======" << endl;

    RectangleWithoutParam rectWithoutParam;

    return 0;

}