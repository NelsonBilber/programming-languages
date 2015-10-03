//http://www.tomdalling.com/blog/software-design/resource-acquisition-is-initialisation-raii-explained/
//http://www.codingstandard.com/rule/3-4-3-use-raii-for-resources/

#include <iostream>
#include <string>

using namespace std;

class File{

public:
	void open(string filename){ cout << "file open = " << filename << endl; }
	void close(){ cout << "file close "<< endl; }
};

class OpenFile
{
public:
	OpenFile()
	{
		try
		{
			file_.open("tmp.txt");
		}
		catch(...)
		{
			std::cout << "Error Open File" << std::endl;
		}
	} 

	~OpenFile()
	{
		file_.close();
	}

private:
	File file_;
};


int main(int argc, char *argv[])
{
	OpenFile of;
        return 0;
}



/*                   Explanation

File f;
f.open("boo.txt");
//UNSAFE - an exception here means the file is never closed
loadFromFile(f);
f.close();

Dog* dog = new Daschund;
//UNSAFE - an exception here means the dog is never deleted
goToThePark(dog); 
delete dog;

Lock* lock = getLock();
lock.aquire();
//UNSAFE - an exception here means the lock is never released
doSomething();
lock.release();

*/
