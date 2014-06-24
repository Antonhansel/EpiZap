#ifndef CONNEXION_HPP_
# define CONNEXION_HPP_

#pragma once

# include <QtWidgets/QApplication>
# include <QtWidgets/QPushButton>
# include <QtWidgets/QLCDNumber>
# include <QtWidgets/QColorDialog>
# include <QtWidgets/QGridLayout>
# include <QtWidgets/QHBoxLayout>
# include <QDesktopWidget>
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
# include "Network.hpp"

class MainUI;
class Connexion : public QWidget
{
	Q_OBJECT
  
public:
	Connexion(MainUI *, Network *);
	~Connexion();
	void 	setLayouts();
	void 	init();
	void 	connectSlots();
public slots:
	void 	quit();
	void 	tryConnect();
private:
  bool  checkData(const QString &);
private:
  Network     *_network;
  QGridLayout *_leftLayout;
  QGridLayout *_rightLayout;
  MainUI 		*_mainUI;
  QPushButton	*_connect;
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
  QPushButton 	*_quit;
  QTextEdit     *_console;
};

#endif /* _CONNEXION_HPP_ */