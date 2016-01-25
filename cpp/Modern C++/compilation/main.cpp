//http://www.codeproject.com/Articles/570638/Ten-Cplusplus-Features-Every-Cplusplus-Developer

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Foo{
public:
    int x;
    Foo(){  cout << "ctor Foo " << endl;}
    ~Foo(){ cout << "~dtor Foor" << endl; }
};

//returning auto types
template<typename T1, typename T2>
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
{
    return t1+t2;
}


int main(int argc, const char * argv[]) {
    
    //===================================================
    // Auto
    //===================================================
    
    auto i = 42;
    auto l = 42LL;
    auto f = new Foo();
    auto v = Foo();
    
    map<string, vector<int> > mymap;
    for(auto it= begin(mymap); it != end(mymap); ++it)
    {
        cout << "" << typeid(mymap).name() << endl;
        
    }
    
    cout << "" << typeid(i).name() << endl;
    cout << "" << typeid(l).name() << endl;
    cout << "" << typeid(f).name() << endl;
    cout << "" << typeid(v).name() << endl;
    
    auto return_auto = compose (3 , 3.14); // v's type is double
    
    cout << "" << return_auto << endl;
    
    delete f;
    
    
    //===================================================
    // nullptr
    //===================================================
    
    
    int* p1 = NULL;
    int* p2 = nullptr;
    if( p1 == p2)
        cout << "equal" << endl;
    else
        cout << "not equal " << endl;
    
    //===================================================
    // Range-base for loops
    //===================================================
    
    
    map<string , vector<int>> mmap;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(34);
    
    mmap["map"] = vec;
    
    for(const auto& kvp: mmap)
    {
        cout << kvp.first << endl;
        
        for(auto vv : kvp.second)
        {
            cout << vv << endl;
        }
    }
    
    cout << "" << endl;
    
    int arr[] = {1,2,3,4,5};
    for(int& e : arr)
    {
        e = e * e;
        cout << "" << e << endl;
    }
    
    //===================================================
    // Override and final
    //===================================================
    
    return 0;
}
