#ifndef IBASEAPI_H
#define IBASEAPI_H

#include <QObject>
#include <QByteArray>
#include <QNetworkReply>

class IBaseAPI : public QObject
{
    Q_OBJECT
public:
    virtual ~IBaseAPI() = default;
signals:
    void newJson(QByteArray& info);

public slots:
    virtual void parseJson(const QByteArray& json) = 0;
    virtual void fetch(QNetworkReply* res) = 0;
    //void createModel();
};

#endif // IBASEAPI_H
