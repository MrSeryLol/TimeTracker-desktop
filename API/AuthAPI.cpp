#include "AuthAPI.h"

AuthAPI::AuthAPI(QObject *parent)
    : QObject{parent}
{

}

void AuthAPI::signIn(const QString &login, const QString &password)
{
    //Формирование header для запроса
    QUrl url(baseURL + "/api/auth/login/");
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    //Параметры запроса
    QUrlQuery params;
    params.addQueryItem("login", login);
    params.addQueryItem("password", password);

    //Отправка post-запроса на сервер
    QNetworkReply* res = _manager.post(req, params.toString(QUrl::FullyEncoded).toUtf8());
    auto roflan = QtFuture::connect(res, &QNetworkReply::finished)
            .then([res]() {
                //Считываем полученные данные
                if (res->error() == QNetworkReply::NoError)
                {
                    res->deleteLater();
                    return res->readAll();
                }

                throw QNetworkReply::NetworkError();
            })
            .then(QtFuture::Launch::Async, [this](const QByteArray& json) {
                qDebug() << "Ошибок нет";
                //Парсим полученный Json, получая jwt-токен
                QJsonObject info = QJsonDocument::fromJson(json).object();
                QString token = info["token"].toString();
                userToken = token;
                qDebug() << userToken;
                emit successVerification();
            })
            .onFailed([res, this](QNetworkReply::NetworkError) {
                QByteArray json = res->readAll();
                QJsonObject info = QJsonDocument::fromJson(json).object();
                QString errorMessage = info["message"].toString();
                res->deleteLater();
                emit failVerification(errorMessage);
            });
}
