#include "spaceinvaders.h"
#include <QPainter>
#include <QApplication>

#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

SpaceInvaders::SpaceInvaders(QWidget *parent) : QWidget(parent)
{
	setFocusPolicy(Qt::StrongFocus);

	xShooter = 0;
	gameOver = false;
	gameWon = false;
	paused = false;
	gameStarted = false;

	level = 1; 		//testing
	score = 0;
	lives = 5;

	shooter = new Shooter();
	bullet = new Bullet();
	//bomb = new Bomb();

	for (int i=0; i < 5; i++)
	{
		alien[i] = new Alien(150 + 50*i, 50);
	}

	alientwo[0] = new AlienTwo(150, 50);
	alientwo[1] = new AlienTwo(350, 50);
	alientwo[2] = new AlienTwo(550, 50);

	spaceship = new Spaceship(((int)((shooter->getRect().left() + shooter->getRect().right()) / 2)), 30 );

	for (int i=0; i<4; i++)
	{
		alienthree[i] = new AlienThree(150, 100 + 30*i);

		if (i%2 == 0)
		{
			alienthree[i]->setXDir(2);
		}
		else 
		{
			alienthree[i]->setXDir(-2);
		}

	}

	boss = new AlienBoss(100, 40);

	setPalette(QPalette(QColor(0, 0, 0, 255)));
  	setAutoFillBackground(true);

}

SpaceInvaders::~SpaceInvaders()
{
	delete shooter;
	for (int i=0; i<5; i++)
	{	
		delete alien[i];
	}
	for (int i=0; i<3; i++)
	{
		delete alientwo[i];
	}
	delete spaceship;
	for (int i=0; i<4; i++)
	{
		delete alienthree[i];
	}
	delete boss;
	delete bullet;
}

void SpaceInvaders::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);


	if (gameOver) 
	{
	  QFont font("Courier", 15, QFont::DemiBold);
	  QFontMetrics fm(font);
	  int textWidth = fm.width("Game Over");

	  painter.setFont(font);
	  int h = 350;
	  int w = 600;

	  painter.drawText((w/2)-textWidth/2, h/2, "Game Over");
	}
	else if(gameWon) 
	{
		QFont font("Courier", 15, QFont::DemiBold);
		QFontMetrics fm(font);
		

		painter.setFont(font);
		int h = 350;//height();
		int w = 600;//width();
		
		
		if (level <= 3)
		{	
			int textWidth = fm.width("Level Up");
			painter.drawText((w/2)-textWidth/2, h/2, "Level Up");
			startGame();
		}
		else 
		{
			int textWidth = fm.width("Victory!");
			painter.drawText((w/2)-textWidth/2, h/2, "Victory!");
		}

	}
	else 
	{

		painter.drawImage(shooter->getRect(), shooter->getImage());
		if (bullet->isActive() == true)
		{
			painter.drawImage(bullet->getRect(), bullet->getImage());
		}

		if (level == 1)
		{
			for (int i=0; i<5; i++)
			{
				if (alien[i]->isDestroyed() == false)
				{
					painter.drawImage(alien[i]->getRect(), alien[i]->getImage());
				}

				if ((alien[i]->getWeapon()->isActive() == true) && (alien[i]->isDestroyed() == false) )
				{
					painter.drawImage(alien[i]->getWeapon()->getRect(), alien[i]->getWeapon()->getImage());
				}

				/*
				if (alien[i]->getPowerup()->getType() != "powerup")
				{
					if ((alien[i]->getPowerup()->isActive() == true) && (alien[i]->isDestroyed() == true))
					{
						painter.drawImage(alien[i]->getPowerup()->getRect(), alien[i]->getPowerup()->getImage());
					}
				} */
			}
		}
		else if (level == 2) 
		{
			for (int i=0; i<3; i++)
			{
				if (alientwo[i]->isDestroyed() == false)
				{
					painter.drawImage(alientwo[i]->getRect(), alientwo[i]->getImage());
				}

				if ((alientwo[i]->getWeapon()->isActive() == true) && (alientwo[i]->isDestroyed() == false))
				{
					painter.drawImage(alientwo[i]->getWeapon()->getRect(), alientwo[i]->getWeapon()->getImage());
				}
			}

			if (spaceship->isDestroyed() == false)
			{
				painter.drawImage(spaceship->getRect(), spaceship->getImage());
			}
			if ((spaceship->getWeapon()->isActive() == true) && (spaceship->isDestroyed() == false))
			{
				painter.drawImage(spaceship->getWeapon()->getRect(), spaceship->getWeapon()->getImage());
			}
		}
		else 
		{
			if (boss->isDestroyed() == false)
			{
				painter.drawImage(boss->getRect(), boss->getImage());
			}

			if ((boss->getWeapon()->isActive() == true) && (boss->isDestroyed() == false))
			{
				painter.drawImage(boss->getWeapon()->getRect(), boss->getWeapon()->getImage());
			}

			for (int i=0; i<4; i++)
			{
				if (alienthree[i]->isDestroyed() == false)
				{
					painter.drawImage(alienthree[i]->getRect(), alienthree[i]->getImage());
				}

				if ((alienthree[i]->getWeapon()->isActive() == true) && (alienthree[i]->isDestroyed() == false))
				{
					painter.drawImage(alienthree[i]->getWeapon()->getRect(), alienthree[i]->getWeapon()->getImage());
				}
			}

		}
	}
}

