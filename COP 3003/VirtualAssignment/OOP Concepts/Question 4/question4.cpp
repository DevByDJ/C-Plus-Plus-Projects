/*
* Write a C++ program to display time in HH: MM: SS using class.
? Hint:     02 hours:34 minutes:26 seconds.
**/

#include <iostream>
#include <ctime>

using namespace std;

class Clock
{
  public:

  // -- Grabs the current time set by the local computer --
  void getTime()
  {
    // -- time_t is a defined class created within <ctime>  --
    time_t curr_time;
    curr_time = time(NULL);

    // -- sets current time to the local time set on the computer --
    tm *tm_local = localtime(&curr_time);

    // -- OUTPUT --
    cout << "Current local time : " << tm_local->tm_hour << ":" << tm_local->tm_min << ":" << tm_local->tm_sec << endl;
  };

};

int main()
{
  // -- Class object declaration --
  Clock clock;
  
  clock.getTime();

	return 0;
}

