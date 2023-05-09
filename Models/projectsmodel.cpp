#include "projectsmodel.h"

ProjectsModel::ProjectsModel(QList<ProjectDTO>* projectsList, QObject *parent)
    : QAbstractListModel{parent},
      _projectsList{projectsList}
{
    //_projectsList = api->GetProjectsList();

    //qDebug() << _projectsList;

//    for(auto projectItem : *_projectsList)
//    {
//        QString string = QString("%1 %2 %3 %4").arg(projectItem.projectName).arg(projectItem.projectDesription).arg(projectItem.estimateTime).arg(projectItem.createdAt.toString());
//        qDebug() << string;

//    }

}

int ProjectsModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }

    return _projectsList->count();
}

QVariant ProjectsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    const ProjectDTO &dto = _projectsList->at(index.row());
    switch (role)
    {
        case ProjectIdRole:
            return dto.projectId;
        case ProjectNameRole:
            return dto.projectName;
        case ProjectDescriptionRole:
            return dto.projectDesсription;
        case ProjectTimeRole:
            return dto.estimateTime;
        case ProjectCreatedDateRole:
            return dto.createdAt;
        case ProjectUpdatedDateRole:
            return dto.updatedAt;
        default:
            return QVariant();
    }
}

QHash<int, QByteArray> ProjectsModel::roleNames() const
{
    static QHash<int, QByteArray> mapping
    {
        {ProjectIdRole, "projectId"},
        {ProjectNameRole, "projectName"},
        {ProjectDescriptionRole, "projectDescription"},
        {ProjectTimeRole, "projectTime"},
        {ProjectCreatedDateRole, "projectDate"},
        {ProjectUpdatedDateRole, "projectUpdateDate"}
    };

    return mapping;
}

int ProjectsModel::size() const
{

}

QVariant ProjectsModel::getData(int index, int role)
{
    if (index < 0 || index >= _projectsList->count())
            return QVariant();
        switch (role) {
        case ProjectNameRole:
            return "Привет";
        default:
            return QVariant();
        }
}
