#include "tcpserver.h"
#include <iostream>
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

bool TcpServer::update() {
    if(!m_client->waitForReadyRead(-1)) {
        return false;
    }
    m_client->read(m_buffer, BUFFER_SIZE);
    m_client->write(m_buffer, strlen(m_buffer) + 1);
    m_client->waitForBytesWritten();

    return true;
}
