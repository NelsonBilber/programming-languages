//
//  HelloCpp.hpp
//  singleview
//
//  Created by Nelson Rodrigues on 21/09/15.
//  Copyright © 2015 Nelson Rodrigues. All rights reserved.
//

#ifndef HelloCpp_hpp
#define HelloCpp_hpp

#include <iostream>
#include <string>

using namespace std;

class HelloCpp
{
public:
    HelloCpp();
    ~HelloCpp();
    
    void print();
    string getStringName();
private:
    string label_;
};

#endif /* HelloCpp_hpp */
