#ifndef BOMB_H
#define BOMB_H

#include "weapon.h"

class Bomb : public Weapon
{
public:
	Bomb();
	virtual ~Bomb();

	/*void setPosition(int, int);

	void resetState();
	bool isActive();
	void setActive(bool);
	QRect getRect();
	void setRect(QRect);
	QImage & getImage();
*/

	virtual void autoMove();

	/*
	void moveBottom(int);

private:
	QRect rect;
	QImage image;
	bool active;
	*/

	//yDir = 3;

};

#endif