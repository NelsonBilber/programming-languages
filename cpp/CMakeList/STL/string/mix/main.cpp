#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string address(const string& identifier, const string& domain)
{
	return identifier + '@' + domain;
}

void findstring()
{
	string s {"accdcde"};

	cout << s.find("cd") << endl;
	cout << s.rfind("cd")<< endl;
}

int main()
{
	string hello = "hello_world";

	cout << "islower() " << islower('C') << " - " << islower('c') << endl; 
	cout << "" << toupper('c') << endl;

	//toupper
	std::string str = "Hello world";
	std::transform (str.begin(), str.end(), str.begin(), ::toupper);

	cout << "" << str << endl;

	//concatenate strings
	cout << address("cool", "cool.ed") << endl;

	//stoi

	string s = "123.45";

	cout << "stoi (atoi) " << stoi(s.c_str()) << endl;
	cout << "stod (atod)" << stod(s.c_str()) << endl;

	//find
	findstring();

	//substring

	string  ss {"github"};

	cout <<"substring = "<<ss.substr(4,5) << endl;
	
    return 0;
}

