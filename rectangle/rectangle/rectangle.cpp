/* --------------------------------------------------------
 *    file: rectangle.cpp
 *   class: COP 2006
 *  author:
 * purpose: debugging lab
 * -------------------------------------------------------- */
#include <iostream>

using namespace std;

// constants
// --------------------------------------------------------

// types
// --------------------------------------------------------
// point structure to hold an (X,Y) coordinate
struct Point
{
    float x;
    float y;
};

// rectangle structure defined by a lower-left point
// and an upper-right point
struct Rectangle
{
    Point lowerLeft;
    Point upperRight;
};


// function prototypes
// --------------------------------------------------------
Point getPoint();
Rectangle getRectangle();
void printPoint(Point point);
void printRectangle(Rectangle rectangle);
bool isInside(Rectangle rectangle, Point point);


// function definitions
// --------------------------------------------------------
int main() {

    // call getRectangle to initialize the rectangle variable
    Rectangle theRectangle;
    theRectangle = getRectangle();

    // print the rectangle

    bool done;
    do {

        // prompt the user to enter the checked point
        // and call the getPoint method to get a user provided
        // Point and assign it the point variable below
        cout << "Enter point to check:" << endl;
        Point thePoint;
        thePoint = getPoint();

        // print the point, and determine if it is inside
        // the rectangle by calling isInside(), and then
        // output the appropriate message
        isInside(theRectangle, thePoint);

        printPoint(thePoint);


        char again;
        cout << "Try again Y/N: ";
        cin >> again;
        done = !(again == 'Y' || again == 'y');

    } while (!done);

    return 0;
}


/**
 * prompt user to enter two floats for X,Y coordinates
 * @return - a populated point structure
 */
Point getPoint()
{
    Point retPoint = { 0.0, 0.0 };

    // prompt for and assign user input to the X,Y of the return point
    float x;
    cin >> x;
    float y;
    cin >> y;

    retPoint = { x, y };

    return retPoint;
}


/**
 * prompt user to enter two points to define a rectangle
 * @return a populated rectangle structure
 */
Rectangle getRectangle()
{
    Rectangle retRectangle = { {0.0, 0.0}, {0.0, 0.0} };

    // prompt for and assign the lower-left point to the return rectangle
    Point lowerLeft = getPoint();

    // prompt for and assign the upper-right point to the return rectangle
    Point upperRight = getPoint();

    retRectangle = { {lowerLeft},{upperRight} };

    return retRectangle;
}


/**
 * print a point X,Y coordinate to the console
 * @param point the point to print
 */
void printPoint(Point point)
{
    // output the point formatted (X,Y)


}


/**
 * print the two defining points of a rectangle to the console
 * @param rectangle the rectangle to print
 */
void printRectangle(Rectangle rectangle)
{
    cout << "Rectangle [";
    // call printPoint to output the lower-left point

    cout << ", ";
    // call printPoint to output the upper-right point

    cout << "]" << endl;
}


/**
 * check if a point is located inside a rectangle
 * @param rectangle defined by lower-left and upper-right points
 * @param point the X,Y coordinate to check
 * @return true if point is located inside the rectangle
 */
bool isInside(Rectangle rectangle, Point point)
{
    // define bool variables for each of the logical expressions
    //  in the return statement below, so you can step
    // through them to see the result of each operation
    // and better determine why this function may not be working.

    return ((point.x <= rectangle.upperRight.x &&
        point.y <= rectangle.upperRight.y) ||
        (point.x >= rectangle.lowerLeft.x &&
            point.y >= rectangle.lowerLeft.y));
}
