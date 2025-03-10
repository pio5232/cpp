#include <iostream>
#include <cstdlib>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { cout << "point 생성자 [" << x << " " << y << "]" << endl; }
	friend ostream& operator << (ostream& os, const Point& pos);
	Point& operator=(const Point& other)
	{
		cout << "point 대입연산자 [" << other.xpos << " " << other.ypos << "]" << endl;
		xpos = other.xpos;
		ypos = other.ypos;

		return *this;
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

using POINT_PTR = Point*;

class BoundCheckPointArray
{
private:
	POINT_PTR* arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr) {}
	BoundCheckPointArray operator= (const BoundCheckPointArray* arr) {}
public:
	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr = new POINT_PTR[len];
	}
	// -- 문제가 발생한다. ShowAllData에서는 const 형으로 받는데. const 함수가 정의되지 않아서 생기는 문제다.
	POINT_PTR& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception " << endl;
			exit(1);
		}
		return arr[idx];
	}

	POINT_PTR operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception " << endl;
			exit(1);
		}
		return arr[idx];
	}

	~BoundCheckPointArray()
	{
		delete[] arr;
	}

	int GetArrLen() const { return arrlen; }
};


// 문제2
class BoundCheck2DIntArray
{
private:
	int** arr;
public:
	BoundCheck2DIntArray(int y, int x)
	{
		arr = new int*[y];

		for (int i = 0; i < y; i++)
		{
			arr[i] = new int[x];
		}
	}

	int* operator[](int n)
	{
		return arr[n];
	}


};
int main()
{
	BoundCheckPointArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i] << ' ';
	delete arr[0];
	delete arr[1];
	delete arr[2];

	BoundCheck2DIntArray arr2d(3,4);



	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			arr2d[n][m] = n + m;
		}
	}
	cout << "----------------------" << endl;
	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			cout << arr2d[n][m] << ' ';
		}
		cout << endl;
	}
}