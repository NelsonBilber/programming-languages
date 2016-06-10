#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	for(int i = 0 ; i < 3 ; i++){
		std::cout<< "i = " << i << std::endl;
		for(int j = 0; j < 5; j++){
			std::cout<<"\t"<<"j = " << j << std::endl;
			if(j == 2){
				continue;
				std::cout<<"Never reach this code !" << std::endl;
				std::cout<<"Skips the rest of the body of an iteration-statement" << std::endl;
				std::cout<<"... but continues the loop !!!! " << std::endl;
			}
		} 
	}
	
	return 0;
}
