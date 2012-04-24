#ifndef SHOOTER_H
#define SHOOTER_H

#include <QImage>
#include <QRect>

class Shooter
{
public:
	Shooter();
	~Shooter();

	void resetState();
	void moveLeft(int);
	void moveRight(int);
	QRect getRect();
	QImage & getImage();

private:
	QImage image;
	QRect rect;
};

#endif