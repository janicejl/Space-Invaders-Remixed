#include "alien.h"
#include <iostream>

using namespace std;

Alien::Alien(int x, int y) : Enemy("alien.png", 1, 0)
{
	rect.translate(x,y);

	weapon = new Bomb();

	/*xDir = 1;
	yDir = 0;

	image.load("alien.png");
	destroyed = false;
	rect = image.rect();
	rect.translate(x,y);

	bomb = new Bomb();
	//resetState(); 
	*/
}

Alien::~Alien()
{
	//delete weapon;
	cout<<"Alien deleted"<<endl;
}
/*
void Alien::resetState()
{
	rect.moveTo(30,10); 		//have to change for different windows size. 
	destroyed = false;
} 

bool Alien::isDestroyed()
{
	return destroyed;
}

void Alien::setDestroyed(bool d)
{
	destroyed = d;
}

QRect Alien::getRect()
{
	return rect;
}

void Alien::setRect(QRect r)
{
	rect = r;
}

QImage & Alien::getImage()
{
	return image;
}


int Alien::getXDir()
{
	return xDir;
}

void Alien::setXDir(int xd)
{
	xDir = xd;
}

int Alien::getYDir()
{
	return yDir;
}

void Alien::setYDir(int yd)
{
	yDir = yd;
}
*/

void Alien::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.left() == 0)
	{	
		xDir = 1;
		yDir = 30;
	}
	if (rect.right() == 598)		//need to change if window size change
	{
		xDir = -1;
		yDir = 30;
	}
	if (rect.left() != 0 && rect.right() != 598)
		yDir = 0;
}

/*
void Alien::moveBottom(int b)
{
	rect.moveBottom(b);
}

void Alien::moveTop(int t)
{
	rect.moveTop(t);
}

void Alien::moveLeft(int l)
{
	rect.moveLeft(l);
}

void Alien::moveRight(int r)
{
	rect.moveRight(r);
}


Bomb* Alien::getBomb()
{
	return bomb;
}

void Alien::releaseBomb()
{
	bomb->setPosition(rect.x() + 20, rect.y() + 30);
	bomb->setActive(true);

}
*/