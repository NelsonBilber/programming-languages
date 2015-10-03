//
//  main.cpp
//  manual_vector
//
//  Created by Nelson Rodrigues on 23/08/15.
//  Copyright (c) 2015 Nelson Rodrigues. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //int* vi = new int [10];
    int vi[10];
    
    for(int i = 0; i < 10; i++)
    {
        vi[i] = i;
    }
    
    for(int i = 0; i < 10; i++)
    {
        cout << vi[i] << endl;
    }
    
    
    return 0;
}
