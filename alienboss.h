#ifndef ALIENBOSS_H
#define ALIENBOSS_H

#include "enemy.h"

class AlienBoss :public Enemy
{
public:
	AlienBoss(int, int);
	virtual ~AlienBoss();

	virtual void autoMove();
};

#endif