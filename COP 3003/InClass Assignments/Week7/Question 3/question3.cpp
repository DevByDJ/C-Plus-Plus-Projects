/*
* Write a C++ Program to show counter using Constructor
**/

#include <iostream>

using namespace std;

class Counter 
{
    public:

    int count;

    Counter()
    {
        count++;

        cout << endl << "Current count: " << count << endl;
    }
};

int main()
{
    Counter newCounter;

    return 0;
}