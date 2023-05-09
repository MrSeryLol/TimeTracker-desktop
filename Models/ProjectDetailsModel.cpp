#include "ProjectDetailsModel.h"

ProjectDetailsModel::ProjectDetailsModel(ProjectDetailsDTO projectDetails, QObject *parent)
    : QObject{parent},
      _project{projectDetails.project},
      _tasks{new TasksModel{projectDetails.tasks}}
{

}

QString ProjectDetailsModel::getProjectName() const
{
    return _project.projectName;
}

QString ProjectDetailsModel::getProjectDescription() const
{
    return _project.projectDesсription;
}

int ProjectDetailsModel::getProjectEstimateTime() const
{
    return _project.estimateTime;
}

QDate ProjectDetailsModel::getProjectCreatedDate() const
{
    return _project.createdAt;
}

QDate ProjectDetailsModel::getProjectUpdatedDate() const
{
    return _project.updatedAt;
}

TasksModel *ProjectDetailsModel::list() const
{
    return _tasks;
}
