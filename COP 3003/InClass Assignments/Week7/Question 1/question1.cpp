/*
* Question 1:
* Write an object-oriented C++ program to create a class for room and three objects to calculate the area and volume of three rooms. 
? Use public access specifier and methods for calculations.
**/

#include <iostream>

using namespace std;

class Room 
{
    public:
        double length, width, height;

        void getArea() {
            double area;

            area = length * width;

            cout << "The area for this room is " << area << " feet" << endl;
            
        };

        void getVolume() {
            double volume;

            volume = length * width * height;

            cout << "The volume for this room is " << volume << " feet" << endl;

        };

};


int main () 
{

    Room bedRoom, classRoom, diningRoom;

    bedRoom.width = 10.5;
    bedRoom.height = 12.2;
    bedRoom.length = 8.8;

    classRoom.width = 12.3;
    classRoom.height = 11.4;
    classRoom.length = 15.9;

    diningRoom.width = 13.3;
    diningRoom.height = 10.1;
    diningRoom.length = 7.8;

    bedRoom.getArea();
    bedRoom.getVolume();

    classRoom.getArea();
    classRoom.getVolume();

    diningRoom. getArea();
    diningRoom.getVolume();    


    return 0;

}   