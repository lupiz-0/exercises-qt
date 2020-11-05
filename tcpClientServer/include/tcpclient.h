#pragma once
#include "abstracttcpclientserver.h"
#include <QTcpSocket>

class TcpClient: public AbstractTcpClientServer
{
public:
    TcpClient();
    bool init() override;
    void setOnlyInit(bool onlyInit) { m_onlyInit = onlyInit; };

private:
    bool update() override;

    QTcpSocket m_tcpSocket;
    bool m_onlyInit;
};

