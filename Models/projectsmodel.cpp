#include "projectsmodel.h"

ProjectsModel::ProjectsModel(QObject *parent)
    : QAbstractListModel{parent}
{
    //_info = _api.GetProjects();

}

int ProjectsModel::rowCount(const QModelIndex &parent) const
{

}

QVariant ProjectsModel::data(const QModelIndex &index, int role) const
{

}
