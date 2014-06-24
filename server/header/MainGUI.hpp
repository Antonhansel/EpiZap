#ifndef _MAINGUI_HPP_
# define _MAINGUI_HPP_

# include <QtCore>
# include <QtOpenGL>
# include <QGLWidget>
# include <QPainter>
# include <GL/glu.h>
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

class MainGUI : public QGLWidget
{
	Q_OBJECT
public:
	MainGUI();
	~MainGUI();
	void initializeGL();
	void resizeGL(int, int);
	void  paintGL();
public slots:
	void 	updateGL();
private:
	QTimer 	*_timer;
};

#endif /*_MAINGUI_HPP_*/