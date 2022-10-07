#include <cstdint>
#include <iostream> 
#include <string>

using namespace std;

int main ()
{
    // -- Intializing the temp values --
    float farhenheit;

    // -- Run the FOR LOOP from -100 to 100 
    for(float celsius = -100; celsius < 101; celsius++)
    {
        // -- Farhenheit conversion -- 
        farhenheit = ((9*celsius)/5) + 32;
        
        // -- Test the condition --
        if(farhenheit == celsius)
        {
            cout << "Farhenheit is equal to Celsius at: " << celsius << " degrees" << endl;
            break;
        }
        
    }
    return 0;
}