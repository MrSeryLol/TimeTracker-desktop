#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include <QQmlContext>
#include "./API/projectapi.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //QQmlContext* context = engine.rootContext();
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    ProjectAPI project;
    //project.getProjects();
    //ProjectDTO dto("Создать программу", "Описать этапы проектирования", 20, QDate::fromString("2023-04-11T16:38:44.071Z"));
    //dto.projectName = "Создать программу";
    //dto.projectDesription = "Описать этапы проектирования";
    //dto.estimateTime = 20;
    //dto.createdAt = QDate::fromString("2023-04-11T16:38:44.071Z");
    //QList<ProjectDTO>* list = new QList<ProjectDTO>();
    //list->append(dto);

    //ProjectsModel projectModel(list);
    engine.rootContext()->setContextProperty("_project", &project);
    //engine.rootContext()->setContextProperty("_model", &projectModel);


    engine.load(url);

    //ProjectsModel model;

    //ProjectAPI project;


    //project.GetProjects();
    //QString string = data;
    //qDebug() << string;
    //qDebug() << data;
    //project.PrintJson();
    //project.GetProjects();



    //ProjectModel model;
    //model.GetProjects();

    return app.exec();
}
