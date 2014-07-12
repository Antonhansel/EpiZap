#include "MainUI.hpp"

MainUI::MainUI(char *ip, char *port, char *team, char *tick)
{
	_team = team;
	_team += "\n";
	_port = atoi(port);
	_tick = atoi(tick);
	_ip = ip;
	startConnexion();
}

void 	MainUI::startConnexion()
{
	QString       input;

	_pSocket = new QTcpSocket();
	connect(_pSocket, SIGNAL(readyRead()), SLOT(readTcpData()));
	_pSocket->connectToHost(_ip.c_str(), _port);
	if (_pSocket->waitForConnected())
	{
		std::cout << "Connexion established." << std::endl;
		_pSocket->write(_team.c_str());
		QTimer *timer = new QTimer(this);
		connect(timer, SIGNAL(timeout()), this, SLOT(sendData()));
		timer->start(_tick);
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

void	MainUI::writeOnSocket(const char *data)
{
	_pSocket->write(data);
	std::cout << data << std::endl;
}

void 	MainUI::sendData()
{
	int i = rand() % 3;
	if (i == 0)
		writeOnSocket("avance\n");
	if (i == 1)
		writeOnSocket("gauche\n");
	if (i == 2)
		writeOnSocket("droite\n");
}
