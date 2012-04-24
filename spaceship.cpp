#include "spaceship.h"
#include "alienhead.h"

#include <iostream>

using namespace std;

Spaceship::Spaceship(int x, int y) : Enemy("spaceship.png", 1, 0)
{
	rect.moveTo(x, y);

	weapon = new Alienhead();
}

Spaceship::~Spaceship()
{
	cout<<"Spaceship deleted"<<endl;
}

void Spaceship::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.left() <= 0 || rect.right() >=600)
	{
		xDir = 0;
	}
}