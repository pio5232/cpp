#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int xpos, int ypos) :x(xpos), y(ypos) {}

	void ShowMember()
	{
		cout << " x : " << x << " y : " << y << "\n";
	}
	// --- 문제 1 --- 
	Point operator-(const Point& other)
	{
		cout << "멤버 -연산자\n";

		return Point{ x - other.x, y - other.y };
	}

	friend Point operator-(const Point&, const Point&);

	// --- 문제 2
	Point& operator+= (const Point& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Point& operator-= (const Point& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	// --- 문제 3
	friend bool operator==(const Point&, const Point&);
	friend bool operator!=(const Point&, const Point&);

};

// --- 문제 1
Point operator-(const Point& o1, const Point& o2)
{
	cout << "멤버 -연산자\n";

	return Point{ o1.x - o2.x, o1.y - o2.y };
}

// --- 문제 3
bool operator ==(const Point& o1, const Point& o2)
{
	return o1.x == o2.x && o1.y == o2.y;
}

bool operator !=(const Point& o1, const Point& o2)
{
	return !(o1 == o2);
}



int main()
{
	Point p1(10, 10);
	Point p2(5, 5);
	
	cout << "-------------------    문제 1    ------------------\n";
	cout << endl;
	Point p3 = p1 - p2;
	p3.ShowMember();
	cout << endl;
	cout << "-------------------    문제 2    ------------------\n";
	cout << endl;
	
	cout << "----------    += 하기 전  ----------\n";
	p1.ShowMember();
	p1 += p2;
	cout << "----------    += 한 후    ----------\n";
	p1.ShowMember();
	cout << endl;

	cout << "----------    -= 하기 전  ----------\n";
	p1.ShowMember();
	p1 -= p2;
	cout << "----------    -= 한 후    ----------\n";
	p1.ShowMember();
	cout << endl;

	cout << "-------------------    문제 3    ------------------\n";
	cout << endl;

	std::cout << " p1 == p2  >>>>>   [" << (p1 == p2) << "]\n";
	std::cout << " p1 != p2  >>>>>   [" << (p1 != p2) << "]\n";

	cout << endl;
	std::cout << " p1 == p1  >>>>>   [" << (p1 == p1) << "]\n";
	std::cout << " p1 != p1  >>>>>   [" << (p1 != p1) << "]\n";

}