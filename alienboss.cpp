#include "alienboss.h"
#include "homing.h"
#include <iostream>

using namespace std;


AlienBoss::AlienBoss(int x, int y) : Enemy("alienboss.png", 2, 0)
{
	rect.moveTo(x,y);

	weapon = new Homing();
}

AlienBoss::~AlienBoss()
{
	cout<<"AlienBoss deleted."<<endl;
}

void AlienBoss::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.left() <= 0)
	{
		xDir = -xDir;
	}
	if (rect.right() >= 600)
	{
		xDir = -xDir;
	}

}