#ifndef HISTORYOFWORKAPI_H
#define HISTORYOFWORKAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include "API/BaseURL.h"
#include "Utils/TimeTracker/TimeTracker.h"

class HistoryOfWorkAPI : public QObject
{
    Q_OBJECT
public:
    explicit HistoryOfWorkAPI(QObject *parent = nullptr);

    void saveActivity(HistoryOfWorkDTO history);


//public slots:
//    void saveActivity(HistoryOfWorkDTO history);


private:
    QNetworkAccessManager _manager;
    TimeTracker _timeTracker;


signals:

};

#endif // HISTORYOFWORKAPI_H
