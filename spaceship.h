#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "enemy.h"

class Spaceship :public Enemy
{
public:
	Spaceship(int, int);
	virtual ~Spaceship();

	virtual void autoMove();
};

#endif