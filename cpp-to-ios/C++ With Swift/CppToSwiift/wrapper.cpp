//
//  wrapper.cpp
//  CppToSwiift
//
//  Created by Nelson Rodrigues on 23/09/15.
//  Copyright © 2015 Nelson Rodrigues. All rights reserved.
//

#include "junk.hpp" 
// extern "C" will cause the C++ compiler
// (remember, this is still C++ code!) to
// compile the function in such a way that
// it can be called from C
// (and Swift).
extern "C" int getIntFromCPP()
{
    // Create an instance of A, defined in
    // the library, and call getInt() on it:
    return A(1234).getInt();
}