#ifndef WEAPON_H
#define WEAPON_H

#include <QRect>
#include <QImage>

#include <QString>

using namespace std;


class Weapon
{
public:
	Weapon(QString, int, int);
	virtual ~Weapon();

	void setPosition(int, int);

	void resetState();

	bool isActive();
	void setActive(bool);

	QRect getRect();
	void setRect(QRect);
	QImage & getImage();

	void moveTop(int);
	void moveBottom(int);
	void moveRight(int);
	void moveLeft(int);

	virtual void autoMove();

	int getXDir();
	void setXDir(int);
	int getYDir();
	void setYDir(int);

protected:
	QRect rect;
	QImage image;
	bool active;
	int xDir;
	int yDir;
};

#endif