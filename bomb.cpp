#include "bomb.h" 
#include <iostream>

using namespace std;

Bomb::Bomb() : Weapon("missile.png", 0, 3)
{
	/*xDir = 1;
	yDir = 0; */
/*
	image.load("bomb.png");
	active = false;
	rect = image.rect();
	rect.translate(10,10); 		*/

	//empty
}

Bomb::~Bomb()
{
	cout<<"Bomb deleted"<<endl;
}
/*
void Bomb::resetState()
{
	rect.moveTo(10,10);
	active = false;
}

void Bomb::setPosition(int xDrop, int yDrop)
{
	rect.moveTo(xDrop+20, yDrop + 40);		//depending on picture size
}	

bool Bomb::isActive()
{
	return active;
}
void Bomb::setActive(bool b)
{
	active = b;
}
QRect Bomb::getRect()
{
	return rect;
}
void Bomb::setRect(QRect r)
{
	rect = r;
}
QImage & Bomb::getImage()
{
	return image;
}
*/

void Bomb::autoMove()
{
	rect.translate(xDir, yDir);

	if (rect.bottom() > 340)
	{	
		active = false;
	}
}

/*
void Bomb::moveBottom(int bottom)
{
	rect.moveBottom(bottom);
}
*/