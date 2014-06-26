#include "Cube.hpp"

CubeView::CubeView(QWidget *parent) : QGLView()
 {
     QGLBuilder builder;
     _widget = parent;
     builder << QGL::Faceted;
     builder << QGLCube();

     cube = builder.finalizedSceneNode();
 }

 void CubeView::paintGL(QGLPainter *painter)
 {
     cube->draw(painter);
 }

 CubeView::~CubeView()
 {}