//lifting : generalizing an algorithm
//concepts: requirements that can be used by n templates and n types arguments
//axioms: something we can't prove so we assume it's true
#include <iostream>
using namespace std;

template <typename Iter, typename Val>
Val sum(Iter first, Iter last )
{
	Val res = 0;
	while(first != last)
	{
		res += *first;
		++first;
	}
	return res;
}

int main()
{
	double v[] = {1,2,4,5};
	double res = sum <double*>(v,v+4);

	cout << "result = " << res << endl;

	return 0;
}
