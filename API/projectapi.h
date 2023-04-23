#ifndef PROJECTAPI_H
#define PROJECTAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include "API/baseURL.h"
#include "../DTO/ProjectDTO.h"
#include "../Models/projectsmodel.h"
//#include "../Models/projectsmodel.h"

//struct ProjectData
//{
//    ProjectData(const QString& projectName, const QString& projectDesription, int estimateTime, const QDate& createdAt)
//        : projectName(projectName), projectDesription(projectDesription), estimateTime(estimateTime), createdAt(createdAt) {}
//    QString projectName;
//    QString projectDesription;
//    int estimateTime;
//    QDate createdAt;
//};


class ProjectAPI : public QObject
{
    Q_OBJECT
public:
    explicit ProjectAPI(QObject *parent = nullptr);

    void StartRequest(QNetworkReply* res);
    Q_INVOKABLE void getProjects();
    QList<ProjectDTO>* GetProjectsList();
    QByteArray ParseJson(const QByteArray& json);

    //void PrintJson();

    ProjectsModel *model() const;

private:
    QNetworkAccessManager _manager;
    QNetworkReply* _res;
    QByteArray _responseArray;
    QJsonDocument _JsonDocument;
    QList<ProjectDTO>* _items;
    ProjectsModel* _model;


signals:
    void NewJson(QByteArray info);
    void ProjectsListReady();
    void modelReady(ProjectsModel* _model);

private slots:
    void Fetch(QNetworkReply* res);
    void CreateModel();
    //void Fetch();
    void PrintJson();
public slots:
    //void GetProjects();
    //QString GetProjects();



};

#endif // PROJECTAPI_H
