#include <iostream>
using namespace std;


class SoSimple
{
public:
	static int simObjCnt;

	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "¹øÂ° SoSimpe °´Ã¼ " << endl;
	}
};

class SoComplex
{
public:
	static int cmxObjCnt;
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << endl;
	}

	SoComplex(const SoComplex& other)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << endl;
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