//auto_pointer deprecated in c++11

#include <iostream>
#include <memory>
#include <vector>
#include <map>

using namespace std;


typedef int ContainedType;


int main()
{
  
  int *i = new int; // auto_ptr so pode ser consumido com apontadores do tipo  new
  auto_ptr<int>x(i);
  auto_ptr<int>y;

  y = x;

  cout << x.get() << endl; // null
  cout << y.get() << endl; // non-null address

  //delete i; //memory crash


  auto_ptr <vector<ContainedType> > open_vec(new vector<ContainedType>);
  open_vec->push_back(0);
  open_vec->push_back(1);
  open_vec->push_back(2);

  // Transfers control, but now the vector cannot be changed:
    auto_ptr<const vector<ContainedType> > closed_vec(open_vec); 
 
    // closed_vec->push_back(8); // Can no longer modify 
 
    // Safe during the lifetime of the autoptr:
    map<string, const ContainedType *> nmap;
 
    nmap["First"]  = & closed_vec->at(0);
    nmap["Second"] = & closed_vec->at(1);
    nmap["Third"]  = & closed_vec->at(2);
 
    for (map<string, const ContainedType *>::iterator it = nmap.begin(); it != nmap.end(); ++it) {
        cout << it->first << " -> " << *(it->second) << std::endl;
    }
 


  return 0;
}
