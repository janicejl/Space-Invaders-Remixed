#ifndef ALIEN3_H
#define ALIEN3_H

#include "enemy.h"
#include "bomb3.h"

class AlienThree :public Enemy
{
public:
	AlienThree(int, int);
	virtual ~AlienThree();

	virtual void autoMove();
};

#endif