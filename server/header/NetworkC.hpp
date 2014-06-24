#ifndef NETWORK_HPP_
# define NETWORK_HPP_

# include <QObject>
# include <QDebug>
# include <QThread>
# include <QTimer>
# include <QTextEdit>
# include "Server.h"

class NetworkC : public QObject
{
    Q_OBJECT
 
public:
    NetworkC(Server *, QTextEdit *);
    ~NetworkC();
 
public slots:
    void    doWork();
    void    updateInfos();
signals:
    void finished();
    void error(QString err);
 
private:
    Server      *_server;
    QTextEdit   *_console;
};
#endif
