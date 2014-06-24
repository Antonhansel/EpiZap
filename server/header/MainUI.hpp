#ifndef MAIN_UI_HPP_
# define MAIN_UI_HPP_

#define WIDTH 1024
#define HEIGHT 768

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
  void  setConsoleText(const QString &);
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
//  MainGUI      *_mainGUI;
  QPushButton  *_quit;
  QMenu        *_fileMenu;
  QAction	     *_exitAction;
  QAction	     *_about;
  QMenuBar	   *_menuBar;
  QGridLayout	 *_mainLayout;
  QTextEdit     *_console;
  QTextEdit     *_data;
  QTextEdit     *_infos;
  QTextEdit     *_teams;
  bool          _start;
};

#endif /* MAIN_UI_HPP_ */
