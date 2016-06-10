// used examples from : http://en.cppreference.com/w/cpp/language/static_cast
//                      http://en.cppreference.com/w/cpp/language/reinterpret_cast
//                      http://en.cppreference.com/w/cpp/language/dynamic_cast
#include <iostream>
#include <vector>
#include <cstdint>
#include <cassert>

using namespace std;

struct Base {
	void print() { std::cout <<"Base"<<std::endl;}
};

struct Derived: Base {
	void print() { std::cout <<"Derived"<<std::endl;}
};


class CBase{
	virtual void poly() {};  // must be polymorphic to use runtime-checked dynamic_cast	

};
class CDerived : public CBase{};

enum class EnumClass{ ONE, TWO, THREE};
enum EnumNormal {ONE, TWO, THREE};

void const_cast_test()
{
	const int value = 33;
	int alternative_value = 22;
	//removes const_cast
	const int* pConstCast = &value;
	//*pConstCast = 4; // read-only
	std::cout <<"pConstCast = " << *pConstCast  << std::endl;
	int* ppConstCast = const_cast<int *>(pConstCast);
	*ppConstCast = 4;
	std::cout <<"pConstCast = " << *pConstCast << " ppConstCast =" << *ppConstCast << std::endl;
}


int f() {return 42;}

void static_cast_test()
{
	double pi = 3.14;
	int ipi = static_cast<int>(pi);
	std::cout <<"double = "<< pi << " int = " << ipi <<std::endl;
	std::vector<int> v = static_cast<std::vector<int>>(10);
	std::cout << "v.size() = " << v.size() << '\n';

	// static downcast
	Derived d;
	Base& base = d; //upcast via implicit conversion
	Derived dd = static_cast<Derived&>(base); //downcast (base-to-derived)
	base.print();
	dd.print();

	// lvalue to xvalue
	std::vector<int> v2 = static_cast<std::vector<int>&&>(v);
	std::cout<< "after move, v.size()= " << v.size() << std::endl;

	//discard-value expression
	static_cast<void>(v2.size());

	//array-to-pointer followed by upcast
	Derived a[10];
	Base *dp = static_cast<Base*>(a); // upcast (derived-to-base)
	dp->print();

	EnumNormal e1 = EnumNormal::THREE;
	int two = static_cast<int>(e1);
	std::cout <<"Enum cast = "<< two <<std::endl;

	//enum class to enum
	EnumNormal en = static_cast<EnumNormal>(e1);
	EnumClass ec = static_cast<EnumClass>(en);
	std::cout <<"Enum normal cast = "<< static_cast<int>(ec) <<std::endl;

	//void* to any type
	void* voidptr = &e1;
	std::vector<int>* ppp = static_cast<std::vector<int>*>(voidptr);
	std::cout << "ppp->size() = " <<ppp->size() << '\n';
}

void reinterpret_cast_test()
{
    char x = 'b';
	//int* p1 = &x; // cannot initialize a variable of  type 'int *' with an rvalue of type 'char *'
	int* pp1 = reinterpret_cast<int *>(&x);
	std::cout << *pp1 << std::endl; 

	int i = 7;
	// pointer to integer and back
	uintptr_t v1 = reinterpret_cast<uintptr_t>(&i); // static_cast is an error
	std::cout << "The value of &i is 0x" << std::hex << v1 << '\n';
	int* p1 = reinterpret_cast<int*>(v1);
	assert(p1 == &i);

	// pointer to function to another and back
	void(*fp1)() = reinterpret_cast<void(*)()>(f);
	// fp1(); undefined behavior
	int(*fp2)() = reinterpret_cast<int(*)()>(fp1);
	std::cout << std::dec << fp2() << '\n'; // safe

	// type aliasing through pointer
	char* p2 = reinterpret_cast<char*>(&i);
	if(p2[0] == '\x7')
		std::cout << "This system is little-endian\n";
	else
		std::cout << "This system is big-endian\n";

	// type aliasing through reference
	reinterpret_cast<unsigned int&>(i) = 42;
	std::cout << i << '\n';
}


void dynamic_cast_test()
{
	CDerived d;
	CBase& b = d;
	CDerived& dd = dynamic_cast<CDerived&>(b); //runtime-checked dynamic_cast

	CBase* b1 = new CBase;
	if(CDerived * d = dynamic_cast<CDerived*>(b1)) {
		std::cout <<"downcast from b1 ok  "<<std::endl;
	} else {
		std::cout <<"erro from cast 1  "<<std::endl;
	}
	
	CBase* bb2 = new CDerived;
	if(CDerived* d = dynamic_cast<CDerived*>(bb2)) {
		std::cout <<"downcast from bb2 ok  "<<std::endl;
	} else {
		std::cout <<"erro from cast 2  "<<std::endl;
	}

	delete b1;
	delete bb2;
}

void implicit_conversions()
{
	double pi = 3.14;
	int value = (int)pi;

	std::cout << value <<std::endl;
}

int main(int argc, char *argv[])
{
	const_cast_test();
	static_cast_test();
	reinterpret_cast_test();
	dynamic_cast_test();
	implicit_conversions();
	return 0;
}
