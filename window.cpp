#include "window.h"
#include <QGridLayout>


Window::Window()
{
	game = new SpaceInvaders(this);

	score = new QLCDNumber(5);
	score->setSegmentStyle(QLCDNumber::Filled);

	level = new QLCDNumber(2);
	level->setSegmentStyle(QLCDNumber::Filled);

	lives = new QLCDNumber(2);
	lives->setSegmentStyle(QLCDNumber::Filled);

	startButton = new QPushButton(tr("&Start"));
	startButton->setFocusPolicy(Qt::NoFocus);

	quitButton = new QPushButton(tr("&Quit"));
	quitButton->setFocusPolicy(Qt::NoFocus);

	pauseButton = new QPushButton(tr("&Pause"));
	pauseButton->setFocusPolicy(Qt::NoFocus);

	connect(startButton, SIGNAL(clicked()), game, SLOT(startGame()));
    connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pauseButton, SIGNAL(clicked()), game, SLOT(pauseGame()));
    connect(game, SIGNAL(scoreChanged(int)), score, SLOT(display(int)));
    connect(game, SIGNAL(levelChanged(int)), level, SLOT(display(int)));
    connect(game, SIGNAL(livesChanged(int)), lives, SLOT(display(int)));

	QGridLayout *layout = new QGridLayout;
    /*layout->addWidget(createLabel(tr("LEVEL")), 0, 0);
    layout->addWidget(level, 1, 0);
    layout->addWidget(startButton, 6, 0);
    layout->addWidget(game, 0, 2, 6, 2 );
    layout->addWidget(createLabel(tr("SCORE")), 2, 1);
    layout->addWidget(score, 3, 0);
    layout->addWidget(quitButton, 7, 0);
    layout->addWidget(pauseButton, 6, 1); */

    layout->addWidget(game, 0, 0, 10, 3, 0);
    layout->addWidget(score, 11, 0, 0);
    layout->addWidget(level, 11, 1, 0);
    layout->addWidget(lives, 11, 2, 0);
    layout->addWidget(createLabel(tr("Score")), 12, 0, 0);
    layout->addWidget(createLabel(tr("Level")), 12, 1, 0);
    layout->addWidget(createLabel(tr("Lives")), 12, 2, 0);
    layout->addWidget(startButton, 13, 0, 0);
    layout->addWidget(pauseButton, 13, 1, 0);
    layout->addWidget(quitButton, 13, 2, 0);
    layout->setRowStretch(0, 30);
    layout->setRowStretch(11, 3);
    layout->setRowStretch(12, 0);
    layout->setRowStretch(13, 3);

    setLayout(layout);



    setWindowTitle(tr("Space Invaders"));
    //resize(640, 500);
    setFixedSize(640, 500);
}




QLabel *Window::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}

