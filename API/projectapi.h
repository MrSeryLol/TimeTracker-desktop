#ifndef PROJECTAPI_H
#define PROJECTAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include "API/baseURL.h"


class ProjectAPI : public QObject
{
    Q_OBJECT
public:
    explicit ProjectAPI(QObject *parent = nullptr);

    void StartRequest(QNetworkReply* res);
    void GetProjects();
    //void PrintJson();

private:
    QNetworkAccessManager _manager;
    QNetworkReply* _res;
    QByteArray _responseArray;
    QJsonDocument _JsonDocument;

signals:
    void NewJson();

private slots:
    void Fetch(QNetworkReply* res);
    void PrintJson();
public slots:
    //void GetProjects();
    //QString GetProjects();



};

#endif // PROJECTAPI_H
