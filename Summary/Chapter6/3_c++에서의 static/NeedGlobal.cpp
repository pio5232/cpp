#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimpe ��ü " << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}

	SoComplex(const SoComplex& other)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};

int main()
{
	SoSimple sim1;
	SoSimple sim1;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}