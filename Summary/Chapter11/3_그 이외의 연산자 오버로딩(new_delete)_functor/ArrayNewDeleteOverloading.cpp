#include <iostream>
using namespace std;


class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	~Point() { cout << "~Point\n"; }
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new(size_t size)
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void* operator new[](size_t size)
	{
		cout << "operator new [] : " << size << endl;
		void* adr = new char[size];
		return adr;
	}

	void operator delete (void* adr)
	{
		cout << "operator delete ()" << endl;
		delete[] adr;
	}

	void operator delete [] (void* adr)
	{
		cout << "operator delete [] ()" << endl;
		delete[] adr;
	}
};

ostream& operator<< (ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main()
{
	Point* ptr = new Point(3, 4);

	Point* arr = new Point[3];

	delete ptr;
	delete[] arr;
	return 0;
}