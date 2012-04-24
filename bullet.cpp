#include "bullet.h" 
#include <iostream>

using namespace std;

Bullet::Bullet() : Weapon("bullet.png", 0, -2)
{
	//empty
}

Bullet::~Bullet()
{
	cout<<"Bullet deleted"<<endl;
}

/*Bullet::Bullet()
{
	//xDir = 1;
	//yDir = 0; 

	image.load("bullet.png");
	active = false;
	rect = image.rect();
	rect.translate(10,10); 		//To let the bullet come out of the middle of shooter. 
}

Bullet::~Bullet()
{
	cout<<"Bullet deleted"<<endl;
}

void Bullet::resetState()
{
	rect.moveTo(10,10);
	active = false;
}

void Bullet::setPosition(int xShotPosition)
{
	rect.moveTo(xShotPosition+20, 320);
}

bool Bullet::isActive()
{
	return active;
}
void Bullet::setActive(bool b)
{
	active = b;
}
QRect Bullet::getRect()
{
	return rect;
}
void Bullet::setRect(QRect r)
{
	rect = r;
}
QImage & Bullet::getImage()
{
	return image;
}
*/

void Bullet::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.top() == 10)
		active = false;
}

/*
void Bullet::moveTop(int top)
{
	rect.moveTop(top);
} 
*/