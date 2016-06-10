// http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c
// http://en.cppreference.com/w/cpp/language/reference
// http://thbecker.net/articles/rvalue_references/section_01.html
// http://msdn.microsoft.com/en-us/library/f90831hc.aspx
// great video --> https://www.youtube.com/watch?v=UTUdhjzws5g

#include <iostream>
#include <string>
using namespace std;

/*
An lvalue (locator value) represents an object that occupies some identifiable location in memory (i.e. has an address).
rvalues are defined by exclusion, by saying that every expression is either an lvalue or an rvalue. Therefore, from the above definition of lvalue, an rvalue is an expression that does not represent an object occupying some identifiable location in memory.
 */




int global_var = 20;



//int& foor() { return 2;} //rvalue
int& foo()
{
  return global_var;
} //turns a reference, which is an lvalue, so it can be assigned to

void f(int& x)
{
     std::cout << "lvalue reference overload f(" << x << ")\n";
}
void f(const int& x)
{
     std::cout << "lvalue reference to const overload f(" << x << ")\n";
}
void f(int&& x)
{
     std::cout << "rvalue reference overload f(" << x << ")\n";
}


int main(int argc, char *argv[])
{
  int var;
  var = 4; // var is a lvalue

  foo() = 10;

  int a = 1;     // a is an lvalue
  int b = 2;     // b is an lvalue
  int c = a + b; // + needs rvalues, so a and b are converted to rvalues
                  // and an rvalue is returned

  int arr[] = {1, 2};
  int* p = &arr[0];
  *(p + 1) = 10;   // OK: p + 1 is an rvalue, but *(p + 1) is an lvalue

  int var2 = 10;
  //int* bad_addr = &(var2 + 1); // ERROR: lvalue required as unary '&' operand
                                 //error: cannot take the address of an rvalue of type 'int'

  int* addr = &var2;           // OK: var is an lvalue
  //&var2 = 40;                // ERROR: lvalue required as left operand of assignment

 
  std::string s1 = "test";
  //  std::string&& ss1 = s1; //// error: can't bind to lvalue
  const std::string& r2 = s1 + s1; // OK, lvalue ref to const extends lifetime
  // r2 += "Test"; // error: can't modify through reference to const
 
   std::string&& r3 = s1 + s1; // OK, rvalue ref extends lifetime
   r3 += "Test"; // this object can be modified
   std::cout << r3 << '\n';

   int n = 1;
   const int x = 2;
   f(n); // calls f(int&)
   f(x); // calls f(const int&)
   f(3); // calls f(int&&)
         // would call f(const int&) if f(int&&) overload wasn't provided

   // ===================================================================================
   // Microsoft - http://msdn.microsoft.com/en-us/library/f90831hc.aspx
   /*
    An lvalue refers to an object that persists beyond a single expression.
    An rvalue is a temporary value that does not persist beyond the expression that uses it
    */
   int xx = 3 + 4;
   cout << xx << endl;
   /*
     xx is an lvalue because it persists beyond the expression that defines it. 
     The expression 3 + 4 is an rvalue because it evaluates to a temporary value that does not persist beyond the expression that defines it.
   */
   // ===================================================================================   
   
  return 0;
}










/* ========================================================================
 
  // lvalues:
  //
  int i = 42;
  i = 43; // ok, i is an lvalue
  int* p = &i; // ok, i is an lvalue
  int& foo();
  foo() = 42; // ok, foo() is an lvalue
  int* p1 = &foo(); // ok, foo() is an lvalue

  // rvalues:
  //
  int foobar();
  int j = 0;
  j = foobar(); // ok, foobar() is an rvalue
  int* p2 = &foobar(); // error, cannot take the address of an rvalue
  j = 42; // ok, 42 is an rvalue


  ======================================================================= */
