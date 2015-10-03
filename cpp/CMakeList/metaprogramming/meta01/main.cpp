/* Examples from
 * https://monoinfinito.wordpress.com/series/introduction-to-c-template-metaprogramming/
 */

#include <iostream>


template <int N> struct Factorial{
  static const int result = N * Factorial<N-1>::result;
};

//specialization of template, in this recursive case
//is for stoping de loop
template <> struct Factorial<0>{
    static const int result = 1;
};

int main()
{
    std::cout << Factorial<5>::result << std::endl;
    return 0;
}

/*
 * NOTES FROM WEB SITE
 *
 * 1. Templates get evaluated on compile time, remember? That means all
 * that code actually executes when compiling the source, not when executing
 * the resulting binary (assuming it actually compiles, of course).
 * Having as a constraint the fact that all your code must resolve on compile
 * time means only const vars make sense.

 */