void SpaceInvaders::timerEvent(QTimerEvent *event)
{
	
	if (bullet->isActive() == true)
	{
		bullet->autoMove();
	}

	srand(time(0));

	if (level == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			alien[i]->autoMove();

			if ((rand()% 5 == 0) && (alien[i]->getWeapon()->isActive() == false))		//change for randomness of bomb fall time
			{
				alien[i]->releaseWeapon();
			} 
			if ((alien[i]->getWeapon()->isActive() == true) && (alien[i]->isDestroyed() == false))
			{
				alien[i]->getWeapon()->autoMove();
			}

/*
			if ((alien[i]->getPowerup()->isActive()== true) && (alien[i]->isDestroyed() == true))
			{
				alien[i]->getPowerup()->autoMove();
			} */
		}
	}
	else if (level == 2) 
	{
		for (int i=0; i<3; i++)
		{
			alientwo[i]->autoMove();

			if ((rand()%3 == 0) && (alientwo[i]->getWeapon()->isActive() == false))
			{
				alientwo[i]->releaseWeapon();

				if ((shooter->getRect().x() - alientwo[i]->getRect().x()) == 0)
				{
					alientwo[i]->getWeapon()->setXDir(0);
				}
				else if ((shooter->getRect().x() - alientwo[i]->getRect().x()) > 0)
				{	
					alientwo[i]->getWeapon()->setXDir((shooter->getRect().x() - alientwo[i]->getRect().x())
														/((shooter->getRect().x() - alientwo[i]->getRect().x())));
				}
				else 
				{
					alientwo[i]->getWeapon()->setXDir((shooter->getRect().x() - alientwo[i]->getRect().x())
														/((-1)*(shooter->getRect().x() - alientwo[i]->getRect().x())));
														///((shooter->getRect().y() - alientwo[i]->getRect().y()) + 1));

				}

				if ((shooter->getRect().y() - alientwo[i]->getRect().y()) == 0)
				{
					alientwo[i]->getWeapon()->setYDir(0);
				}
				else if ((shooter->getRect().y() - alientwo[i]->getRect().y()) > 0)
				{
					alientwo[i]->getWeapon()->setYDir((shooter->getRect().y() - alientwo[i]->getRect().y())
														/(shooter->getRect().y() - alientwo[i]->getRect().y()));
				}
				else 
				{
					alientwo[i]->getWeapon()->setYDir((shooter->getRect().y() - alientwo[i]->getRect().y())
														/((-1)*shooter->getRect().y() - alientwo[i]->getRect().y()));
															///((shooter->getRect().x() - alientwo[i]->getRect().x()) + 1));
				}

			}
			if ((alientwo[i]->getWeapon()->isActive() == true) && (alientwo[i]->isDestroyed() == false))
			{
				alientwo[i]->getWeapon()->autoMove();
			}
		}

		if ((spaceship->getWeapon()->isActive() == false) && (rand()% 25 == 0))
		{
			spaceship->releaseWeapon();
		}
		if ((spaceship->getWeapon()->isActive() == true) && (spaceship->isDestroyed() == false))
		{
			spaceship->getWeapon()->autoMove();
		}

	}
	else 
	{
		boss->autoMove();

		if ((boss->getRect().left() < shooter->getRect().left()) && (boss->getRect().right() > shooter->getRect().right())
			&& (boss->getWeapon()->isActive() == false))
		{
			boss->releaseWeapon();
		}

		if (boss->getWeapon()->isActive() == true)
		{
			boss->getWeapon()->autoMove();
		}

		for (int i=0; i<4; i++)
		{
			alienthree[i]->autoMove();


			if ((alienthree[i]->getRect().left() ==  shooter->getRect().left())
				&& (alienthree[i]->getWeapon()->isActive() == false))
			{
				alienthree[i]->releaseWeapon();
			}

			if ((alienthree[i]->getWeapon()->isActive() == true) && (alienthree[i]->isDestroyed() == false))
			{
				alienthree[i]->getWeapon()->autoMove();
			}
		}
	}
	
	checkCollision();
	repaint();
}

