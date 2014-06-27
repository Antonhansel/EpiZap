#include "MainGUI.hpp"

MainGUI::~MainGUI(){}

MainGUI::MainGUI(QTextEdit *console)
{
	_console = console;
}

void 	MainGUI::logOutput(QString input)
{
	QString test;

	test = "[OpenGL]: qizjdiqjzdijqzidjqizdjiqjz";
	test += input;
	_console->append(test);
}
