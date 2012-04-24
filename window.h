#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <QFrame>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QLCDNumber>
#include <QLabel>

#include "spaceinvaders.h"

class Window : public QWidget
{
	Q_OBJECT

public:
	Window();

private:
	QLabel *createLabel(const QString &text);

	SpaceInvaders *game;
	QLCDNumber *score;
	QLCDNumber *level;
	QLCDNumber *lives;
	QPushButton *startButton;
	QPushButton *quitButton;
	QPushButton *pauseButton;
};


#endif