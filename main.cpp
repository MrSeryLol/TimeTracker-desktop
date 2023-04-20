#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include "./API/projectapi.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    ProjectAPI project;
    project.GetProjects();
    //project.PrintJson();
    //project.GetProjects();



    //ProjectModel model;
    //model.GetProjects();

    return app.exec();
}
