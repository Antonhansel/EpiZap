#ifndef MAIN_UI_HPP_
# define MAIN_UI_HPP_

#define WIDTH 1800
#define HEIGHT 900

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
# include <QWindow>
# include <Window.hpp>
# include "Connexion.hpp"
# include "MainGUI.hpp"
# include "NetworkC.hpp"

class	MainUI: public	QWidget
{
  Q_OBJECT
public:
  MainUI();
  void  setConsoleText(const QString &);
  void  setServer(Server &);
public slots:
  void  showAbout() const;
  void  updateInfos();
private:
  void  connectSlots();
  void  initLayouts();
  void  initUi();
  void  applyLayouts();
  void  menuBar();
  void  initConnexionStuff();
protected:
  Connexion    *_connexion;
  MainGUI      *_mainGUI;
  QPushButton  *_quit;
  QMenu        *_fileMenu;
  QAction	     *_exitAction;
  QAction	     *_about;
  QMenuBar	   *_menuBar;
  QGridLayout	 *_mainLayout;
  QGridLayout  *_leftLayout;
  QGridLayout  *_bottomLayout;
  QGridLayout  *_rightLayout;
  QGridLayout   *_topLayout;
  QTextEdit     *_console;
  QTextEdit     *_data;
  QTextEdit     *_infos;
  QTextEdit     *_teams;
  Server        *_server;
  QWindow   *_window;
  bool          _start;
  QWidget       *_testWidget;
};

#endif /* MAIN_UI_HPP_ */
