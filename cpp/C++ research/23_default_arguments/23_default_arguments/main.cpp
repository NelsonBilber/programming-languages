#include <iostream>

using  namespace std;

void foo (int x, int value = 10)
{
    cout << "value (int) = " << value << endl;
}

void foo (int x, double value = 13.0)
{
    cout << "value (double) = " << value << endl;
}

void bar(int v = 10, char c = ' ') {
    cout << "value (int) = " << v << endl;
}

void bar( double v = 10.3, char c = ' ') {
    cout << "value (double) = " << v << endl;
}

int main(int argc, const char * argv[]) {
  
    //note: default params don't count to make function
    //unique
    
    //foo ( 10 );
    //foo ( 12.3);
    
    // ... bit it can have all overloading params
    // as default 
    
    bar(10);
    bar(12.0);
    
    return 0;
}
