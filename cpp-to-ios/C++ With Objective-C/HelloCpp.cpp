

#include "HelloCpp.hpp"


HelloCpp::HelloCpp()
{
    cout << "Hello" << endl;
}

HelloCpp::~HelloCpp()
{
    cout << "~Hello" << endl;
}

void HelloCpp::print()
{
    cout << "Print class from HelloCpp" << endl;
}


string HelloCpp::getStringName()
{
    string str = "Hello world from c++!";
    return str;
}