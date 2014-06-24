#include "MainGUI.hpp"

MainGUI::~MainGUI(){}

MainGUI::MainGUI(QTextEdit *console)
{
	_console = console;
	_timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    _timer->start(1000/30);	
    setFixedSize(1457, 707);
}

void 	MainGUI::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();	
    logOutput("Resized");

}

void 	MainGUI::logOutput(QString input)
{
	QString test;

	test = "[OpenGL]: ";
	test += input;
	_console->append(test);
}

void 	MainGUI::initializeGL()
{
	glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    logOutput("Initialized");
}

void 	MainGUI::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);

    glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();

    glTranslatef(3.0f, 0.0f, -6.0f);
    glBegin(GL_QUADS);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glVertex3d(1.0f, 1.0f, 0.0f);
    glEnd();
}

void 	MainGUI::updateGL()
{
	paintGL();
}

