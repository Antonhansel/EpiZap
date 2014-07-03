#include <QtCore>
#include <QFont>
#include <QPainter>
#include <QDesktopServices>
#include <QtWidgets/QApplication>
# include "MainUI.hpp"

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		QApplication	app(argc, argv);

		MainUI	Client(argv[1], argv[2], argv[3]);
		return (app.exec());
	}
	else
	{
		std::cout << "./tester [ip] [port] [team to join]" << std::endl;
		return 1;
	}
}
