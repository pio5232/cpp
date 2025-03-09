#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int xpos, int ypos) : x(xpos), y(ypos) {}

	void ShowMembers()
	{
		cout << "x : " << x << " y : " << y << endl;
	}

	// --- 문제 1
	Point operator-()
	{
		return Point{ x * -1, y * -1 };
	}
	
	// --- 문제 2
	friend Point operator~(const Point&);
	
};
Point operator~(const Point& other)
{
	return Point{ ~other.x, ~other.y };
}

int main()
{
	{
		Point p(10, 20);

		Point p2 = -p;

		cout << "--- 문제 1 ---\n\n";
		p.ShowMembers();
		p2.ShowMembers();
	}

	cout << "\n\n--- 문제 2 -----\n\n";
	{
		Point p(INT_MAX, INT_MAX);
		Point p2(10, 20);
		
		cout << "원래 p : ";
		p.ShowMembers();
		Point reverse = ~p;
		reverse.ShowMembers();
		reverse = ~reverse;
		reverse.ShowMembers();
		cout << "\n\n";

		cout << "원래 p2 : ";
		p2.ShowMembers();
		reverse = ~p2;
		reverse.ShowMembers();
		reverse = ~reverse;
		reverse.ShowMembers();
	}
}