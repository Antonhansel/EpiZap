#ifndef NETWORK_HPP_
# define NETWORK_HPP_

# include <QObject>
# include <QDebug>
# include <QThread>
# include "Server.h"

class NetworkC : public QObject {
    Q_OBJECT
 
public:
    NetworkC(Server *);
    ~NetworkC();
 
public slots:
    void doWork();
 
signals:
    void finished();
    void error(QString err);
 
private:
    Server  *_server;
};
#endif
