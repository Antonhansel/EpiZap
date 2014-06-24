#include "MainGUI.hpp"

MainGUI::~MainGUI(){}

MainGUI::MainGUI(QTextEdit *console)
{
	_console = console;
	_timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    _timer->start(1000/30);	
    setFixedSize(1457, 707);
    _rotate = 0;
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
    glRotatef(_rotate, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1.5f, 0.0f, -6.0f);

    glBegin(GL_TRIANGLES);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
    glEnd();

    glTranslatef(3.0f, 0.0f, -6.0f);
    glRotatef(_rotate, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex3f(-1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glVertex3d(1.0f, 1.0f, 0.0f);
    glEnd();
  int xPointCount = 100;
  int yPointCount = 100;
  double xSpacing = 1;
  double ySpacing = 1;
  double width = xSpacing * (xPointCount-1); 
  double height = ySpacing * (yPointCount-1); 
  double minX = -width/2; 
  double minY = -height/2;
  
  glBegin(GL_POINTS);
  glColor3ub(255,255,255);
  for(int i = 0; i < xPointCount; i++) 
    { 
      for(int j = 0; j<yPointCount; j++) 
	{ 
	  double x = minX + i*xSpacing; 
	  double y = minY + j*ySpacing; 
	  double z = 0;
	  glVertex3f(x, y, z); 
	} 
    }
  glColor3ub(255,255,150);
  for(int i = 0; i<xPointCount; i++) 
    { 
      for(int j = 0; j<yPointCount; j++) 
	{ 
	  double x = minX + i*xSpacing; 
	  double y = minY + j*ySpacing; 
	  double z = 5; 
	  glVertex3f(x, y, z); 
	} 
    }
  glColor3ub(150,150,255);
  for(int i = 0; i<xPointCount; i++) 
    { 
      for(int j = 0; j<yPointCount; j++) 
	{ 
	  double x = minX + i*xSpacing; 
	  double y = minY + j*ySpacing; 
	  double z = 10; 
	  glVertex3f(x, y, z); 
	} 
    }
  glEnd();
}


void 	MainGUI::updateGL()
{
	_rotate += 1.0f;
	paintGL();
	swapBuffers();
}
