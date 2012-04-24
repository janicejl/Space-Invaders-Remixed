#include "enemy.h"
//#include "oneup.h"
#include <iostream>

using namespace std;

Enemy::Enemy(QString filename, int xD, int yD)
{
	image.load(filename);
	rect = image.rect();
	destroyed = false;
	xDir = xD;
	yDir = yD;
/*
	int randomNum = rand() % 3;

	if (randomNum == 0)
	{
		powerup = new Powerup();
	}
	else if (randomNum == 1)
	{
		powerup = new Oneup();
	}
	//else if (randomNum == 2)
*/
}

Enemy::~Enemy()
{
	delete weapon;
	cout<<"Enemy deleted"<<endl;
}

void Enemy::resetState()
{
	rect.moveTo(30,30);
	destroyed = false;
}

void Enemy::setPosition(int x, int y)
{
	rect.moveTo(x,y);
}

bool Enemy::isDestroyed()
{
	return destroyed;
}

void Enemy::setDestroyed(bool d)
{
	destroyed = d;
}

QRect Enemy::getRect()
{
	return rect;
}

void Enemy::setRect(QRect r)
{
	rect = r;
}

QImage & Enemy::getImage()
{
	return image;
}

int Enemy::getXDir()
{
	return xDir;
}
void Enemy::setXDir(int xD)
{
	xDir = xD;
}
int Enemy::getYDir()
{
	return yDir;
}
void Enemy::setYDir(int yD)
{
	yDir = yD;
}

void Enemy::autoMove()
{
	rect.translate(xDir, yDir);
}

void Enemy::moveBottom(int b)
{
	rect.moveBottom(b);
}

void Enemy::moveTop(int t)
{
	rect.moveTop(t);
}

void Enemy::moveLeft(int l)
{
	rect.moveLeft(l);
}

void Enemy::moveRight(int r)
{
	rect.moveRight(r);
}

Weapon* Enemy::getWeapon()
{
	return weapon;
}
void Enemy::releaseWeapon()
{
	weapon->setPosition(((int)(rect.left() + rect.right())/2), ((int)(rect.top() + rect.bottom())/2));
	weapon->setActive(true);
}
/*
Powerup* Enemy::getPowerup()
{
	return powerup;
}

void Enemy::releasePowerup()
{
	powerup->setPosition(((int)(rect.left() + rect.right())/2), ((int)(rect.top() + rect.bottom())/2));
	powerup->setActive(true);
}
*/