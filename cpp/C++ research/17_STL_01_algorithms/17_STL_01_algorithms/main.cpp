//http://www.cplusplus.com/reference/algorithm/sort/
//http://en.cppreference.com/w/cpp/algorithm/equal
//http://en.cppreference.com/w/cpp/algorithm/mismatch
//http://en.cppreference.com/w/cpp/algorithm/copy
//http://www.cplusplus.com/reference/algorithm/fill/
//http://en.cppreference.com/w/cpp/algorithm/swap
//http://www.cplusplus.com/reference/algorithm/remove/
//http://en.cppreference.com/w/cpp/algorithm/binary_search
//http://www.cplusplus.com/reference/algorithm/merge/
//http://www.cplusplus.com/reference/algorithm/lexicographical_compare/

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <string>
#include <iterator>
#include <numeric>
#include <cctype>

using namespace std;


/* --------------- min max ---------------------------*/

void stl_min_max()
{
	cout << "max (1,3) = " << max(1,3) << endl;
	cout << "max ('a','z') = " << max('a','z') << endl;
	cout << "min (1,3) = " << min(1,3) << endl;
	cout << "min ('a','z') = " << min('a','z') << endl;
}

/* --------------- lexical compare -------------------*/

// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

void stl_lexicographical_compare()
{
	char foo[]="Apple";
	char bar[]="apartment";
	
	std::cout << std::boolalpha;
	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";
	std::cout << "Using default comparison (operator<): ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';
	std::cout << "Using mycomp as comparison object: ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	std::cout << '\n';	
}

/* --------------- sorting and searching  -------------*/


void stl_binary_search()
{
	vector<int> haystack{1,3,4,5,9};
	vector<int> needles {1,2,3};

	for(auto needle: needles){
		cout << "search for = " << needle << endl;
		if(std::binary_search(haystack.begin(), haystack.end(), needle)){
			cout << " Found " << needle << endl;
		} else {
			cout << "nop " << endl;
		}
	}
}


void stl_merge()
{
	int first [] = {5, 10, 15, 20, 25};
	int second [] = {50, 40, 30, 20, 10};

	vector<int> v(10);

	sort (first, first+5);
	sort (second, second+5);
	merge(first, first+5, second, second+5, v.begin());

	for( auto i: v)
	{
		cout << i << " - ";
	}
	cout << endl;
}


// partial sort


/* --------------- permutations --------------*/

void stl_fill()
{
	vector<int> vector (8);

	for( auto v: vector){
		cout << v << " - ";
	}
	cout << endl;
	fill(vector.begin(), vector.begin()+4, 5);

	for( auto v: vector){
		cout << v << " - ";
	}
	cout << endl;

	fill(vector.begin()+3, vector.end()-2, 8);
	for( auto v: vector){
		cout << v << " - ";
	}
	cout << endl;
}


void stl_swap()
{
	int a = 10, b=20;
	cout << a << " - " << b << endl;
	std::swap(a,b);
	cout << a << " - " << b << endl;
}


/*---------------- modifying sequence algorithms -------------- */


void stl_copy()
{
	vector<int> from_vector(10);
	std::iota(from_vector.begin(), from_vector.end(), 0);

	vector<int> to_vector;
	
	for( auto v: from_vector){
		cout << v << " - ";
	}
	cout << endl;
	
	for( auto v: to_vector){
		cout << v << " <-> ";
	}
	cout << endl;

	std::copy(from_vector.begin(), from_vector.end(),
		 std::back_inserter(to_vector));

	for( auto v: to_vector){
		cout << v << " <-> ";
	}
	cout << endl;

	cout << "to_vector contains: ";

	std::copy(to_vector.begin(), to_vector.end(),
			  std::ostream_iterator<int>(std::cout, " ")); 

	cout << endl;
}

void stl_remove()
{
	int myints[] = {10,20,30,30,10,22};

	int* pbegin = myints;
	int* pend = myints+ sizeof(myints)/sizeof(int);

	std::remove(pbegin, pend, 30);

	for(int* p = pbegin; p != pend; ++p)
		cout << ' ' << *p;
	cout << endl;
}


//unique
//replace
//rotate
//random_shuffle
//partition

/* --------------- nonmodifying sequence algorithms ------------- */

void myprintfunction(string i) { cout << " -> " << i; }
void stl_for_each()
{
	vector <string> v {"three", "four", "one"};
	for_each( v.begin(), v.end(), myprintfunction);
	cout << endl;
}

void stl_find()
{
	vector<int> v {1, 56, 2,7};
	vector<int>::iterator it;

	it = find(v.begin(), v.end(), 56);
	if(it != v.end())
		cout << "Found = "<< *it << endl;
	else
		cout << "Not found = " << *it << endl;
}

bool is_palindrome(const std::string& s)
{
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

void stl_equal(const string& s)
{
	std::cout << "\"" << s << "\" "
			  << (is_palindrome(s) ? "is" : "is not")
			  << " a palindrome\n";
}
	
string stl_mismatch(const string& in)
{
	return std::string(in.begin(),
					   std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}


/*----------------------- sequences---------------------------------- */

bool myfunction (int i,int j) { return (i<j); }

struct myclass
{
  bool operator() (int i,int j) { return (i<j);}
} myobject;

void stl_sort()
{
	int myints[] = {32,71,12,45,26,80,53,33};
	vector <int> myvector(myints, myints+8);
	
	// using default comparison (operator <):
	std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

	// using function as comp
	std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

	// using object as comp
	std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

	for( auto v: myvector)
		cout << v << " ";
	cout << endl;
}

int main()
{
	// pair of iterators (inputs) or a single iterator (outputs)

	stl_sort();
	stl_for_each();
	stl_find();
	stl_equal("radar");
	stl_equal("hello");
	cout << stl_mismatch("abXYZba") << endl;
	cout << stl_mismatch("abca") << endl;
	cout << stl_mismatch("aba") << endl;
	stl_copy();
	stl_fill();
	stl_swap();
	stl_remove();
	stl_binary_search();
	stl_merge();
	stl_lexicographical_compare();
	stl_min_max();
	
	return 0;
}

