#include "tcpclient.h"
#include <iostream>
#include <QHostAddress>

TcpClient::TcpClient(): m_tcpSocket(), m_onlyInit(false)
{
}

bool TcpClient::init() {
    m_tcpSocket.connectToHost(QHostAddress("127.0.0.1"), 3333);
    return m_tcpSocket.waitForConnected();
}

bool TcpClient::update() {

    if(m_tcpSocket.waitForReadyRead(1000)) {
        QByteArray serverResult = m_tcpSocket.read(MAX_READ);
        std::cout << serverResult.toStdString();
    }

    std::string string;
    std::getline(std::cin, string);
    if(string == "quit")
        return false;
    m_tcpSocket.write(string.c_str(), string.length() + 1);
    m_tcpSocket.waitForBytesWritten();

    return true;
}

