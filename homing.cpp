#include "homing.h"
#include <iostream>

using namespace std;

Homing::Homing() :Weapon("homing.png", 0, 3)
{
	//empty
}

Homing::~Homing()
{
	cout<<"Homing destroyed."<<endl;
}

void Homing::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.left() <= 0 || rect.right() >=600 || rect.top() <=0 || rect.bottom() >=350)
		active = false;

}