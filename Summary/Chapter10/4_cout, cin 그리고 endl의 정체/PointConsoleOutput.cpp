#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
};
istream& operator>>(istream& istr, Point& point)
{
	istr >> point.xpos >> point.ypos;
	return istr;
}
ostream& operator<<(ostream& ostr, const Point& point)
{
	ostr << point.xpos << ", " << point.ypos << endl;
	return ostr;
}

int main()
{
	//Point pos(1, 3);
	//cout << pos;
	//Point pos2(101, 303);

	//cout << pos2;

	Point pos3;
	cout << " x,y ют╥б : ";
	cin >> pos3;

	cout << pos3;

	return 0;
}