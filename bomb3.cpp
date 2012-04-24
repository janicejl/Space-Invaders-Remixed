#include "bomb3.h"
#include <iostream>

using namespace std;

BombThree::BombThree() :Weapon ("dynamite.png", 0, 1)
{
	//empty
}

BombThree::~BombThree()
{
	cout<<"BombThree deleted."<<endl;
}

void BombThree::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.bottom() > 345)
		active = false;
}