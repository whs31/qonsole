#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <qqml.h>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
#ifdef Q_OS_WIN
    qSetMessagePattern("[%{time process}] %{message}");
#else
    qSetMessagePattern("[%{time process}] "
                       "%{if-debug}\033[01;38;05;15m%{endif}"
                       "%{if-info}\033[01;38;05;146m%{endif}"
                       "%{if-warning}\033[1;33m%{endif}"
                       "%{if-critical}\033[1;31m%{endif}"
                       "%{if-fatal}F%{endif}"
                       "%{message}\033[0m");
#endif

    QGuiApplication app(argc, argv);

    // c++ part

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/example.qml"));
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

    return app.exec();
}
