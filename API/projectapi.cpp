#include "projectapi.h"



ProjectAPI::ProjectAPI(QObject *parent)
    : QObject{parent}
      //_model({}, parent)
{
    _items = new QList<ProjectDTO>();

    connect(&_manager, &QNetworkAccessManager::finished, this, &ProjectAPI::Fetch);
    connect(this, &ProjectAPI::NewJson, this, &ProjectAPI::ParseJson);
    connect(this, &ProjectAPI::ProjectsListReady, this, &ProjectAPI::CreateModel);
    //QDate date = QDate::fromString("2023-04-11T16:38:44.071Z");
    //_items->append(ProjectData("Создать программу", "Описать этапы проектирования и прочего", 20, date));

//    for(auto item : *_items)
//    {
//        QString string = QString("%1 %2 %3 %4").arg(item.projectName).arg(item.projectDesription).arg(item.estimateTime).arg(item.createdAt.year());
//        qDebug() << string;
//        //qDebug() << std::printf("%s %s %d %s", item.projectName, item.projectDesription, item.estimateTime, item.createdAt);
//    }
    //connect(&_manager, &QNetworkAccessManager::finished, this, &ProjectAPI::Fetch);
    //connect(this, &ProjectAPI::NewJson, this, &ProjectAPI::PrintJson);
}


void ProjectAPI::Fetch(QNetworkReply* res)
{
    if(res->error())
    {
        qDebug() << res->error();
        res->deleteLater();
        return;
    }

    QByteArray info = res->readAll();
    QString string = info;
    qDebug() << string;
    res->deleteLater();
    emit NewJson(info);
}

void ProjectAPI::CreateModel()
{
    _model = new ProjectsModel(_items, this);
    emit modelReady(_model);
    //qDebug() << _model->data(0, Qt::UserRole);
}

QByteArray ProjectAPI::ParseJson(const QByteArray &json)
{
    QJsonArray info = QJsonDocument::fromJson(json).array();
    for(auto value : info)
    {
        QString projectName = value.toObject()["project_name"].toString();
        QString projectDesription = value.toObject()["project_description"].toString();
        int estimateTime = value.toObject()["estimate_time"].toInt();
        QDate createdAt = QDate::fromString(value.toObject()["createdAt"].toString(), Qt::DateFormat::ISODate);



        _items->append(ProjectDTO(projectName, projectDesription, estimateTime, createdAt));
    }

    for(auto item : *_items)
    {
        QString string = QString("%1 %2 %3 %4").arg(item.projectName).arg(item.projectDesription).arg(item.estimateTime).arg(item.createdAt.toString());
        qDebug() << string;
        //qDebug() << std::printf("%s %s %d %s", item.projectName, item.projectDesription, item.estimateTime, item.createdAt);
    }

    qDebug() << _items;

    emit ProjectsListReady();
    return QByteArray();
}

ProjectsModel *ProjectAPI::model() const
{
    return _model;
}

void ProjectAPI::getProjects()
{
    //_manager.get(QNetworkRequest(QUrl(baseURL + "/api/projects/56")));
    _res = _manager.get(QNetworkRequest(QUrl(baseURL + "/api/projects/")));
//    connect(&_manager, &QNetworkAccessManager::finished, this, &ProjectAPI::Fetch);
//    connect(this, &ProjectAPI::NewJson, this, &ProjectAPI::ParseJson);
//    connect(this, &ProjectAPI::ProjectsListReady, this, &ProjectAPI::CreateModel);
}

//QByteArray ProjectAPI::ToJson(const QByteArray &json)
//{
//    QJsonObject info = QJsonDocument::fromJson(json).object();
//    qDebug() << info;

//}
//            .then([this] {
//        //QString string = _res->readAll();
//        //qDebug() << string;
//            return _res->readAll();
//            })
    //QString string = future.;
    //connect(_res, &QNetworkReply::readyRead, this, &ProjectAPI::Fetch);
    //qDebug() << _JsonDocument.isEmpty();
//    if (_res->isFinished())
//    {
//        qDebug() << _res->readAll();
//        _res->close();
//    }
    //qDebug() << _res->readAll();
    //QJsonDocument::fromJson(response)
    //qDebug() << response;




void ProjectAPI::PrintJson()
{
      auto json = _JsonDocument.toJson(QJsonDocument::Indented);
      qDebug() << json;
}
