#ifndef PROJECTSMODEL_H
#define PROJECTSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "../DTO/ProjectDTO.h"

class ProjectsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles
    {
        ProjectIdRole = Qt::UserRole,
        ProjectNameRole,
        ProjectDescriptionRole,
        ProjectTimeRole,
        ProjectCreatedDateRole,
        ProjectUpdatedDateRole
    };

    explicit ProjectsModel(QList<ProjectDTO>* projectsList, QObject *parent = nullptr);

signals:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<ProjectDTO>* _projectsList;
    //QByteArray _info;

};

#endif // PROJECTSMODEL_H
