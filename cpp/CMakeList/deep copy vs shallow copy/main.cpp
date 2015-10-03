// Example of using deep copy vs shallow copy
// A Good explanation about this http://www.learncpp.com/cpp-tutorial/912-shallow-vs-deep-copying/


#include <iostream>
#include <memory>

using namespace std;

class MyString
{
private:
	char* m_pchString;
	int m_Length;

public:
	MyString(char* pchString="")
	{
		m_Length = strlen(pchString)+1;
		m_pchString = new char[m_Length];

		strncpy(m_pchString, pchString, m_Length);
		m_pchString[m_Length] = '\0';
	}

	~MyString()
	{
		delete [] m_pchString;
		m_pchString = 0;
	}

	//deep copy
	//copy operator
	MyString(const MyString& cSource)
	{
		std::cout <<"copy constructor ... "<<std::endl;
		m_Length = cSource.m_Length; //shallow copy - native type

		//deep copy of a pointer
		if(cSource.m_Length)
		{
			m_pchString = new char [m_Length];
			strncpy(m_pchString, cSource.m_pchString, m_Length);
		}
		else
		{
			m_pchString = 0;
		}
	}

	//deep copy
	//assign operator
	MyString& operator=(const MyString& cSource)
	{
		std::cout<<"overload assign operator = ...."<<std::endl;
		if(this == &cSource)
		{
			std::cout <<"self-assignment"<<std::endl;
			return *this;
		}

		delete [] m_pchString;

		if(cSource.m_pchString)
		{
			m_pchString = new char [m_Length];
			strncpy(m_pchString, cSource.m_pchString, m_Length);
		}
		else
		{
			m_pchString = 0;
		}

		return *this;
	}

	
	char* Getstring() { return m_pchString; }
	int GetLength()   { return m_Length;    }
};



void shallow_deep_copy()
{
	char* Source = "copy of a copy";
	char* shallow_copy = Source;
	char* deep_copy = new char(strlen(Source +1));

	strcpy(deep_copy, Source);

	std::cout << "address original     = " << &Source << std::endl;
	std::cout << "address shallow copy = " << &shallow_copy << std::endl;
	std::cout << "address deep copy    = " << &deep_copy << std::endl;
}


int main(int argc, char *argv[])
{
	shallow_deep_copy();

	/*
	MyString  cHello("Hello, world!");
	{
		MyString cCopy = cHello; // default copy ctor
	}
	*/

	//Problems because out of scope, c++ uses by default 
	//shallow copies the address of the pointers and point
	//to the same memory, when it goes out of scope it delete
	//from both vars, so it will crash
	//std::cout << cHello.Getstring() << std::endl;

	MyString  c2Hello("Hello, world!");
	c2Hello = c2Hello;
	{
		MyString cCopy = c2Hello; // default copy ctor
		MyString ccCopy;
		ccCopy = c2Hello;
	}
	std::cout<< c2Hello.Getstring() <<std::endl;
	
	return 0;
}
