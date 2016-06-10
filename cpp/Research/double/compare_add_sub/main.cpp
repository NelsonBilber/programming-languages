// Tips for doubles --> http://www.codeproject.com/Articles/29637/Five-Tips-for-Floating-Point-Programming
// Examples from ->http://www.cygnus-software.com/papers/comparingfloats/Comparing%20floating%20point%20numbers.htm
// IEEE floating-points exceptions -> http://www.johndcook.com/blog/IEEE_exceptions_in_cpp/
// What Every Computer Scientist Should Know About Floating-Point Arithmetic  -> http://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html
// Examples of overflow and Underflow -> http://www.codeproject.com/Articles/25294/Avoiding-Overflow-Underflow-and-Loss-of-Precision
// resume -> https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

void test_equality()
{
	double x = 10;
	double y = sqrt(x);
	double tolerance = 0.005; //elipson value better approach

	y *= y;

	if(x == y) //floats problems
		std::cout <<"is equal" <<std::endl;
	else if (fabs(x-y) < tolerance)
	    std::cout <<"is equal with tolerance" <<std::endl;
	else
		std::cout << "not equal = " << (x-y) << std::endl;
}

void test_equality_epsilon()
{
	double x = 10;
	double y = sqrt(x);
	
	y *= y;

    bool check = std::fabs(x - y) <= std::numeric_limits<double>::epsilon();
	if (check)
	    std::cout <<"is equal with tolerance - epsilon" <<std::endl;
	else
		std::cout << "not equal = " << (x-y) << std::endl;
}

bool absoluteToleranceCompare(double x, double y)
{
    bool check = std::fabs(x - y) <= std::numeric_limits<double>::epsilon();
    return  check;
}

bool relativeToleranceCompare(double x, double y)
{
    double maxXY = std::max( std::fabs(x) , std::fabs(y) ) ;
    return std::fabs(x - y) <= std::numeric_limits<double>::epsilon()*maxXY ;
}

bool combinedToleranceCompare(double x, double y)
{
    double maxXYOne = std::max( { 1.0, std::fabs(x) , std::fabs(y) } ) ;
    return std::fabs(x - y) <= std::numeric_limits<double>::epsilon()*maxXYOne ;
}

void test_equality_multiple_tolerance()
{
    double x = 10;
    double y = sqrt(x);
   
    y *= y;
    
    if (absoluteToleranceCompare(x,y) == true)
        std::cout <<"is equal with tolerance - absoluteToleranceCompare" <<std::endl;
    else
        std::cout << "not equal - absoluteToleranceCompare = " << (x-y) << std::endl;
    
    
    if (relativeToleranceCompare(x,y))
        std::cout <<"is equal with tolerance - relativeToleranceCompare" <<std::endl;
    else
        std::cout << "not equal - relativeToleranceCompare = " << (x-y) << std::endl;
    
    
    if (combinedToleranceCompare(x,y))
        std::cout <<"is equal with tolerance - combinedToleranceCompare" <<std::endl;
    else
        std::cout << "not equal - combinedToleranceCompare = " << (x-y) << std::endl;
}

void addiction_and_subtraction()
{
    cout << std::setprecision(15);
	for(int i = 1; i < 20; i++)
	{
		double h = pow(10.0, -i);
		cout << (sin(1.0+h) - sin(1.0))/h << endl;
	}
	cout << "True result = " << cos(1.0) << endl;
}

void increment_floats()
{
	// 32 and 64 bit problems
	
	float f = 16777216; // 2^24
	cout << f << " " << f+1 << endl;

	double x = 9007199254740992; // 2^53
	cout << ((x+1) - x) << endl;
}

void increment_doubles()
{
    double x = 1.0;
    double y = x + 0.5 * std::numeric_limits<double>::epsilon();
    
    if(x == y)
        cout << "bump !" << endl;
}

void subtractionAdd()
{
    double x = 10.13;
    double y = 0.001;
    
    std::cout << " sub: " << y-x << std::endl;
    std::cout << " add:  " << y+x << std::endl;

}

int main(int argc, char *argv[])
{
	cout << "=> Equal " << endl;
	test_equality();	
	cout << "\n=> Equal - epsilon " << endl;
	test_equality_epsilon();
    cout << "\n=> Equal - multiple tolerance " << endl;
    test_equality_multiple_tolerance();
	cout << "\n=> Add and sub " << endl;
	addiction_and_subtraction();	
	cout << "\n=> Increments " << endl;
    increment_floats();
    increment_doubles();
    cout << "\n=> Sub and Add " << endl;
    subtractionAdd();
	
	return 0;
}
