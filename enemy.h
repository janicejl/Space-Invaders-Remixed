#ifndef ENEMY_H
#define ENEMY_H

#include <QRect>
#include <QImage>
#include <QString>

#include "weapon.h"
//#include "powerup.h"


class Enemy
{
public:
	Enemy(QString, int, int);
	virtual ~Enemy();

	void resetState();

	void setPosition(int, int);

	bool isDestroyed();
	void setDestroyed(bool);

	QRect getRect();
	void setRect(QRect);
	QImage & getImage();

	int getXDir();
	void setXDir(int);
	int getYDir();
	void setYDir(int);

	virtual void autoMove();

	void moveBottom(int);
	void moveTop(int);
	void moveLeft(int);
	void moveRight(int);

	Weapon* getWeapon();
	void releaseWeapon();

	//Powerup* getPowerup();
	//void releasePowerup();

protected:
	QRect rect;
	QImage image;
	bool destroyed;
	Weapon *weapon;
	//Powerup *powerup;
	int xDir;
	int yDir;

};

#endif