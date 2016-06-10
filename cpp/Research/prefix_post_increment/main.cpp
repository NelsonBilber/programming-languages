#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int i = 1;
	//assign -> increment
	//pre-increment --> first will increment the value of i, and then return the incremented value
	int j = ++i; 
	int k = 1;
	//increment -> assign
	//post-increment --> first will increment the value of i, but return the original value that i held before being incremented
	int kk = k++; 

	std::cout << "i = " << i << " j = " << j << " k =  " << k << std::endl;

	for(int i = 0; i < 5; i++){
		std::cout <<" i = " << i << std::endl;  
	}

	std::cout << std::endl;

	for(int i = 0; i < 5; ++i){
		std::cout <<" i = " << i << std::endl;  
	}

	std::cout << std::endl;

	for(int i = 0; i < 5; ){
		std::cout <<" i = " << ++i << std::endl;  
	}

	std::cout << std::endl;

	for(int i = 0; i < 5; ){
		std::cout <<" i = " << i++ << std::endl;  
	}

	int n = 1;
	if(++n == 2) {
		std::cout <<" is equal 2" << std::endl;
	}
	else {
		std::cout <<" not equal 2" << std::endl;
	}
		
	int m = 1;
	if(m++ == 2) {
		std::cout <<" is equal 2" << std::endl;
	}
	else {
		std::cout <<" not equal 2" << std::endl;
	}
	
	return 0;
}
