#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base Constructor\n"; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne : virtual public Base
{
public:
	MiddleDerivedOne() : Base()
	{
		cout << "MiddleDerivedOne Constructor\n";
	}

	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDerivedOne\n";
	}
};

class MiddleDerivedTwo : virtual public Base
{
public:
	MiddleDerivedTwo() : Base()
	{
		cout << "MiddleDerivedOne Constructor\n";
	}

	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDerivedOne\n";
	}
};
class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		cout << "LastDerived Constructor\n";
	}

	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main()
{
	cout << "��ü ���� ��\n";
	LastDerived dr;
	cout << "��ü ���� ��\n";
	dr.ComplexFunc();

	return 0;
}