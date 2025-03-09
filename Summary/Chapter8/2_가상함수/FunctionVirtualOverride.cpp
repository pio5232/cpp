#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc() { cout << "FirstFunc()\n"; }
};

class Second : public First
{
public:
	virtual void MyFunc() { cout << "SecondFunc()\n"; }
};

class Third : public Second
{
public:
	virtual void MyFunc() { cout << "ThirdFunc()\n"; }
};

int main()
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	delete tptr;

	return 0;
}