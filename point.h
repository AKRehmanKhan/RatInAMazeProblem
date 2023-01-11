#pragma once
#include<iostream>
using namespace std;
const int MAX_X = 1000;
const int MAX_Y = 1000;

//-------------------------------POINT CLASS------------------------------//
//initialize MaxPoint
class point
{
public:
	point() { x = 0; y = 0; }
	point(int a, int b) { x = a; y = b; }
	int getX() { return x; }
	int getY() { return y; }
	void set(int a, int b) { x = a; y = b; }
	void setX(int a) { x = a; }
	void setY(int b) { y = b; }
	void setMaxPoint(int a, int b) { MaxPoint.x = a; MaxPoint.y = b; }
	int getMaxPointX() { return MaxPoint.x; }
	int getMaxPointY() { return MaxPoint.y; }
	//increment x-coordinate.  If max limit is reached then increment y and set x to zero
	//return false if max limit for x and y is reached
	bool incrementX();
	//increment y-coordinate.  If max limit is reached return false
	bool incrementY();
	//decrement x-coordinate.  If x is already at 0 then go to line above at last x (decrement y)
	//return false if both x and y are at 0
	bool decrementX();
	//decrement y-coordinate.  If y is already at 0 then return false
	bool decrementY();
private:
	static point MaxPoint;
	int x;
	int y;

};

point point::MaxPoint(MAX_X, MAX_Y);
bool point::incrementX()
{
	bool returnValue = true;
	if (x < MaxPoint.x)
	{
		x++;

	}
	else if (y < MaxPoint.y)
	{
		x = 0;
		y = y + 1;
	}
	else
		returnValue = false;

	return returnValue;
}

bool point::incrementY()
{
	bool returnValue = true;
	if (y < MaxPoint.y)
		y++;
	else
		returnValue = false;

	return returnValue;

}
bool point::decrementX()
{
	bool returnValue = true;
	if (x > 0)
		x--;
	else if (y > 0)
	{
		y--;
		x = MaxPoint.x;
	}
	else
		returnValue = false;

	return returnValue;
}
bool point::decrementY()
{
	bool returnValue = true;
	if (y > 0)
		y--;
	else
		returnValue = false;

	return returnValue;

}

//-------------------------------END OF POINT CLASS------------------------------------------------//
