#include "shooter.h"
#include <iostream>

using namespace std;

Shooter::Shooter()
{
	image.load("shooter.png");

	rect = image.rect();
	resetState();
}

Shooter::~Shooter()
{
	cout<<"Shooter deleted"<<endl;
}

void Shooter::resetState()
{
	rect.moveTo(200,320); 		//have to change for different windows size. 
}

void Shooter::moveLeft(int left)
{
	if (rect.left() >= 2)
		rect.moveTo(left, rect.top());
}

void Shooter::moveRight(int right)
{
	if(rect.right() <= 598)		//Have to change for different windows size. 
		rect.moveTo(right, rect.top());
}

QRect Shooter::getRect()
{
	return rect;
}

QImage & Shooter::getImage()
{
	return image;
}