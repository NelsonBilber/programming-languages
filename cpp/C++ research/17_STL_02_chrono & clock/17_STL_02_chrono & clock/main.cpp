//http://www.cplusplus.com/reference/chrono/duration_cast/
//http://www.cplusplus.com/reference/chrono/system_clock/

// duration_cast
#include <iostream>     // std::cout
#include <chrono>       // std::chrono::seconds, std::chrono::milliseconds
                        // std::chrono::duration_cast
#include <chrono>
#include <ratio>

using namespace std;

int main ()
{
  std::chrono::seconds s (1);             // 1 second
  std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds> (s);

  ms += std::chrono::milliseconds(2500);  // 2500 millisecond

  s = std::chrono::duration_cast<std::chrono::seconds> (ms);   // truncated

  std::cout << "ms: " << ms.count() << std::endl;
  std::cout << "s: " << s.count() << std::endl;



  //--------------------------------------------------
  
  std::chrono::steady_clock::time_point t = std::chrono::steady_clock::now();
  for(int i = 0; i < 10000; i++)
	  cout << "print" << endl;
  auto d = std::chrono::steady_clock::now() - t;
  cout << "now = " <<  std::chrono::duration_cast<std::chrono::milliseconds> (d).count() <<" milliseconds"<< endl;

   //--------------------------------------------------

  using namespace std::chrono;
 
  typedef duration<int,std::ratio<60*60*24>> days_type;

  time_point<system_clock,days_type> today = time_point_cast<days_type>(system_clock::now());

  std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;

    
  return 0;
}

/*

System clock
Clock classes provide access to the current time_point.
Specifically, system_clock is a system-wide realtime clock.


Steady clock
Clock classes provide access to the current time_point.
steady_clock is specifically designed to calculate time intervals.

Time point
A time_point object expresses a point in time relative to a clock's epoch.
Internally, the object stores an object of a duration type, and uses the Clock type as a reference for its epoch.



* From Book The C++ programming language

clocks types:
...............
system_clock: system's real-time clock
steady_clock: a clock where time moves steadly forward and the tick is constant
high_resolution_clock: a clock with the shortest time increment on a system
*/


