#ifndef TOKENPARSER_H
#define TOKENPARSER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

class TokenParser : public QObject
{
    Q_OBJECT
public:
    explicit TokenParser(QObject *parent = nullptr);

    static int getUserId(const QString& token);

signals:

};

#endif // TOKENPARSER_H
