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
# include "Cube.hpp"

class MainGUI : public QGLWidget
{
	Q_OBJECT
public:
	MainGUI(QTextEdit *);
	~MainGUI();
	void initializeGL();
	void resizeGL(int, int);
	void  paintGL();
	void 	logOutput(QString);
public slots:
	void 	updateGL();
private:
	float 		_rotate;
	QTextEdit *_console;
	QTimer 	*_timer;
	CubeView *_view;
};

#endif /*_MAINGUI_HPP_*/