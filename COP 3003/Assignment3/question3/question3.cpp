/**
 * * Write a Program illustrating how the constructors are implemented and the 
 * * order in which they are called when the classes are inherited. Use three classes 
 * * named alpha, beta, gamma such that alpha, beta are base class and gamma is 
 * * derived class inheriting alpha & beta. 
*/

#include <iostream>
using namespace std;

//alpha class
class alpha
{
    //variable x declared
    int x;

public:
    //alpha constructor with an integer parameter
    alpha(int x)
    {
        //x initialized
        this->x = x;
        cout<<"alpha is initialized\n";
    }
    //display value of x
    void disp_x(void)
    {
        cout<<"x="<<x<<"\n";
    }
};

//beta class
class beta
{
    // y initialized
    double y;
public:
    //beta constructor with a floating parameter
    beta(float y)
    {
        this->y = y;
        cout<<"beta is initialized\n";
    }
    //display value of y
    void disp_y(void)
    {
        cout<<"y= "<<y<<"\n";
    }
};

// class gamma which derives alpha and beta class
class gamma : public alpha, public beta
{
    int m,n;
public:
    // gamma constructor
    gamma(int a, float b, int m, int n):
    //call the alpha and beta constructor with 'a' and 'b' parameters passed
            alpha(a), beta(b)
    {
        // initialize m and n
        this->m = m;
        this->n = n;
        cout<<"gamma is initialized\n";
    }

    // display values of m and n
    void disp_mn(void)
    {
        cout<<"m="<<m<<"\n";
        cout<<"n="<<n<<"\n";
    }
};

//main function
int main()
{
    // gamma called with parameters and 'g' is an object of gamma
    gamma newGamma(12, 3.6, 31, 27);

    //disp functions called to print value of x, y, m and n
    newGamma.disp_x();
    newGamma.disp_y();
    newGamma.disp_mn();
    return 0;
} 
