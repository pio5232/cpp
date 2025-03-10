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

class BoundCheckPointArray
{
private:
	Point* arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr) {}
	BoundCheckPointArray operator= (const BoundCheckPointArray* arr) {}
public:
	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr = new Point[len];
	}
	// -- 문제가 발생한다. ShowAllData에서는 const 형으로 받는데. const 함수가 정의되지 않아서 생기는 문제다.
	Point& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception " << endl;
			exit(1);
		}
		return arr[idx];
	}

	Point operator[] (int idx) const
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

int main()
{
	BoundCheckPointArray arr(3);
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);
}