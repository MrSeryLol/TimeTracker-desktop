#ifndef HISTORYOFWORKDTO_H
#define HISTORYOFWORKDTO_H

#include <QTime>
#include <QDateTime>
#include <QDate>

class HistoryOfWorkDTO {

public:
    int efficientTime;
    QDateTime startDateTime;
    QDateTime endDateTime;
    QDate date;
    int projectId;
    int taskId;
    int userId;
    QDateTime createdAt;
    QDateTime updatedAt;
};

#endif // HISTORYOFWORKDTO_H
