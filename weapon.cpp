#include "weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon(QString filename, int xD, int yD)
{
	image.load(filename);
	rect = image.rect();
	active = false;
	xDir = xD;
	yDir = yD;
}

Weapon::~Weapon()
{
	cout<<"Weapon deleted."<<endl;
}


void Weapon::setPosition(int xPos, int yPos)
{
	rect.moveTo(xPos, yPos);
}

void Weapon::resetState()
{
	rect.moveTo(10,10);
	active = false;
}

bool Weapon::isActive()
{
	return active;
}
void Weapon::setActive(bool b)
{
	active = b;
}

QRect Weapon::getRect()
{
	return rect;
}
void Weapon::setRect(QRect r)
{
	rect = r;
}
QImage & Weapon::getImage()
{
	return image;
}

void Weapon::moveTop(int top)
{
	rect.moveTop(top);
}
void Weapon::moveBottom(int bottom)
{
	rect.moveBottom(bottom);
}
void Weapon::moveRight(int right)
{
	rect.moveRight(right);
}
void Weapon::moveLeft(int left)
{
	rect.moveLeft(left);
}

void Weapon::autoMove()
{
	rect.translate(xDir, yDir);

	/**if (rect.top() <= 10)
	{
		active = false;
	}
	if (rect.bottom() >= 340)
	{
		active  = false;
	}
	if (rect.right() <= 1 || rect.left() >= 599)
	{
		xDir = -xDir;
	} */
}

int Weapon::getXDir()
{
	return xDir;
}
void Weapon::setXDir(int xD)
{
	xDir = xD;
}
int Weapon::getYDir()
{
	return yDir;
}
void Weapon::setYDir(int yD)
{
	yDir = yD;
}

