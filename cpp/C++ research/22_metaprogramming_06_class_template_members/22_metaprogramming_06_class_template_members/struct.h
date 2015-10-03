#include <iostream>
#include <vector>

using namespace std;


template <typename T>
struct X
{
    enum E1 {a, b};
	int m1 = 7;
    static const int m3 = 10;
	T m2;

    X(const T& x):m2{x}{}

     void printT();

};

template <typename T>
void X<T>::printT()
{
    cout << m2 << endl;
}


