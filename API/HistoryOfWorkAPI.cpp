#include "HistoryOfWorkAPI.h"

HistoryOfWorkAPI::HistoryOfWorkAPI(QObject *parent)
    : QObject{parent}
{
    connect(&_timeTracker, &TimeTracker::stopWorking, this, qOverload<HistoryOfWorkDTO>(&HistoryOfWorkAPI::saveActivity));

}

void HistoryOfWorkAPI::saveActivity(HistoryOfWorkDTO history)
{
    //Формирование header для запроса
    QUrl url(baseURL + "/api/history/saveActivity");
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    //Параметры запроса
    QUrlQuery params;
    params.addQueryItem("history_id", "1");
    params.addQueryItem("starting_time", "10.01.23");
    params.addQueryItem("ending_time", "11.01.23");
    params.addQueryItem("efficient_time", "100");
    params.addQueryItem("date", "11.01.23");
    params.addQueryItem("project_id", "1");
    params.addQueryItem("task_id", "1");
    params.addQueryItem("user_id", "1");






    //Отправка post-запроса на сервер
    _manager.post(req, params.toString(QUrl::FullyEncoded).toUtf8());


}
