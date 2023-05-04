#ifndef PROJECTDETAILSMODEL_H
#define PROJECTDETAILSMODEL_H

#include "DTO/ProjectDetailsDTO.h"
#include <QObject>
#include <QAbstractListModel>

class ProjectDetailsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ProjectDetailsModel(ProjectDetailsDTO projectDetails, QObject *parent = nullptr);

    Q_PROPERTY(QString projectName READ getProjectName CONSTANT)

    enum Roles {
        TaskIdRole = Qt::UserRole,
        TaskNameRole,
        TaskDescriptionRole,
        TaskPriorityRole,
        ProjectCreatedDateRole,
        ProjectUpdatedDateRole
    };

signals:

public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    QString getProjectName() const;


private:
    ProjectDetailsDTO _projectDetails;
};

#endif // PROJECTDETAILSMODEL_H
