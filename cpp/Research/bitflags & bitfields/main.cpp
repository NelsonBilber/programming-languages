// Example of using bitfields or bitflags


#include <iostream>
#include <memory>

using namespace std;

enum Options{
  OPT_1 = 0x01,
  OPT_2 = 0x02,
  OPT_3 = 0x04,
  OPT_4 = 0x08,
  OPT_5 = 0x10,
  OPT_6 = 0x20
};


int main(int argc, char *argv[])
{

  unsigned char options;

  std::cout << "Set flag values " << std::endl;

  options = OPT_1 | OPT_5;

  std::cout << "Check if is assigned " << std::endl;

  if(options & OPT_1){
    std::cout << "OPTION 1 is assigned " << std::endl;
  }
  
  if(options & OPT_2){
    std::cout << "OPTION 2 is assigned " << std::endl;
  }

  if(options & OPT_3){
    std::cout << "OPTION 3 is assigned " << std::endl;
  }
 
  if(options & OPT_4){
    std::cout << "OPTION 4 is assigned " << std::endl;
  }
 
  if(options & OPT_5){
    std::cout << "OPTION 5 is assigned " << std::endl;
  }
  
  return 0;
}