void SpaceInvaders::keyPressEvent(QKeyEvent *event)
{
	switch(event->key())
	{
		case Qt::Key_Left:
			{	
				int xShooter = shooter->getRect().x();
				for (int i = 0; i < 10; i++)
				{
					shooter->moveLeft(xShooter--);
				}

				if (level == 2)
				{
					int xShip = spaceship->getRect().x();
					for (int i = 0; i < 10; i++)
					{
						spaceship->moveLeft(xShip--);
					}
				}
			}
			break;
		case Qt::Key_Right:
			{
				
				int xShooter = shooter->getRect().x();
				for (int i = 0; i < 10; i++)
				{
					shooter->moveRight(xShooter++);
				}

				if (level == 2)
				{
					int xShip = spaceship->getRect().x();
					for (int i = 0; i < 10; i++)
					{
						//spaceship->moveRight(xShip++);
						spaceship->setPosition(xShip++, 30);
					}
				}
			}
			break;
		case Qt::Key_Up:
			{
				if (bullet->isActive() == false)
				{
					bullet->setPosition(shooter->getRect().x() + 20, 310);
					bullet->setActive(true);
				}
			}
			break;
		case Qt::Key_P:
			{
				pauseGame();
			}
			break;
		case Qt::Key_Space:
			{
				
				if (gameStarted == false)
				{
					level = 1;
					score = 0;
					lives = 5;
				}
				startGame();
			}
			break;
		case Qt::Key_Escape:
			{
				qApp->exit();
			}
			break;
		default:
			QWidget::keyPressEvent(event);
	}
}

void SpaceInvaders::startGame()
{
	if (!gameStarted)
	{
		shooter->resetState();

		for (int i = 0; i < 5; i++)
		{
			alien[i]->setPosition(150 + 50*i, 50);
			alien[i]->setDestroyed(false);
			alien[i]->setXDir(1);
			alien[i]->getWeapon()->setActive(false);
			//alien->resetState();
		}

		for (int i=0; i<3; i++)
		{
			alientwo[i]->setDestroyed(false);
			alientwo[i]->getWeapon()->setActive(false);
		}

		for (int i=0; i<4; i++)
		{
			alienthree[i]->setPosition(150, 100+30*i);
			alienthree[i]->setDestroyed(false);
			alienthree[i]->getWeapon()->setActive(false);
		}
		spaceship->setDestroyed(false);
		boss->setDestroyed(false);


		bullet->resetState();
		//bomb->resetState();


		gameOver = false;
		gameWon = false;
		gameStarted = true;

	    emit scoreChanged(score);
	    emit levelChanged(level);
	    emit livesChanged(lives);

		timerId = startTimer(10);
	}
}

