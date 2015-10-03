
#include <iostream>

using namespace std;

class Shape
{
public:
    virtual void print ()
    {
        cout << " SHAPE " << endl;
    }
};


class Circle : public Shape
{
public:
    void print ()
    {
        cout << " CIRCLE " << endl;
    }
};



int main(int argc, const char * argv[]) {

    Shape* shape = new Circle();
    shape->print();
    
    delete shape;
    
    return 0;
}
