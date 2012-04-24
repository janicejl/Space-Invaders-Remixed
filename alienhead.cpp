#include "alienhead.h"

#include <iostream>

using namespace std;

Alienhead::Alienhead() : Weapon("alienhead.png", 0, 7)
{
	//empty
}


Alienhead::~Alienhead()
{
	cout<<"Alienhead deleted"<<endl;
}

void Alienhead::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.bottom() >=340)
	{
		active = false;
	}
}