#ifndef _NETWORK_HPP_
# define _NETWORK_HPP_

# include <QDesktopWidget>
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
# include <QString>
# include <QTime>
# include <QTimer>

class Network : public QWidget
{
	Q_OBJECT
public:
	Network();
	~Network();
	void  setConsoleText(const QString &data);
private:
	QWidget 	*_window;
  	QTextEdit     *_console;
  	QGridLayout 	*_mainLayout;
};

#endif /* _NETWORK_HPP_ */