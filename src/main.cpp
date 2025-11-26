#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "calculator.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    Calculator calculator;


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("calculator", &calculator);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("basic_calculator", "Main");

    if (engine.rootObjects().isEmpty()) {
        qDebug() << "No QML objects loaded!";
        return -1;
    }

    return app.exec();
}
