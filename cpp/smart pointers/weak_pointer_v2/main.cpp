// Weak Pointer
//
// Excelent tutorial about weak_pointers
//http://www.umich.edu/~eecs381/examples/std_smart_pointer_demos/weak_ptr_demo.cpp

/*
Demonstration of shared_ptr and weak_ptr, showing how cycle problems can be solved.
*/

/* A Thing has a pointer to another Thing. The following code creates two Things that
point to each other. If the internal pointers are weak_ptrs, then when main discards 
its shared_ptrs, the objects get deleted properly.  
*/


#include <iostream>
#include <memory>

using namespace std;

class Thing
{
public:
	//give each Thing a unique number so we can easily tell them part
	Thing():i(++count){}
	~Thing() {cout << "Thing " << i << " destruction " << endl;}

	int get_i() const {return i;}

	//make this Thing point to another one
	void set_ptr(shared_ptr<Thing> p) { ptr = p; }

	//display who Thing is now pointing to, if anybody
	void print_pointing_to() const 
	{
		// see if the pointed-to object is there
		if(ptr.expired())
		{
			cout << "Thing " << i << " is pointing at nothing" << endl;
		}
		else 
		{
			// create a temporary shared pointer, making sure the other Thing stays around
			// long enough to look at it
			shared_ptr<Thing> p = ptr.lock();
			// redundant in this code, but another way to test for expiration
			if(p)
			{
				cout <<  "Thing " << i << " is pointing to Thing " << p->get_i() << endl;
			}
	       } 
	}
private:
	//point to the other Thing, bit doesn't affect lifetime
	weak_ptr<Thing> ptr;
	int i;
	static int count;
	
};

int Thing::count = 0;
 
int main()
{
	/* Always create objects like this, in single stand-alone statement that does nothing 
	more than create the new object in a shared_ptr constructor, to minimize any possibility 
	of having a stray ordinary pointer involved, or other wierd effects.
	*/

	shared_ptr<Thing> p1(new Thing);
	shared_ptr<Thing> p2(new Thing);

	//display what each object is pointing to:
	p1->print_pointing_to();
	p2->print_pointing_to();
    
	//create the cycle with two set_ptr calls:
	p1->set_ptr(p2);
	p2->set_ptr(p1);

	//display what each object is pointing to:
	p1->print_pointing_to();
	p2->print_pointing_to();

	/*	A. */
	// reset with no arguments is how you discard the pointed-to object;
	// it zeroes-out the internal pointer to the shared object; 
	p1.reset();
	// display what Thing 2 is pointing to
	p2->print_pointing_to();
	/**/


	return 0;
}
