#pragma once

class Point
{
private:
	int x;
	int y;

public:
	Point(int xpos, int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xPos);
	bool SetY(int yPos);
};