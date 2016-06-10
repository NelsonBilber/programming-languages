// Weak Pointer
//http://en.cppreference.com/w/cpp/memory/weak_ptr


#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void f()
{
   // Has to be copied into a shared_ptr before usage
   if (auto spt = gw.lock())
   { 
     std::cout << *spt<< std::endl;
   }
   else
   {
     std::cout << "gw is expired\n";
   }
}

 
int main()
{
  {
    auto sp = std::make_shared<int>(42);
     gw=sp; 
     f();
  }
  
  f();
  
  return 0;
}
