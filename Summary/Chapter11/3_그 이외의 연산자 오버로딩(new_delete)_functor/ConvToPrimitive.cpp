#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num()
	{
		cout << "Number(int n = 0 )" << endl;
	}

	Number& operator= (const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}

	operator int()
	{
		return num;
	}

	void ShowNumber() { cout << num << endl; }
};

int main()
{
	Number num1;
	num1 = 30;
	Number num2 = num1 + 20;
	num2.ShowNumber();

	return 0;
}