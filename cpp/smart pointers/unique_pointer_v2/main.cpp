//http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <iostream>
#include <memory>

using namespace std;

struct Foo
{
  Foo()  {std::cout << "Foo::Foo\n";}
  ~Foo() {std::cout << "Foo::~Foo\n";}
  void bar() {std::cout << "Foo::bar\n";}
};

void f(const Foo &)
{
  std::cout << "f(const Foo&)\n";
}


int main()
{
  
  std::cout<< " init .... " << std::endl;

  std::unique_ptr<Foo> p1(new Foo); //pointer p1 onws Foo
  if(p1)
    p1->bar();
  
  //socped
  {
    std::unique_ptr<Foo> p2(std::move(p1)); // pointer p2 now owns Foo
    f(*p2);

    p1 = std::move(p2); // ownership returns to p1
    std::cout << "destroying p2 ...\n";
  }


  if(p1)
    p1->bar();

  //Foo instances is destroyed when p1 goes out of scope

  return 0;
}
