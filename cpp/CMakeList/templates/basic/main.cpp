#include <iostream>
#include <exception>

using namespace std;


template <typename T>
class MyTemplate
{
public:
	MyTemplate(int size)
	{
		if(size > 0 )
		{
			elem = new T[size];
			mysize = size;
		}
		else
		{
				std::cout << "size can't be inferior to zero." << std::endl;
		}
	}
	~MyTemplate()
	{
		delete[] elem;
	}

	T* begin(MyTemplate<T>& x)
	{
		return &x[0];
	}

	T *end(MyTemplate<T>& x)
	{
		return x.begin()+ x.size();
	}

	inline int size_container() { return mysize; }

	void print()
	{

		for( int i = 0 ; i <  mysize; i++)
		{
			std::cout << "i = "<< i  << " elem = "<< elem[i] << std::endl;
		}
	}

private:
	T* elem;
	int mysize;
};

int main()
{
	MyTemplate<char> vc(200);
	MyTemplate<string> vs(77);
	MyTemplate<int> vi(399);

	std::cout<<"template has " << vs.size_container() << " elements " <<std::endl;
	vs.print();

	return 0;
}
