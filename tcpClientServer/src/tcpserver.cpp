#include "tcpserver.h"
#include <QTcpSocket>

TcpServer::TcpServer(): m_tcpServer(), m_client(nullptr)
{
}

bool TcpServer::init() {
    if (!m_tcpServer.listen(QHostAddress("127.0.0.1"), 3333)) {
        return false;
    }

    m_tcpServer.waitForNewConnection(-1);
    m_client = m_tcpServer.nextPendingConnection();

    return true;

}
