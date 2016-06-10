#include <iostream>
#include <exception>
#include <string>
#include "struct.h"
#include "struct.cpp"
#include "scalar.h"

using namespace std;

//function templates
template <typename T>
void mysort(vector<T>& v )
{
    //do your stuff
    // shell sort (Knuth, vol. 3 pg 84)
    const size_t n = v.size();

    for(int gap = n/2; 0 < gap; gap /=2 ) {
        for(int i = gap; i < n; i++) {
            for(int j = i - gap; 0 <=j; j-=gap ) {
                if(v[j+gap] < v[j]) {
                    T temp = v[j];
                    v[j] = v[j+gap];
                    v[j+gap] = temp;
                }
            }
        }
    }
}

int main()
{
	X<int> xi{9};
	X<string> xs{"test"};

	xi.printT();
    xs.printT();

    Complex<float> cf;
    Complex<double> cd {cf};
    //Complex<float> cf2 {cd}; //no implicit convertion from double->float conversion
    Complex<double> cf3 {2.0F, 3.0F}; // uses float to double convertion

    //using template functions

    vector<int> v {1, 5, 2,10,8};
    mysort(v);

    for(auto x: v )
        cout << x << endl;

	return 0;
}
