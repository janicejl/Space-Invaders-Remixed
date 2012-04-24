#ifndef BOMB2_H
#define BOMB2_H

#include "weapon.h"

class BombTwo :public Weapon
{
public:
	BombTwo();
	virtual ~BombTwo();

	virtual void autoMove();

};


#endif