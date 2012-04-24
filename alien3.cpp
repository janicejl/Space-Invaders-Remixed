#include "alien3.h"
#include "bomb3.h"
#include "enemy.h"
#include <iostream>

using namespace std;

AlienThree::AlienThree(int x, int y) : Enemy("alien3.png", 2, 0)
{
	rect.moveTo(x,y);

	weapon = new BombThree();
}


AlienThree::~AlienThree()
{
	cout<<"AlienThree deleted."<<endl;
}

void AlienThree::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.left() <= 0 || rect.right()>= 600)
	{
		xDir = -xDir;

		yDir = 30;
	}
	else 
		yDir = 0;
}