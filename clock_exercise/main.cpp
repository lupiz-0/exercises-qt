#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "clockmanager.h"
#include "alarmitemmodel.h"
#include "alarmitemdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("clockManager", new ClockManager(&engine));
    engine.load(url);

    return app.exec();
}
