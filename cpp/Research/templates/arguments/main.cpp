//http://en.cppreference.com/w/cpp/language/template_specialization
// from:: https://msdn.microsoft.com/en-us/library/c401y1kb.aspx

#include <iostream>

using namespace std;

//passing arguments
template< typename T, int max>
class Buffer
{
	T v[max];
public:
	Buffer(){}

};

//passing arguments with default values
template<typename T1 = int, typename T2 = double>
class Default
{
	
};


template<class T, size_t N>
size_t size(T (&)[N]) { return N; }

//specialization
// the order matters

// Template class declaration and definition
template <class T>
class Formatter
{
    T* m_t;
public:
    Formatter(T* t) : m_t(t) { }
    void print()
    {
        cout << *m_t << endl;
    }
};

// Specialization of template class for type char*
template<>
class Formatter<char*>
{
    char** m_t;
public:
    Formatter(char** t) : m_t(t) { }
    void print()
    {
        cout << "Char value: " << **m_t << endl;
    }
};


int main()
{

    Buffer<int, 10> b;
    int a[] {1,2,3,5,3};

    std::cout<<"template has " << size(a) << " elements " <<std::endl;

    Default<float> f; //creates a <float, double> replaces default value and uses the default for second parameter
    Default<float, float> ff;


    // specialization 

    int i = 157;
    // Use the generic template with int as the argument.
    Formatter<int> formatter1(&i);

    char str[10] = "string1";
    char* str1 = str;
    // Use the specialized template.
    Formatter<char*> formatter2(&str1);

    formatter1.print(); // 157
    formatter2.print(); // Char value : s

    return 0;
}
