#pragma once
#include "abstracttcpclientserver.h"
#include <QTcpServer>

class TcpServer: public AbstractTcpClientServer
{
public:
    TcpServer();
    TcpServer(const TcpServer&) = delete;
    TcpServer& operator=(const TcpServer&) = delete;
    bool init() override;

private:

    QTcpServer m_tcpServer;
    QTcpSocket* m_client;
};
