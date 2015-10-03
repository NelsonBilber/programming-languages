// void* a generic pointer

#include <iostream>

using namespace std;


struct MyStruct
{
	double sd;
};

int main(int argc, char *argv[])
{
	int i = 10;
	int* ptr = &i;
	
	void* vprt;
	vprt = ptr;

	std::cout << " void* = " << *(static_cast<int*>(vprt)) <<std::endl;

	double d = 10.11;
	double * dptr = &d;

	vprt = dptr;
	std::cout << " void* = " << *(static_cast<double*>(vprt)) <<std::endl;

	MyStruct* s = new MyStruct;
	s->sd = 99.99;
	
	vprt = s;
	std::cout << " void* = " << (static_cast<MyStruct*>(s))->sd <<std::endl;

	return 0;
}

















