#ifndef AUTHAPI_H
#define AUTHAPI_H

#include <QNetworkAccessManager>
#include "./BaseURL.h"
#include <QObject>
#include <QNetworkReply>
#include "./Token.h"
#include <QQmlEngine>
#include <QJSEngine>

class AuthAPI : public QObject
{
    Q_OBJECT
public:

    explicit AuthAPI(QObject *parent = nullptr);
    Q_INVOKABLE void signIn(const QString& login, const QString& password);



private:
    QNetworkAccessManager _manager;
    QString _login;
    QString _password;

signals:
    void successVerification();
    void failVerification(const QString& error);

};

#endif // AUTHAPI_H
