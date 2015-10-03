// from :: https://msdn.microsoft.com/en-us/library/4h2h0ktk.aspx
#include <iostream>
#include <string>
using namespace std;

class Date{
public:
	Date():
		cache_valid(false),
		cache("cache ")
		{}
	
	string string_repo() const
	{
		if(!cache_valid){
			compute_cache();
		}
	}

private:
	mutable bool cache_valid;
	mutable string cache;
	
	void compute_cache() const
	{
		cache.append(" computed");
	}
	
};

class X
{
public:
   bool GetFlag() const
   {
      m_accessCount++;
      return m_flag;
   }
private:
   bool m_flag;
   mutable int m_accessCount;
};

void funk(Date d, const Date cd){
	string s1 = d.string_repo();
	string s2 = d.string_repo();
	
	//cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
}

int main()
{
	Date d1, d2;
	
	funk(d1, d2);
	
	return 0;
}
