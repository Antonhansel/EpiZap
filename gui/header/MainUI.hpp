#ifndef MAIN_UI_HPP_
# define MAIN_UI__HPP_

#define WIDTH 400
#define HEIGHT 400

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
# include "Network.hpp"
# include "MainGUI.hpp"

class	MainUI: public	QWidget
{
  Q_OBJECT
public:
  MainUI();
public slots:
  void  tryConnect();
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
  QLabel       *_ipLabel;
  QLabel       *_portLabel;
  QPushButton  *_connect;
  QMenu        *_fileMenu;
  QAction	     *_exitAction;
  QAction	     *_about;
  QMenuBar	   *_menuBar;
  QGridLayout	 *_mainLayout;
  QLineEdit    *_ip;
  QLineEdit    *_port;
};

#endif /* MAIN_UI_HPP_ */
