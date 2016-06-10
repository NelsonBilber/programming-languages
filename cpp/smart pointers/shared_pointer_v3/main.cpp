// Shared Pointer
//
// Excelent tutorial about shared_pointers
//http://www.umich.edu/~eecs381/examples/std_smart_pointer_demos/shared_ptr_demo.cpp



#include <iostream>
#include <memory>

using namespace std;


// Important
// Thing inherits from template class std::tr1::enaable_shared_from_this<>
class Thing : public enable_shared_from_this<Thing> {
public:
	// give each Thing a unique number so we can easily tell them apart
	Thing() : i(++count) {}
	// verify the destruction
	~Thing () {cout << "Thing " << i << " destruction" << endl;}
	int get_i() const {return i;}
	// make this Thing point to another one
	void set_ptr(shared_ptr<Thing> p) 
		{ptr = p;}
	// display who this Thing is now pointing to, if anybody
	void print_pointing_to() const
	{
		if(ptr)
			cout <<  "Thing " << i << " is pointing to Thing " << ptr->get_i() << endl;
		else
			cout <<  "Thing " << i << " is pointing to nobody" << endl;
	}
	
private:
	shared_ptr<Thing> ptr;	// keeps other Thing in existence as long as this Thing exists
	int i;
	static int count;
};

int Thing::count = 0;


int main()
{
	/* Always create objects like this, in single stand-alone statement that does nothing 
	more than create the new object in a shared_ptr constructor. This will help prevent 
	accidentally assigning more than one shared_ptr family to the same object.
	*/

	shared_ptr<Thing> p1(new Thing);
	shared_ptr<Thing> p2(new Thing);

	//:: Problems ::
	//mix smart pointers with raw pointers !!!!

/* 	// It is difficult to set a shared_ptr to an object any other way.
	// The definition of shared_ptr disallows assigning from a raw pointer!
	shared_ptr<Thing> p3;

	Thing * raw_ptr = new Thing;
	p3 = raw_ptr;	// disallowed! compile error!

	// the following works, but there is no protection against raw_ptr being used elsewhere; try to avoid
	p3.reset(raw_ptr);
*/
		
	// create a cycle with two set_ptr calls:
	p1->set_ptr(p2);
	//p2->set_ptr(p1);
	
	// display what each object is pointing to:
	p1->print_pointing_to();
	p2->print_pointing_to();
	
	// reset with no arguments is how you discard the pointed-to object;
	// break the cycle by calling the pointer reset function for one of the objects
	// to discard its pointer
	//p1.reset();	
	p2.reset();
	
	cout << "Exiting main function" << endl;	
}
