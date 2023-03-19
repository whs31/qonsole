#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <qqml.h>
#include <QTimer>

#include "../include/debug.hpp"

QONSOLE_DECLARE;
int main(int argc, char *argv[])
{
    #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif
    QGuiApplication app(argc, argv);
    QONSOLE_INIT;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Example.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
            {
                qCritical() << "[MAIN] Failed to launch QML engine";
                QCoreApplication::exit(-1);
            }
        },
        Qt::QueuedConnection
        );
    engine.load(url);

    qDebug() << "123";
    qWarning() << "1231231";
    qInfo() << "123123123123";
    qCritical() << "asdsdgjnsdfkogjdfg";
    for(int i = 0; i < 50; i++)
    {
        qDebug() << "[TEST] Test number: " << i;
    }

    return app.exec();
}
