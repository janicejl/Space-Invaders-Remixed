#include "spaceinvaders.h"
#include "window.h"

#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget)
{
	int x;
	int y;
	int screenWidth;
	int screenHeight;

	int WIDTH = 600;
	int HEIGHT = 350;

	QDesktopWidget *desktop = QApplication::desktop();

	screenHeight = desktop->height();
	screenWidth = desktop->width();

	x = (screenWidth - WIDTH) / 2;
	y = (screenHeight - HEIGHT) / 2;

	widget.setGeometry(x, y, WIDTH, HEIGHT);
	widget.setFixedSize(WIDTH, HEIGHT);

	//widget.setStyleSheet("QWidget { background-color: black; }");		//changing background colour
}

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);

	Window window;

//srand(time(0));

	//window.setWindowTitle("Space Invaders");
	window.show();
	//center(window);

	return app.exec();
}