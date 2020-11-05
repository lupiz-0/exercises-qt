#include "tcpserver.h"
#include <iostream>
#include <QTcpSocket>
#include <QProcess>

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
    QList<QByteArray> commandAndParameters = m_client->read(MAX_READ).split(' ');
    QStringList parameters;
    for(int i = 1; i < commandAndParameters.count(); i++)
        parameters << commandAndParameters[i];

    // <<< cosa da fare dopo aver preso il comando
    QProcess process;
    process.start(commandAndParameters[0], parameters);
    process.closeWriteChannel();
    process.waitForFinished();
    QByteArray result = process.readAllStandardOutput();
    // >>> cosa da fare dopo aver preso il comando

    m_client->write(result);
    m_client->waitForBytesWritten();

    return true;
}
