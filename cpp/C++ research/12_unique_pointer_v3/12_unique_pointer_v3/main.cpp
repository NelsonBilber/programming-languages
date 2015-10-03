//Excelente tutorial From
//http://www.umich.edu/~eecs381/examples/std_smart_pointer_demos/unique_ptr_demo.cpp

/* Demo of unique_ptr
In summary: 
A unique_ptr has sole ownership of the pointed-to object. It has no
copy constructor or copy assignment. It does have a move constructor
and move assignment. This means that rvalue unique_ptrs can have their
ownership moved implicitly, but not lvalue unique_ptrs. 
This means that a unique_ptr can be assigned to the unique_ptr returned
from a function, but you can't assign one declared unique_ptr to another.

But if you invoke a move assignment (with std::move) you can assign them, 
but the lhs unique_ptr now owns the object and the rhs now owns nothing.

The standard container insert functions will move a rvalue unique_ptr in;
You have to explicitly move an lvalue in otherwise with std::move.
but their accessor functions will not move a unique_ptr out. But you
can use the accessor as a way to use the pointer.

By explicitly invoking a move (with std::move) you can use a container
accessor to move ownership out into another unique_ptr.  The unique_ptr 
remains in the container, but it now owns nothing.
*/


#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Thing 
{
public:
	Thing() : 
	  i (++count) 
          {
	    cout << "Thing " << i << " creation" << endl;
          }

	~Thing ()
        {
	   cout << "Thing " << i << " destruction" << endl;
        }

	int get_i() const 
        {
	  return i;
        }
private:
	int i;
	static int count;
};

int Thing::count = 0 ;


// create a Thing returning a unique_ptr-transfer of ownership is the concept
unique_ptr<Thing> create_Thing()
{
  unique_ptr<Thing> p (new Thing);
  cout << "in create thing: p points to thing " << p->get_i() << endl;
  
  unique_ptr<Thing> p3;
  //p3 = p;// error transfering ownership, this is not possible;

  return p;
}

void refer_to_it(unique_ptr<Thing>& p)
{
  cout <<" in refer_to_it: p points to Thing "<< p->get_i()<< endl;
  cout << "leaving refer_to_it" << endl;
}


void take_it(unique_ptr<Thing> p)
{
  cout << "in take_it: p points to Thing " << p->get_i() << endl;
  cout << "leaving take_it"<< endl;
}


int main()
{
  //scope 1:: create a Thing owned by a unique ptr, then  leave the scope
  {
    cout << "Entering main scope 1" << endl;
    unique_ptr<Thing> p =  create_Thing();

    cout <<"in main scope 1: p points to thing " <<p->get_i()<< endl;
    
    unique_ptr<Thing> p2;
    cout << "Leaving main scope 1 "<<endl;
  }

  //scope 2: create another Thing, give it to a fcuntion that refers to it
  {
    cout << "\nEntering main scope 2" << endl;
    unique_ptr<Thing> p = create_Thing();
    cout <<"in main scope 2: p points to Thing " << p->get_i() << endl;
    
    refer_to_it(p);

    //does p still own anything?

    if(p)
      cout << "in main scope 2: p points to Thing " << p->get_i() <<endl;
    else
      cout << "in main scope 2: p points to nothing"<< endl;
    cout << "leaving main scope 2" << endl;
  }
  
  //scope 3 : create another Thing, give it (and ownership to a function which keeps it"

  {
    cout << "Entering main scope 3"<< endl;
    unique_ptr<Thing> p = create_Thing();
    cout <<"in main scope 3: p points to Thing" << p->get_i() << endl;

    //take_it(p) // error - can'tcopy it as a function argument
    
    take_it(std::move(p)); //move ownership to take_it function

    //does p still own anything?

        // does p still own anything?
     if(p)
         cout << "in main scope 3: p points to Thing " << p->get_i() << endl;        else
          cout << "in main scope 3: p points to nothing" << endl;
     cout << "Leaving main scope 3" << endl;
  }

  //scope 4: create some things, pointed to a unique_ptr, and store the ins a vector

  //..

  //scope 5: put unique_ptrs in a map

  //...

  return 0;
}
