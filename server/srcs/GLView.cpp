#include "GLView.hpp"

GLView::GLView(QWindow *parent) : QGLView(parent)
{
	_window = parent;
	QGLBuilder builder;
	builder << QGL::Faceted;
	builder << QGLCube();
	cube = builder.finalizedSceneNode();
	_rotate = 0;
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(10);
}

void GLView::paintGL(QGLPainter *painter)
{
     painter->setStandardEffect(QGL::LitMaterial);
     painter->setFaceColor(QGL::AllFaces, QColor(170, 202, 0));
     _rotate += 0.5;
     painter->modelViewMatrix().rotate(_rotate, 1.0f, 1.0f, 1.0f);
     cube->draw(painter);
}

GLView::~GLView(){}