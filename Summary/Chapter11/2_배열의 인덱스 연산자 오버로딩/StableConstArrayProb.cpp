#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>

using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray operator= (const BoundCheckIntArray* arr) {}
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	// -- 문제가 발생한다. ShowAllData에서는 const 형으로 받는데. const 함수가 정의되지 않아서 생기는 문제다.
	int& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception " << endl;
			exit(1);
		}
		return arr[idx];
	}

	int operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception " << endl;
			exit(1);
		}
		return arr[idx];
	}

	~BoundCheckIntArray()
	{
		delete[] arr;
	}

	int GetArrLen() const { return arrlen; }
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;
}
int main()
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;

	ShowAllData(arr);

	return 0;
}