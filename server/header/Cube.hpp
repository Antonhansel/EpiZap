#ifndef CUBE_HPP_
# define CUBE_HPP_

#include <QWidget>
#include <QGLView>
#include <QGLSceneNode>
#include <QGLBuilder>
#include <QGLPainter>
#include <QGLTexture2D>
#include <QGLCube>

class QGLSceneNode;

class CubeView : public QGLView
 {
     Q_OBJECT
 public:
     CubeView(QWidget *parent);
     ~CubeView();

 protected:
     void paintGL(QGLPainter *painter);

 private:

 	QWidget	*_widget;
    QGLSceneNode *cube;
    QGLTexture2D logo;

};

#endif /* !CUBE_HPP_ */