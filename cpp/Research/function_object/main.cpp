// example from :: http://msdn.microsoft.com/en-us/library/dd293608.aspx



#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class FunctorClass
{
public:
  // The required constructor for this example.
  explicit FunctorClass(int& evenCount)
    : m_evenCount(evenCount) { }

  // The function-call operator prints whether the number is
  // even or odd. If the number is even, this method updates
  // the counter.
  void operator()(int n) const {
    cout << n;

    if (n % 2 == 0) {
      cout << " is even " << endl;
      ++m_evenCount;
    } else {
      cout << " is odd " << endl;
    }
  }

private:
  // Default assignment operator to silence warning C4512.
  FunctorClass& operator=(const FunctorClass&);

  int& m_evenCount; // the number of even variables in the vector.
};


int main()
{
  // Create a vector object that contains 10 elements.
  vector<int> v;
  for (int i = 1; i < 10; ++i) {
    v.push_back(i);
  }

  // Count the number of even numbers in the vector by
  // using the for_each function and a function object.
  int evenCount = 0;
  for_each(v.begin(), v.end(), FunctorClass(evenCount));

  // Print the count of even numbers to the console.
  cout << "There are " << evenCount
       << " even numbers in the vector." << endl;
}
