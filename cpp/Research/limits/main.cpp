#include <iostream>
#include <limits>

using namespace std;

int main()
{
    std::cout <<"min value for int "<< std::numeric_limits<int>::lowest() << std::endl;
    std::cout <<"max value for int "<< std::numeric_limits<int>::max() << std::endl;
    std::cout <<"min value for char "<< std::numeric_limits<char>::lowest() << std::endl;
    std::cout <<"max value for char "<< std::numeric_limits<char>::max() << std::endl;

    std::cout <<"char  size = "<< sizeof(char) <<" bytes equals to " << sizeof(char)*8   << " bits" <<std::endl;
    std::cout <<"bool  size = "<< sizeof(bool) <<" bytes equals to " << sizeof(bool)*8   << " bits" <<std::endl;
    std::cout <<"short size = "<< sizeof(short)<<" bytes equals to " << sizeof(short)*8  << " bits" <<std::endl;
    std::cout <<"int   size = "<< sizeof(int)  <<" bytes equals to " << sizeof(int)*8    << " bits" <<std::endl;
    std::cout <<"float size = "<< sizeof(float)<<" bytes equals to " << sizeof(float)*8  << " bits" <<std::endl;
    std::cout <<"long  size = "<< sizeof(long) <<" bytes equals to " << sizeof(long)*8   << " bits" <<std::endl;
    std::cout <<"long double size = "<< sizeof(long double)<<" bytes equals to  " << sizeof(long double)*8  << " bits" <<std::endl;
    
    return 0;
}

