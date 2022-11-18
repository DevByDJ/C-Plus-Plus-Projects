/**
 * *Write a program to find the shapes using Function overloading. 
*/

#include<iostream>
using namespace std;

void area(int area)
{
    int square=area*area;
    cout<<"The Area Of Square Value is:"<<square<<endl;
}

void area(int length,int width)
{
    int rectangle=length*width;
    cout<<" The Area Of The Rectangle Value is:"<<rectangle<<endl;
}

void area(float radius)
{
    float circle=2.34*radius*radius;
    cout<<"The Area of The Circle Value is:"<<circle<<endl;
}

void area (float length,float height)
{
    float triangle=0.4*length*height;
    cout<<" The Area Of the triangle value is:"<<triangle<<endl;
}

int main()
{
    int a,w,l;
    float r,le,height;

    cout<<"___________"<<endl;
    cout<<"AREA OF SHAPES USING FUNCTION OVERLOADING"<<endl;
    cout<<"___"<<endl;
    cout<<"Enter one value for Square:";
    cin>>a;
    cout<<endl;
    cout<<"Enter two value for Rectangle:";
    cin>>w>>l;
    cout<<endl;
    cout<<"Enter one value for Circle:";
    cin>>r;
    cout<<endl;
    cout<<"Enter two values for triangle:";
    cin>>le>>height;
    cout<<endl;
    cout<<"____"<<endl;

    area(a);
    area(l,w);
    area(r);
    area(le,height);


    cout<<"_____"<<endl;

    return 0;

}