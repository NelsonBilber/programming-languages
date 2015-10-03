// example from ::http://www.cprogramming.com/tutorial/function-pointers.html

#include <iostream>
#include <vector>
using namespace std;


void print_int(int x)
{
	cout << "function = " << x << std::endl;
}
int print_(long x, char c)
{
	cout << "function (long)= " << x <<" (char)= " << c << std::endl;
	return 1;
}

int main()
{
	void (*ptr)(int);
	ptr = &print_int;

	ptr(2);
	//or
	(*ptr)(4);

	int(*pptr)(long, char);
	pptr = &print_;
	
	std::cout << "seconf call = " << pptr((long)7.11, 'Z') << std::endl;	

	return 0;
}
