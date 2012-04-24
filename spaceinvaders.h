#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include "shooter.h"
#include "alien.h"
#include "bullet.h"
#include "alien2.h"
#include "alienboss.h"
#include "alien3.h"
#include "spaceship.h"
//#include "bomb.h"
#include <QWidget>
#include <QKeyEvent>

class SpaceInvaders : public QWidget
{
	Q_OBJECT

public:
	SpaceInvaders(QWidget *parent = 0);
	~SpaceInvaders();

protected:
	void paintEvent(QPaintEvent *event);
	void timerEvent(QTimerEvent *event);
	void keyPressEvent(QKeyEvent *event);

	void victory();
	void checkCollision();

public slots:
	void startGame();
	void pauseGame();
	void stopGame();

signals:
	void scoreChanged(int);
	void levelChanged(int);
	void livesChanged(int);

private:
	int xShooter;
	int timerId;
	int level;
	int score;
	int lives;
	Shooter *shooter;
	Alien *alien[5];
	AlienTwo *alientwo[3];
	Spaceship *spaceship;
	AlienThree *alienthree[4];
	AlienBoss *boss;
	Bullet *bullet;
	//Bomb *bomb;
	bool gameOver;
	bool gameWon;
	bool gameStarted;
	bool paused;
};

#endif