#ifndef _WINDOW_HPP_
# define _WINDOW_HPP_

# include <QWindow>
# include "GLView.hpp"
# include <QGLView>

class Window : public QWindow
{
public:
	Window();
	~Window();	
public slots:
protected:
	GLView 	*_glview;
};

#endif /* !_WINDOW_HPP_ */