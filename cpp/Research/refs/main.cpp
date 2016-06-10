#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int i = 42;
  int& j = i;
  int* iptr = &i;

  long l = 142;
  long& lref = l;
  long* lptr = &l;

  std::cout << "=>int" <<std::endl;
  std::cout << "i = " << i <<" ref = " << &i  << " sizeof = " << sizeof(i) << std::endl; 
  std::cout << "j = " << i <<" ref = " << &j  << " sizeof = " << sizeof(&j) << std::endl;
  std::cout << "*iptr = " << iptr <<" ref = " << &iptr  << " sizeof = " << sizeof(&iptr) << std::endl;
  std::cout << "=>double"<<std::endl;
  std::cout << "l = " << l <<" l = " << &l  << " sizeof = " << sizeof(l) << std::endl; 
  std::cout << "lref = " << lref <<" lref = " << &lref  << " sizeof = " << sizeof(&lref) << std::endl;
  std::cout << "*lptr = " << lptr <<" lprt = " << &lptr  << " sizeof = " << sizeof(&lptr) << std::endl;

  return 0;
}
