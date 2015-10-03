//http://www.cplusplus.com/reference/exception/exception/
#include <iostream>
#include <exception>

using namespace std;

class X {
    virtual void up(){}
};

int main()
{
    try
    {
        //throw 20;
        //int* myarray= new int[10000000000000000];
         X *x = 0;
        typeid(*x);
    }
    catch(int e)
    {
        cout << "Exception nr.. = " << e << endl;
    }
    catch(exception e)
    {
        cerr <<"Poly error = "<< e.what() <<endl; // bad_typeid exception
    }
    catch( exception& e)
    {
        cout << "Standart exception: " << e.what() << endl;
    }
    
    cout << "end" << endl;
    return 0;
}

/* 

c++ 11
 
bad_function_call
bad_weak_pointer
future_error
system_error
bad_array_new_length 
 
*/