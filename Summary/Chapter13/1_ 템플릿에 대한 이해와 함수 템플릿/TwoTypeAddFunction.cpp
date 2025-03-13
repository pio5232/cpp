#include <iostream>
using namespace std;

template <typename T>
T add(T num1, T num2)
{
	cout << "T add()\n";
	return num1 + num2;
}

int add(int num1, int num2)
{
	cout << "int add()\n";
	return num1 + num2;
}

double add(double num1, double num2) 
{
	cout << "double add()\n";
	return num1 + num2;
}


int main()
{
	cout << add(15, 20) << endl;
	cout << add(2.9, 3.7) << endl;
	cout << add<int>(3.2, 3.2) << endl;
	cout << add<double>(3.14, 2.75) << endl;

	return 0;
}
