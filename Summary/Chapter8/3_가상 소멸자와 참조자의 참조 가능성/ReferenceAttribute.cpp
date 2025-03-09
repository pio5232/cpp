#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()\n"; }
	virtual void SimpleFunc() { cout << "First's Simple Function()" << endl; }
};


class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()\n"; }
	virtual void SimpleFunc() { cout << "Second's Simple Function()" << endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()\n"; }
	virtual void SimpleFunc() { cout << "Third's Simple Function()" << endl; }
};

int main()
{
	Third obj;

	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& rObj = obj;
	rObj.FirstFunc();
	rObj.SecondFunc();
	rObj.SimpleFunc();
}