#ifndef ALIENHEAD_H
#define ALIENHEAD_H

#include "weapon.h"

class Alienhead :public Weapon
{
public:
	Alienhead();
	virtual ~Alienhead();

	virtual void autoMove();
};

#endif