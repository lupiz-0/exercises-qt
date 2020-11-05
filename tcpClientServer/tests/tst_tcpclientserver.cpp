#include <QtTest>

class tcpClientServer : public QObject
{
    Q_OBJECT

public:
    tcpClientServer();
    ~tcpClientServer();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void clientFailedInitTest();
};

tcpClientServer::tcpClientServer()
{

}

tcpClientServer::~tcpClientServer()
{

}

void tcpClientServer::initTestCase()
{

}

void tcpClientServer::cleanupTestCase()
{

}

void tcpClientServer::clientFailedInitTest() {
    QProcess clientProcess;
    clientProcess.start(QString("../tcp-client"), {"--only-init"});
    clientProcess.waitForFinished();
    QCOMPARE(clientProcess.exitCode(), QProcess::CrashExit);
}
QTEST_APPLESS_MAIN(tcpClientServer)

#include "tst_tcpclientserver.moc"
