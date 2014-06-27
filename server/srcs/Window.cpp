#include "Window.hpp"

Window::Window()
{
	this->resize(1457, 707);
	_glview = new GLView(this);
	this->show();
	_glview->resize(1457, 707);
	_glview->show();
}

Window::~Window(){}