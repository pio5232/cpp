#include <iostream>
using namespace std;

int main()
{
	int num1 = 1020;
	int& num2 = num1;

	num2 = 3047;
	cout << "VAL : " << num1 << endl;
	cout << "REF : " << num2 << endl;

	cout << "VAL : " << &num1 << endl;
	cout << "REF : " << &num2;
	return 0;
}