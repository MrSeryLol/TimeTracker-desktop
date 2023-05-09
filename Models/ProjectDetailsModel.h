#ifndef PROJECTDETAILSMODEL_H
#define PROJECTDETAILSMODEL_H

#include "./DTO/ProjectDTO.h"
#include "./DTO/ProjectDetailsDTO.h"
#include "Models/TasksModel.h"
#include <QObject>
#include <QAbstractListModel>

class ProjectDetailsModel : public QObject
{
    Q_OBJECT
public:
    explicit ProjectDetailsModel(ProjectDetailsDTO projectDetails, QObject *parent = nullptr);

    Q_PROPERTY(QString projectName READ getProjectName CONSTANT)
    Q_PROPERTY(QString projectDescription READ getProjectDescription CONSTANT)
    Q_PROPERTY(int projectEstimateTime READ getProjectEstimateTime CONSTANT)
    Q_PROPERTY(QDate projectCreatedDate READ getProjectCreatedDate CONSTANT)
    Q_PROPERTY(QDate projectUpdatedDate READ getProjectUpdatedDate CONSTANT)
    Q_PROPERTY(TasksModel* list READ list CONSTANT)

public:
    QString getProjectName() const;
    QString getProjectDescription() const;
    int getProjectEstimateTime() const;
    QDate getProjectCreatedDate() const;
    QDate getProjectUpdatedDate() const;
    TasksModel* list() const;

private:
    ProjectDTO _project;
    TasksModel* _tasks;
};

#endif // PROJECTDETAILSMODEL_H
