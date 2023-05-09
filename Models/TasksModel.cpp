#include "TasksModel.h"

TasksModel::TasksModel(QList<TaskDTO>* tasksList, QAbstractListModel *parent)
    : QAbstractListModel{parent},
      _tasksList{tasksList}
{

}

int TasksModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }

    return _tasksList->count();
}

QVariant TasksModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    const TaskDTO &dto = _tasksList->at(index.row());
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
        case TaskCreatedDateRole:
            return dto.createdAt;
        case TaskUpdatedDateRole:
            return dto.updatedAt;
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> TasksModel::roleNames() const
{
    static QHash<int, QByteArray> mapping
    {
        {TaskIdRole, "taskId"},
        {TaskNameRole, "taskName"},
        {TaskDescriptionRole, "taskDescription"},
        {TaskPriorityRole, "taskPriority"},
        {TaskCreatedDateRole, "taskDate"},
        {TaskUpdatedDateRole, "taskUpdateDate"}
    };
    return mapping;
}
