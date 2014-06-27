#ifndef _MAINGUI_HPP_
# define _MAINGUI_HPP_

# include <QtCore>
# include <QtOpenGL>
# include <QGLWidget>
# include <QPainter>
# include <GL/glu.h>
# include <GL/glut.h>
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
# include <iostream>
# include <QGLPainter>
# include <QWindow>
# include "GLView.hpp"

class MainGUI : public QWidget
{
	Q_OBJECT
public:
	MainGUI(QTextEdit *);
	~MainGUI();
	void 	logOutput(QString);
public slots:
private:
	QTextEdit 	*_console;
	GLView 		*_view;
	QWindow 	*_window;
 	// QTimer 		*_timer;
 	// QGLPainter	*_painter;
};

#endif /*_MAINGUI_HPP_*/