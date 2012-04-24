#ifndef BOMB3_H
#define BOMB3_H

#include "weapon.h"


class BombThree :public Weapon
{
public:
	BombThree();
	virtual ~BombThree();

	virtual void autoMove();
};

#endif