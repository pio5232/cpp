#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class First
{
private:
	char* strOne;
public:
	First(const char* str)
	{
		strOne = new char[strlen(str) + 1];
	}
	~First()
	{
		cout << "~First()\n";
		delete[] strOne;
	}
};

class Second : public First
{
private:
	char* strTwo;
public:
	Second(const char* str1, const char* str2) : First(str1)
	{
		strTwo = new char[strlen(str2) + 1];
	}
	~Second()
	{
		cout << "~Second()" << endl;
		delete[] strTwo;
	}
};

int main()
{
	First* ptr = new Second("SIMPLE", "COMPLEX");
	delete ptr;
	return 0;
}