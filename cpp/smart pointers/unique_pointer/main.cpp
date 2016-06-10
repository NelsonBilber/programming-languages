//http://msdn.microsoft.com/en-us/library/hh279674.aspx

#include <iostream>
#include <memory>

using namespace std;

class LargeObject
{
public: 
  void  DoSomething(){}
};


void ProcessLargeObject(const LargeObject& lo){}

void SmartPointerDemo()
{
  std::unique_ptr<LargeObject> pLarge(new LargeObject);

  pLarge->DoSomething();

   // Pass a reference to a method.
  ProcessLargeObject(*pLarge);

}// //pLarge is deleted automatically when function block goes out of scope.

int main()
{
  SmartPointerDemo();
  return 0;
}
