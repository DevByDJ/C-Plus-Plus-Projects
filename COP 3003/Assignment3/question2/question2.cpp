#include<iostream>
using namespace std;

class fibonacci
{
    long int initialValue, nextValue; //data members
    public:
    fibonacci() //special member function constructor
    {
        initialValue=-1;
        nextValue=1;
       
    }

    void fibseries(int n) //member function
    {
        int i,current;
        cout<<"\n Resultant fibonacci series";
        cout<<"\n-----------------------------\n";
        for(i=0;i<n;i++)
        {
            current=initialValue+nextValue; //Expression
            cout<<current<<endl; //To print the fibseries
            initialValue=nextValue;
            nextValue=current;
        }
   
    }
};


int main()
{
    fibonacci f;
    int n;
    cout<<"\n Fibonacci series \n";
    cout<<"\n Enter the range = \n";
    cin>>n;
    f.fibseries(n); //Accessing the members l function fibseries () using Dot (.) operator
    return 0;
}