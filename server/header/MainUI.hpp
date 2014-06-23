#ifndef MAIN_UI_HPP_
# define MAIN_UI__HPP_

#define WIDTH 600
#define HEIGHT 600

# include <sstream>
# include <iostream>
# include <QtCore>
# include <QFont>
# include <QPainter>
# include <QDesktopServices>
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
# include <stdlib.h>
# include "Network.hpp"
# include "MainGUI.hpp"

# include <unistd.h>

class	MainUI: public	QWidget
{
  Q_OBJECT
public:
  MainUI();
public slots:
  void  tryConnect();
  void  quit();
  void  showAbout() const;
private:
  void  connectSlots();
  void  initLayouts();
  void  foldersLayout();
  void  initUi();
  void  applyLayouts();
  void  timeLayout();
  void  mailPreviewLayout();
  void  menuBar();
  void  initConnexionStuff();
protected:
  Network      *_network;
  MainGUI      *_mainGUI;
  QPushButton  *_connect;
  QPushButton  *_quit;
  QMenu        *_fileMenu;
  QAction	     *_exitAction;
  QAction	     *_about;
  QMenuBar	   *_menuBar;
  QGridLayout	 *_mainLayout;
  QTextEdit     *_console;
  QLabel        *_portLabel;
  QLineEdit     *_port;
  QLabel        *_widthLabel;
  QLineEdit     *_width;
  QLabel        *_heightLabel;
  QLineEdit     *_height;
  QLabel        *_customerLabel;
  QLineEdit     *_customer;
  QLabel        *_delayLabel;
  QLineEdit     *_delay;
};

#endif /* MAIN_UI_HPP_ */
