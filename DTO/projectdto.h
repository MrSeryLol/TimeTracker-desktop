#ifndef PROJECTDTO_H
#define PROJECTDTO_H

#include <QString>
#include <QDate>

class ProjectDTO
{
public:
    ProjectDTO(const QString& projectName, const QString& projectDesription, int estimateTime, const QDate& createdAt)
        : projectName(projectName), projectDesription(projectDesription), estimateTime(estimateTime), createdAt(createdAt) {}
    QString projectName;
    QString projectDesription;
    int estimateTime;
    QDate createdAt;
};

#endif // PROJECTDTO_H
