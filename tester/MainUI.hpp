#ifndef _MAINUI_HPP_
#define _MAINUI_HPP_


# include <QMainWindow>
# include <QDesktopServices>
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
# include <QtNetwork>
# include <QtCore>
# include <QFont>
# include <QPainter>
# include <QtNetwork>
# include <QLineEdit>
# include <QTextEdit>
# include <QString>
# include <QTime>
# include <QTimer>

# include <sstream>
# include <iostream>
# include <sstream>

class MainUI : public QWidget
{
	Q_OBJECT
public:
	MainUI(char *, char *, char *);
	~MainUI();	
	void 	startConnexion();
public slots:
	void 	readTcpData();
	void 	sendData();
private:
	QTcpSocket 	*_pSocket;
	std::string 	_team;
	std::string 	_ip;
	int 			_port;
};

#endif 