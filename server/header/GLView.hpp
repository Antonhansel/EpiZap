#ifndef CUBE_HPP_
# define CUBE_HPP_

# include <QWidget>
# include <QGLView>
# include <QGLSceneNode>
# include <QGLBuilder>
# include <QGLPainter>
# include <QGLTexture2D>
# include <QGLCube>
# include <QWindow>
# include <iostream>
# include <QTimer>

class QGLSceneNode;
class GLView : public QGLView
{
     Q_OBJECT
 public:
    GLView(QWindow *);
    ~GLView();
    void 	paintGL(QGLPainter *painter);
 private:
 	QWindow 	*_window;
 	QGLSceneNode *cube;
 	float 		_rotate;
};

#endif /* !CUBE_HPP_ */