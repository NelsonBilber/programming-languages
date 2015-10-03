#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void std_string()
{
  string base = "this is the base string ";
  string add = " so we can append some text using std libs ";
  int repeat = 10;

  base.append(add);
  
  cout << base << endl;

  base.append<int>(repeat, 0x2E);

  cout << base << endl;

}

void overloading_operator_plus()
{
  std::string name("Bill ");
  std::string surname("Kill");
 
  std::string result;

  result+=surname;
  result+= name;
 
  cout << result << endl;
}

void add_int_string_stream()
{
  std::ostringstream s;
  s << "select * from users where id = " << 777;

  string transform(s.str());
  cout <<  transform << endl;
}

void add_int_string_CPP11()
{
  string query("select * from users where id = " + to_string(999));
  cout << query << endl;
}



int main()
{

  //using standart libs
  std_string();

  cout << endl;

  //overloading the operator
  overloading_operator_plus();

  cout << endl;

  //using sstream
  add_int_string_stream();

  cout << endl;

  //c++11 style

  add_int_string_CPP11();

  return 0;
}
