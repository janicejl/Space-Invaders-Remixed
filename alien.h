#ifndef ALIEN_H
#define ALIEN_H

#include "weapon.h"
#include "bomb.h"
#include "enemy.h"


class Alien :public Enemy
{
public:
	Alien(int, int);
	virtual ~Alien();

	/*void resetState();
	bool isDestroyed();
	void setDestroyed(bool);
	QRect getRect();
	void setRect(QRect);
	QImage & getImage();

	int getXDir();
	void setXDir(int);
	int getYDir();
	void setYDir(int);
*/
	virtual void autoMove();
/*
	void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int); 

    Bomb* getBomb();
    void releaseBomb();

private:
	QRect rect;
	QImage image; 
	int position;
	bool destroyed;
	int xDir;
	int yDir;

	Bomb *bomb;*/

};

#endif