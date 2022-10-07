#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() 
{
    int startValue = 0, nextValue =1;
    int i, finalValue ,userInput,j;    
        cout<<"Enter the limit: ";    
        cin>> userInput;    
        for(i=1; i <= userInput; i++)    
        {    
            startValue = 0;    
            nextValue = 1;    
            cout << nextValue <<"\t";   
            for(j=1; j<i; j++)    
            {    
                finalValue = startValue + nextValue;    
            cout << finalValue << "\t";    
                startValue = nextValue;    
                nextValue = finalValue;  
            }    
            cout << "\n";    
        }    
    return 0;  
  
}