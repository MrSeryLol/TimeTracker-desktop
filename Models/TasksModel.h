#ifndef TASKSMODEL_H
#define TASKSMODEL_H

#include "DTO/TaskDTO.h"
#include <QObject>
#include <QAbstractListModel>

class TasksModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TasksModel(QList<TaskDTO>* tasksList, QAbstractListModel *parent = nullptr);

    enum Roles
    {
        TaskIdRole = Qt::UserRole,
        TaskNameRole,
        TaskDescriptionRole,
        TaskPriorityRole,
        TaskCreatedDateRole,
        TaskUpdatedDateRole
    };

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<TaskDTO>* _tasksList;

};

#endif // TASKSMODEL_H
