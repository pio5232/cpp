#include <iostream>
using namespace std;


class SoSimple
{
public:
	static int simObjCnt;

	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimpe ��ü " << endl;
	}
};

class SoComplex
{
public:
	static int cmxObjCnt;
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