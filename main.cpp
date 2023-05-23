#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include <QQmlContext>
#include "./API/ProjectAPI.h"
#include "./API/AuthAPI.h"
#include "./Models/ProjectDetailsModel.h"
#include "./Utils/TimeTracker/TimeTracker.h"
#include "API/HistoryOfWorkAPI.h"
#include "./Utils/TokenParser/TokenParser.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterSingletonType<AuthAPI>("AuthAPI", 1, 0, "AuthAPI", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        AuthAPI *example = new AuthAPI();
        return example;
    });
    qmlRegisterSingletonType<ProjectAPI>("ProjectAPI", 1, 0, "ProjectAPI", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        ProjectAPI *example = new ProjectAPI();
        return example;
    });
    qmlRegisterSingletonType<TimeTracker>("TimeTracker", 1, 0, "TimeTracker", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        TimeTracker *example = new TimeTracker();
        return example;
    });

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);



    //ProjectAPI project;
    //HistoryOfWorkAPI history;
    //history.saveActivity();
    TimeTracker timer;
    //qDebug() << timer.getTaskName();
    //AuthAPI auth;
    //ProjectDetailsModel projectDetails;
    //project.getProjects();
    //ProjectDTO dto("Создать программу", "Описать этапы проектирования", 20, QDate::fromString("2023-04-11T16:38:44.071Z"));
    //dto.projectName = "Создать программу";
    //dto.projectDesription = "Описать этапы проектирования";
    //dto.estimateTime = 20;
    //dto.createdAt = QDate::fromString("2023-04-11T16:38:44.071Z");
    //QList<ProjectDTO>* list = new QList<ProjectDTO>();
    //list->append(dto);

    //ProjectsModel projectModel(list);
    //engine.rootContext()->setContextProperty("_project", &project);
    engine.rootContext()->setContextProperty("_timeTracker", &timer);
    //engine.rootContext()->setContextProperty("_history", &history);
    //engine.rootContext()->setContextProperty("_auth", &auth);

    //engine.rootContext()->setContextProperty("_projectDetailsModel", project.projectDetailsModel());
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
