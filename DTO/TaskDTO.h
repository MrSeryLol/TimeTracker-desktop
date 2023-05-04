#ifndef TASKDTO_H
#define TASKDTO_H

#include <QString>
#include <QDate>

class TaskDTO
{
public:
    int taskId;
    QString taskName;
    QString taskDescription;
    QString priority;
    //int mainTaskId;
    QDate createdAt;
    QDate updatedAt;
};

#endif // TASKDTO_H
