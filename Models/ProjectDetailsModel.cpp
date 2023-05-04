#include "ProjectDetailsModel.h"

ProjectDetailsModel::ProjectDetailsModel(ProjectDetailsDTO projectDetails, QObject *parent)
    : QAbstractListModel{parent},
      _projectDetails{projectDetails}
{

}

int ProjectDetailsModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }

    return _projectDetails.tasks.count();
}

QVariant ProjectDetailsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    const TaskDTO &dto = _projectDetails.tasks.at(index.row());
    switch (role)
    {
        case TaskIdRole:
            return dto.taskId;
        case TaskNameRole:
            return dto.taskName;
        case TaskDescriptionRole:
            return dto.taskDescription;
        case TaskPriorityRole:
            return dto.priority;
        case ProjectCreatedDateRole:
            return dto.createdAt;
        case ProjectUpdatedDateRole:
            return dto.updatedAt;
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> ProjectDetailsModel::roleNames() const
{
    static QHash<int, QByteArray> mapping
    {
        {TaskIdRole, "taskId"},
        {TaskNameRole, "taskName"},
        {TaskDescriptionRole, "taskDescription"},
        {TaskPriorityRole, "taskPriority"},
        {ProjectCreatedDateRole, "taskDate"},
        {ProjectUpdatedDateRole, "taskUpdateDate"}
    };

    return mapping;
}

QString ProjectDetailsModel::getProjectName() const
{
    return _projectDetails.project.projectName;
}
