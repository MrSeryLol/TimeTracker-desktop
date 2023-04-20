#include "projectapi.h"

ProjectAPI::ProjectAPI(QObject *parent)
    : QObject{parent}
{
    //connect(&_manager, &QNetworkAccessManager::finished, this, &ProjectAPI::Fetch);
    //connect(this, &ProjectAPI::NewJson, this, &ProjectAPI::PrintJson);
}


void ProjectAPI::Fetch(QNetworkReply* res)
{
    //_res = qobject_cast<QNetworkReply*>(sender());

    if(res->error())
    {
        qDebug() << res->error();
        res->deleteLater();
        return;
    }

    _JsonDocument = QJsonDocument::fromJson(_res->readAll());

    if(_JsonDocument.isNull())
    {
        qDebug() << "Ошибка в жасоне";
    }

    qDebug() << _JsonDocument["company_id"];

    //QString string = res->readAll();
    //qDebug() << string;

    res->deleteLater();
    emit NewJson();
    //connect(this, &ProjectAPI::NewJson, this, &ProjectAPI::PrintJson);

    //QNetworkReply* _res = res;

    //QString string = res->readAll();
    //qDebug() << string;
    //_res->close();
    //res->deleteLater();
//    return _res->readAll();
}

void ProjectAPI::GetProjects()
{
    //_manager.get(QNetworkRequest(QUrl(baseURL + "/api/projects/56")));
    _res = _manager.get(QNetworkRequest(QUrl(baseURL + "/api/projects/")));
    QtFuture::connect(_res, &QNetworkReply::finished)
            .then([this] {
        QString string = _res->readAll();
        qDebug() << string;
        return _res->readAll();
    });
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


}

void ProjectAPI::PrintJson()
{
      auto json = _JsonDocument.toJson(QJsonDocument::Indented);
      qDebug() << json;
}
