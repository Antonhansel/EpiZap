#include "MainUI.hpp"

MainUI::MainUI()
{
	startConnexion();
}

void 	MainUI::startConnexion()
{
	QString       input;

	_pSocket = new QTcpSocket();
	connect(_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()));
	_pSocket->connectToHost(IP, 4242);
	if (_pSocket->waitForConnected())
	{
		std::cout << "Connexion established." << std::endl;
		_pSocket->write("TOTO\n");
		QTimer *timer = new QTimer(this);
		connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));
		timer->start(100);
	}
}

void	MainUI::readTcpData()
{
	QByteArray   	data = _pSocket->readAll();
	std::cout << data.data() << std::endl;
}

MainUI::~MainUI()
{

}

void 	MainUI::sendData()
{
	_pSocket->write("TEST TEST\n");
	std::cout << "Data sent" << std::endl;
}
