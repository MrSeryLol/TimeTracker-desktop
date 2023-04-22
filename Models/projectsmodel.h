#ifndef PROJECTSMODEL_H
#define PROJECTSMODEL_H

#include <QObject>
#include <QAbstractListModel>
//#include "../API/projectapi.h"

class ProjectsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ProjectsModel(QObject *parent = nullptr);

signals:


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

private:
    QList<QString> _projectsList;
    QByteArray _info;
};

#endif // PROJECTSMODEL_H