void SpaceInvaders::pauseGame()
{
	if (paused)
	{
		timerId = startTimer(10);
		paused = false;
	}
	else
	{
		paused = true;
		killTimer(timerId);
	}
}

void SpaceInvaders::stopGame()
{
	killTimer(timerId);
	gameOver = true;
	gameStarted = false;
	level = 0;
	score = 0;
	lives = 0;
}

void SpaceInvaders::victory()
{
	killTimer(timerId);
	gameWon = true;
	gameStarted = false;
	level++;
	//emit levelChanged(level);
}

void SpaceInvaders::checkCollision()
{

	if (lives == 0)
	{
		stopGame();
	}

	if (level == 1)
	{
		for (int i=0, j=0; i<5; i++)
		{
			if (alien[i]->isDestroyed() == true)
				j++;
			if (j == 5)
				victory();
		}
	}
	/*else if (level == 2) 
	{
		for (int i=0, j=0; i<3; i++)
		{
			if (alientwo[i]->isDestroyed() == true)
				j++;
			if (j == 3)
				victory();
		}
	} */


	if (!gameOver && level == 1)
	{
		for (int i=0; i<5; i++)
		{
			if ((bullet->getRect().intersects(alien[i]->getRect()) == true) 
				&& (bullet->isActive() == true) && (alien[i]->isDestroyed() == false))
			{
				cout<<"Score increased..."<<endl;
				alien[i]->setDestroyed(true);
				alien[i]->getWeapon()->setActive(false);
				/*if (alien[i]->getPowerup()->getType() != "powerup")
				{
					alien[i]->getPowerup()->setActive(true);
				} */
				bullet->setActive(false);
				bullet->resetState();

				//add score
				score++;
				emit scoreChanged(score);

				//alien->resetState();		//remove later...
			}
		
			if ((alien[i]->getWeapon()->getRect().intersects(shooter->getRect()) == true) 
				&& (alien[i]->getWeapon()->isActive() == true))
			{
				cout<<"Life lost..."<<endl;
				alien[i]->getWeapon()->setActive(false);
				//alien->getWeapon()->resetState();
				//taking away life
				lives--;
				emit livesChanged(lives);

				shooter->resetState();
			}

			if ((alien[i]->getRect().intersects(shooter->getRect()) == true) 
				&& alien[i]->isDestroyed() == false)
			{
				cout<<"Life Lost."<<endl;
				alien[i]->getWeapon()->setActive(false);

				lives--;
				emit livesChanged(lives);

				shooter->resetState();
			}

/*
			if (alien[i]->getPowerup()->getType() != "powerup")
			{
				if (shooter->getRect().intersects(alien[i]->getPowerup()->getRect()) == true)
				{
					cout<<"Powerup"<<endl;

					alien[i]->getPowerup()->setActive(false);

					lives++;
					emit livesChanged(lives);
				}
			}
			*/
		}
	}
	else if (!gameOver && level == 2) 
	{
		for (int i=0; i<3; i++)
		{
			if ((bullet->getRect().intersects(alientwo[i]->getRect()) == true) 
				&& (bullet->isActive() == true) && (alientwo[i]->isDestroyed() == false))
			{
				cout<<"Score increased..."<<endl;
				alientwo[i]->setDestroyed(true);
				alientwo[i]->getWeapon()->setActive(false);
				bullet->setActive(false);
				bullet->resetState();

				//add score
				score++;
				emit scoreChanged(score);

			}
		
			if ((alientwo[i]->getWeapon()->getRect().intersects(shooter->getRect()) == true) 
				&& (alientwo[i]->getWeapon()->isActive() == true))
			{
				cout<<"Life lost..."<<endl;
				alientwo[i]->getWeapon()->setActive(false);
				//alien->getWeapon()->resetState();
				//taking away life
				lives--;
				emit livesChanged(lives);

				shooter->resetState();
				spaceship->setPosition(((int)((shooter->getRect().left() + shooter->getRect().right()) / 2)), 30 );
			}
			
			if ((alientwo[i]->getRect().intersects(shooter->getRect()) == true) 
				&& alientwo[i]->isDestroyed() == false)
			{
				cout<<"Life Lost."<<endl;
				alientwo[i]->getWeapon()->setActive(false);

				lives--;
				emit livesChanged(lives);

				shooter->resetState();
				spaceship->setPosition(((int)((shooter->getRect().left() + shooter->getRect().right()) / 2)), 30 );
			}

		}

		int k = 0;
		for (int i=0; i<3; i++)
		{
			if (alientwo[i]->isDestroyed() == true)
				k++;
		}

		if ((bullet->getRect().intersects(spaceship->getRect()) == true) 
			&& (bullet->isActive() == true) && (spaceship->isDestroyed() == false) && k==3)
		{
			cout<<"Spaceship destroyed"<<endl;
			spaceship->setDestroyed(true);
			bullet->setActive(false);
			bullet->resetState();

			score = score + 10;
			emit scoreChanged(score);

			victory();
		}

		if ((spaceship->getWeapon()->isActive() == true) 
			&& (spaceship->getWeapon()->getRect().intersects(shooter->getRect()) == true) 
			&& (spaceship->isDestroyed() == false))
		{
			cout<<"Unlucky, Life lost."<<endl;
			spaceship->getWeapon()->setActive(false);

			lives--;
			emit livesChanged(lives);

			shooter->resetState();
			spaceship->setPosition(((int)((shooter->getRect().left() + shooter->getRect().right()) / 2)), 30 );
		}

	}
	else if (!gameOver && level == 3)
	{
		int j = 0;
		for (int i=0; i<4; i++)
		{
			if (alienthree[i]->isDestroyed() == true)
				j++;
		}

		if ((bullet->getRect().intersects(boss->getRect()) == true) 
			&& (bullet->isActive() == true) && (boss->isDestroyed() == false) && j==4)
		{
			cout<<"Boss killed.... VICTORY!"<<endl;
			boss->setDestroyed(true);
			bullet->setActive(false);
			bullet->resetState();

			score = score + 100;
			emit scoreChanged(score);

			victory();
		}

		if ((bullet->getRect().intersects(boss->getWeapon()->getRect()) == true)
			&& (bullet->isActive() == true) && (boss->getWeapon()->isActive() == true))
		{
			cout<<"Homing missile destroyed."<<endl;
			bullet->setActive(false);
			bullet->resetState();
			boss->getWeapon()->setActive(false);
		}

		if (((boss->getWeapon()->getRect().intersects(shooter->getRect())) == true) 
			&& (boss->isDestroyed() == false) && (boss->getWeapon()->isActive() == true))
		{
			cout<<"life lost..."<<endl;
			boss->getWeapon()->setActive(false);

			lives--;
			emit livesChanged(lives);

			shooter->resetState();
		}


		for (int i=0; i<4; i++)
		{
			if ((bullet->getRect().intersects(alienthree[i]->getRect()) == true) 
				&& (bullet->isActive() == true) && (alienthree[i]->isDestroyed() == false))
			{
				cout<<"AlienThree Shot"<<endl;
				alienthree[i]->setDestroyed(true);
				bullet->setActive(false);
				bullet->resetState();

				score++;
				emit scoreChanged(score);
			}

			if (((alienthree[i]->getWeapon()->getRect().intersects(shooter->getRect())) == true) 
				&& (alienthree[i]->isDestroyed() == false) && (alienthree[i]->getWeapon()->isActive() == true))
			{
				cout<<"Life Lost."<<endl;
				alienthree[i]->getWeapon()->setActive(false);

				lives--;
				emit livesChanged(lives);

				shooter->resetState();
			}
		}


	}
}






