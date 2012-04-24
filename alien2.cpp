#include "alien2.h"
#include "iostream"

#include <ctime>

using namespace std;



AlienTwo::AlienTwo(int x, int y) : Enemy("alien2.png", 1, 1)
{
	rect.moveTo(x,y);

	weapon = new BombTwo();
}

AlienTwo::~AlienTwo()
{
	cout<<"AlienTwo deleted."<<endl;
}

void AlienTwo::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.left() <= 0)
	{
		xDir = 1;
	}
	if (rect.right() >= 600)
	{
		xDir = -1;
	}
	if (rect.top() <= 0)
	{
		yDir = 1;
	}
	if (rect.bottom() >= 350)
	{
		yDir = -1;
	}
}