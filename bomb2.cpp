#include "bomb2.h"
#include <iostream>

using namespace std;

BombTwo::BombTwo() : Weapon("bomb.png", 0, 2)
{
	//empty
}

BombTwo::~BombTwo()
{
	cout<<"BombTwo deleted."<<endl;
}

void BombTwo::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.top() <= 10)
	{
		active = false;
	}
	if (rect.bottom() >= 340)
	{
		active  = false;
	}
	if (rect.right() <= 1 || rect.left() >= 599)
	{
		active = false;
	}

}