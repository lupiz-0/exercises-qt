#include "tcpclient.h"
#include <QHostAddress>

TcpClient::TcpClient(): m_tcpSocket(), m_onlyInit(false)
{
}

bool TcpClient::init() {
    m_tcpSocket.connectToHost(QHostAddress("127.0.0.1"), 3333);
    return m_tcpSocket.waitForConnected();
}
