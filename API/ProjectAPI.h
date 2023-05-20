#ifndef PROJECTAPI_H
#define PROJECTAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFuture>
#include "API/baseURL.h"
#include "../DTO/ProjectDTO.h"
#include "../Models/projectsmodel.h"
#include "../Models/ProjectDetailsModel.h"
#include "../API/IBaseAPI.h"
#include "../API/Token.h"
#include "DTO/ProjectDetailsDTO.h"

class ProjectAPI : public QObject
{
    Q_OBJECT
public:
    explicit ProjectAPI(QObject *parent = nullptr);

    Q_INVOKABLE void getProjects();
    Q_INVOKABLE void getProjectById(int id);
    QList<ProjectDTO>* GetProjectsList();

    Q_INVOKABLE ProjectsModel *model() const;
    Q_PROPERTY(ProjectDetailsModel* model READ projectDetailsModel CONSTANT)

    ProjectDetailsModel* projectDetailsModel();

private:
    QNetworkAccessManager _manager;
    QNetworkReply* _res;
    QByteArray _responseArray;
    QJsonDocument _JsonDocument;
    QList<ProjectDTO>* _projects;
    ProjectDetailsModel* _projectDetails;
    ProjectsModel* _model;

    void createProjectDetailsModel();

signals:
    void newJsonWithProjects(QByteArray info);
    void projectsListReady();
    void modelReady(ProjectsModel* _model);
    void projectDetailsModelReady(ProjectDetailsModel* projectDetails);
    void newJsonWithProjectDetails(QByteArray info);
    void projectDetailsReady();
//
};

#endif // PROJECTAPI_H
