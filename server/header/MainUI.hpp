#ifndef MAIN_UI_HPP_
# define MAIN_UI_HPP_

#define WIDTH 1748
#define HEIGHT 880

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
# include <QListWidget>
# include "Connexion.hpp"
# include "NetworkC.hpp"
# include "Graphic.hpp" 

class	MainUI: public	QWidget
{
  Q_OBJECT
public:
  MainUI(bool);
  void  setConsoleText(const QString &);
  void  setServer(Server &);
  void  startGraphic();
  void  initRealUpdate();
  void  addData(QString const &, bool);
public slots:
  void  showAbout() const;
  void  updateInfos();
  void  updateGraphic();
private:
  void  connectSlots();
  void  initLayouts();
  void  initUi();
  void  applyLayouts();
  void  menuBar();
  void  initConnexionStuff();
protected:
  Connexion    *_connexion;
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
  QListWidget   *_teams;
  Server        *_server;
  bool          _start;
  Graphic       *_graphic;
  bool          _continue;
  bool          _status;
};

#endif /* MAIN_UI_HPP_ */
