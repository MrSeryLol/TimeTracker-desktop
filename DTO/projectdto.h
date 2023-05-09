#ifndef PROJECTDTO_H
#define PROJECTDTO_H

#include <QString>
#include <QDate>

class ProjectDTO
{
public:
    int projectId;
    QString projectName;
    QString projectDesсription;
    int estimateTime;
    QDate createdAt;
    QDate updatedAt;
};

#endif // PROJECTDTO_H
