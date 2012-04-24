#ifndef ALIEN2_H
#define ALIEN2_H

#include "enemy.h"
#include "bomb2.h"

class AlienTwo :public Enemy
{
public:
	AlienTwo(int, int);
	virtual ~AlienTwo();

	virtual void autoMove();

};

#endif