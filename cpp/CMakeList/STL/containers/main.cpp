//http://en.cppreference.com/w/cpp/container/vector
//http://en.cppreference.com/w/cpp/container/vector/insert
//http://en.cppreference.com/w/cpp/language/range-for
//http://www.cplusplus.com/reference/vector/vector/emplace/
//http://www.cplusplus.com/reference/list/list/remove_if/
//http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html
//http://www.cplusplus.com/reference/vector/vector/reserve/

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <unordered_map> // c++11

using namespace std;


// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
    bool operator() (const int& value) { return (value%2)==1; }
};


void vector_example()
{
    cout << "------------------------------------" << endl;
    cout << " vector " << endl;
    cout << "------------------------------------" << endl;
    
    vector <int> v {11,3,5,6,3};
    
    for(auto i : v) { //acess by value the type of i is int
        cout << i << " ";
    }
    
    cout << endl;
    
    for(const int&i : v) { // access by const reference
        cout << i << " ";
    }
    
    cout << endl;
    
    for( auto&&i : v ) { //acess by reference the type of int&
        cout << i << " ";
    }
    
    cout << endl;
    
    for(int n : {0,1,2,3,4,5}) { //the initializer may be a braced-init-list
        cout << n << " ";
    }
    
    cout << endl;
    
    cout << "Begin : " << *(v.begin()) << endl;
    cout << "End : " << *(v.end()) << endl;
    
    vector<int> vect(3, 100);
    for(auto i : vect) {
        cout << i << " ";
    }
    
    cout << endl;
    
    int arr[] = { 501, 502, 503};
    vect.insert(vect.begin()+2, arr, arr+2);
    for(auto i : vect) {
        cout << i << " ";
    }
    
    cout << endl;
    
    vect.erase(vect.begin()+2, vect.end());
    for(auto i : vect) {
        cout << i << " ";
    }
    
    cout << endl;
    
    vector<int> vv = {10, 20, 30};
    auto it = vv.emplace(vv.begin()+1, 100);
    
    for(auto i : vv) {
        cout << i << " ";
    }
    
    cout << endl;
    
    vv.emplace(it, 200);
    
    for(auto i : vv) {
        cout << i << " ";
    }
    cout << endl;

}

void list_example()
{
    cout << "------------------------------------" << endl;
    cout << " list " << endl;
    cout << "------------------------------------" << endl;
    
    //pair is a particular case of tuple
    list<pair<string, double>> lst;
    
    auto p = lst.begin();
    p = lst.emplace(p, "England", 5.5);
    p = lst.insert(p, make_pair("Portugal", 9.9));
    
    for(auto i : lst ){
        cout << " " << i.first << " - " << i.second << endl;
    }
    
    cout << endl;
    
    lst.reverse();
    
    for(auto i : lst ){
        cout << " " << i.first << " - " << i.second << endl;
    }
    
    cout << endl;
    
    int myints[]= {15,36,7,17,20,39,4,1};
    std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
    
    mylist.remove_if (single_digit);           // 15 36 17 20 39
    
    mylist.remove_if (is_odd());               // 36 20
    
    std::cout << "mylist contains:";
    for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it){
        std::cout << ' ' << *it;
    }
    std::cout << '\n';

}



void map_example()
{
    cout << "------------------------------------" << endl;
    cout << " map " << endl;
    cout << "------------------------------------" << endl;
    
    map <int, string> map_people;
    
    map_people[100] = "nelson";
    map_people[230] = "scarlet";
    map_people[234] = "mia";
    map_people[234] = "anna";
    map_people[234] = "anna";
    map_people[234] = "anna";
    
    for(map <int, string>::iterator ii = map_people.begin();
        ii != map_people.end(); ++ii)
    {
        cout << (*ii).first << " : " << (*ii).second << endl;
    }
    
    cout << endl;
    
    map <int, string> map_people_ordered;
    //map <int, string, std::less<int>> map_people_ordered; // order insert
    //map <int, string, std::greater<int>> map_people_ordered; //order insert
    
    map_people_ordered[100] = "nelson";
    map_people_ordered[80] = "scarlet";
    map_people_ordered[234] = "mia";
    map_people_ordered[1] = "anna";
    map_people_ordered[1] = "anna";
    map_people_ordered[1] = "anna";
    
    map_people_ordered.insert(std::pair<int, string>(2, "joana"));
    map_people_ordered.insert(map<int, string>::value_type(3, "eve"));
    map_people_ordered.insert(std::make_pair(4, "mona lisa"));
    
    for(map <int, string>::iterator iii = map_people_ordered.begin();
        iii != map_people_ordered.end(); ++iii)
    {
        cout << (*iii).first << " : " << (*iii).second << endl;
    }
    
    cout << endl;
}


void hash_example()
{
    cout << "------------------------------------" << endl;
    cout << " unordered_map a.k.a hash " << endl;
    cout << "------------------------------------" << endl;
    
    unordered_map <int, string> u_map_people;
    
    u_map_people[100] = "nelson";
    u_map_people[230] = "scarlet";
    u_map_people[234] = "mia";
    u_map_people[234] = "anna";
    u_map_people[234] = "anna";
    u_map_people[234] = "anna";
    
    for(auto ii = u_map_people.begin();
        ii != u_map_people.end(); ++ii)
    {
        cout << (*ii).first << " : " << (*ii).second << endl;
    }

    std::cout << '\n';
    
}

void hash_multi_example()
{
    cout << "------------------------------------" << endl;
    cout << " unordered_map  " << endl;
    cout << "------------------------------------" << endl;
    
    
    std::unordered_multimap<int,std::string> u_map_people = {
        {100,"nelson"},
        {100,"nelson"},
        {100,"anna"},
        {100,"anna"},
        {101,"anna"},
        {100,"nelson"},
        {7,"eve"},
    };

    for(auto ii = u_map_people.begin();
        ii != u_map_people.end(); ++ii)
    {
        cout << (*ii).first << " : " << (*ii).second << endl;
    }
    
    std::cout << '\n';
    
}

void reserve()
{
    cout << "------------------------------------" << endl;
    cout << " reserve()  " << endl;
    cout << "------------------------------------" << endl;
    
    std::vector<int>::size_type sz;
    
    std::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i)
    {
        foo.push_back(i);
        if (sz!=foo.capacity())
        {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }
    
    std::cout << '\n';
  
    std::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<105; ++i)
    {
        bar.push_back(i);
        if (sz!=bar.capacity())
        {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
        }
    }

    std::cout << '\n';
    
}


int main()
{
    vector_example();
    list_example();
    map_example();
    hash_example();
    hash_multi_example();
    
    reserve();
}

/* 

 sequence containers:
 --------------------
 vector
 list
 forward_list
 deque
 
 associative containers:
 -----------------------
 map
 multimap
 set
 multiset
 unordered_map
 unordered_multimap
 unordered_set
 unordered_multiset
 
 containers adaptors:
 --------------------
 priority_queue
 queue
 stack

 almost containers:
 -------------------
 T[N]
 array<T,N>
 basic_string<>
 string
 u16string
 u32string
 wstring
 valarray<T>
 vector<bool>
 
*/