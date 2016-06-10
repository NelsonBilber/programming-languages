#include <iostream>
#include <exception>
#include <string>

using namespace std;


template <typename C>
class String
{
public:
	String(const C* ch): sz{0}, ptr{ch}
	{
	}

	void print () { cout << ptr  << endl; }

private:
	static const int short_max = 15;
	int sz;
	const C* ptr;
};


int main()
{
	String <char> tc ("teste");
	tc.print();

	int i = 100;
	const int* iptr = &i;
	String <int> ti (iptr);
	ti.print();

	using UChar =   wchar_t ;
	const UChar* x = (UChar*)("test big");
	String <UChar> tuc (x);
	tuc.print();
	
	return 0;
}
