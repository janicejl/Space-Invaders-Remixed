#ifndef BULLET_H
#define BULLET_H

#include "weapon.h"

class Bullet : public Weapon
{
public:
	Bullet();
	virtual ~Bullet();

	/*void setPosition(int);

	void resetState();
	bool isActive();
	void setActive(bool);
	QRect getRect();
	void setRect(QRect);
	QImage & getImage();
*/
	virtual void autoMove();
/*
	void moveTop(int);
*/
private:
	/*QRect rect;
	QImage image;
	bool active;
	
*/
	//yDir = -2;

};

#endif