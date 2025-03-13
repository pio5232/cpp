#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <typename T>
class SimpleDataWrapper
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data) : mdata(data) {}
	void ShowDataInfo()
	{
		cout << "Data : " << mdata << endl;
	}
};

template<>
class SimpleDataWrapper<char*>
{
private:
	char* mdata;
public:
	SimpleDataWrapper(const char* data)
	{
		mdata = new char[strlen(data) + 1];
		strcpy(mdata, data);
	}
	void ShowDataInfo()
	{
		cout << "String : " << mdata << endl;
		cout << "Length : " << strlen(mdata) << endl;
	}
	~SimpleDataWrapper() { delete[] mdata; }
};

template <>
class SimpleDataWrapper<Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{
	}
	void ShowDataInfo()
	{
		mdata.ShowPosition();
	}
};

int main()
{
	SimpleDataWrapper<int> iwrap(170);
	iwrap.ShowDataInfo();
	SimpleDataWrapper<char*> swrap("class template specialization");
	swrap.ShowDataInfo();

	SimpleDataWrapper<Point<int>> poswrap(3, 87);
	poswrap.ShowDataInfo();

	return 0;
}
