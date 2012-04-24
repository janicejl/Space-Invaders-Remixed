#ifndef HOMING_H
#define HOMING_H

#include "weapon.h"

class Homing :public Weapon
{
public:
	Homing();
	virtual ~Homing();

	virtual void autoMove();
};

#endif