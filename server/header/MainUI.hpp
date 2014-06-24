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
# include <regex>
# include <stdlib.h>
# include "Connexion.hpp"

class	MainUI: public	QWidget
{
  Q_OBJECT
public:
  MainUI();
public slots:
  void  showAbout() const;
private:
  void  connectSlots();
  void  initLayouts();
  void  initUi();
  void  applyLayouts();
  void  menuBar();
  void  initConnexionStuff();
protected:
  Connexion    *_connexion;
//  Network      *_network;
//  MainGUI      *_mainGUI;
  QPushButton  *_quit;
  QMenu        *_fileMenu;
  QAction	     *_exitAction;
  QAction	     *_about;
  QMenuBar	   *_menuBar;
  QGridLayout	 *_mainLayout;
  bool          _start;
};

#endif /* MAIN_UI_HPP_ */
