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
    void succeededInitTest();

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

void tcpClientServer::succeededInitTest() {
    QProcess serverProcess;
    serverProcess.start(QString("../tcp-server"), QStringList());
    serverProcess.waitForStarted();

    QTest::qSleep(1000);

    QProcess clientProcess;
    clientProcess.start(QString("../tcp-client"), {"--only-init"});
    clientProcess.waitForStarted();

    clientProcess.write("quit\n");

    clientProcess.waitForFinished();
    serverProcess.waitForFinished();

    QCOMPARE(clientProcess.exitCode(), QProcess::NormalExit);
    QCOMPARE(serverProcess.exitCode(), QProcess::NormalExit);
}

QTEST_APPLESS_MAIN(tcpClientServer)

#include "tst_tcpclientserver.moc"
