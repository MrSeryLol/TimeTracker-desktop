#include "TokenParser.h"

TokenParser::TokenParser(QObject *parent)
    : QObject{parent}
{

}

int TokenParser::getUserId(const QString &token)
{
    QList splittedToken = token.split(".");
    QByteArray encodedPayload = splittedToken[1].toUtf8();
    QByteArray decodedPayload = encodedPayload.fromBase64Encoding(encodedPayload, QByteArray::Base64UrlEncoding).decoded;
    QJsonObject payload = QJsonDocument::fromJson(decodedPayload).object();
    return payload["user_id"].toInt();
}
