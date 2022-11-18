/**
 * *Write a Program to design a class having static member function named
 * *showcount() which has the property of displaying the number of objects
 * *created of the class. 
*/

#include <iostream>
using namespace std;
class test {

	int amountOfObjects;
	static int objectCounter;

  public:
    test()
    {
    amountOfObjects = ++objectCounter;
    }
    ~test()
    {
    --objectCounter;
    }
    void printObjectAmount(void)
    {
      cout << "object number :" << amountOfObjects << "\n";
    }
    static void printCounterAmount(void)
    {
      cout << "count:" << objectCounter<< "\n";
    }
};

int test::objectCounter;

int main()
{
	test testOne, testTwo;
	test::printCounterAmount();

	test testThree;
	test::printCounterAmount();

	testOne.printObjectAmount();
	testTwo.printObjectAmount();
	testThree.printObjectAmount();
	return 0;
}
