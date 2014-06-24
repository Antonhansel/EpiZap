#ifndef _CONNEXION_HPP_
# define _CONNEXION_HPP_

# include <QtWidgets/QApplication>
# include <QtWidgets/QPushButton>
# include <QtWidgets/QLCDNumber>
# include <QtWidgets/QColorDialog>
# include <QtWidgets/QGridLayout>
# include <QtWidgets/QHBoxLayout>
# include <QtWidgets/QGroupBox>
# include <QtWidgets/QDialog>
# include <QtWidgets/QMenuBar>
# include <QtWidgets/QMenu>
# include <QtWidgets/QAction>
# include <QtWidgets/QLabel>
# include <QtWidgets/QMessageBox>
# include <QLineEdit>
# include <QTextEdit>
# include <QString>
# include <QTime>
# include <QTimer>
# include <regex>
# include <stdlib.h>

//# include "MainUI.hpp"
class MainUI;
class Connexion
{
public:
	Connexion(MainUI *);
	~Connexion();
	void 	setLayouts();
	void 	init();
	void 	connectSlots();
public slots:
	void 	tryConnect();
private:
  MainUI 		*_mainUI;
  QPushButton	*_connect;
  QPushButton	*_quit;
  QWidget 		*_window;
  QGridLayout	*_mainLayout;
  QLabel        *_portLabel;
  QLineEdit     *_port;
  QLabel        *_widthLabel;
  QLineEdit     *_width;
  QLabel        *_heightLabel;
  QLineEdit     *_height;
  QLabel        *_clientLabel;
  QLineEdit     *_client;
  QLabel        *_delayLabel;
  QLineEdit     *_delay;
};

#endif /* _CONNEXION_HPP_ */