#ifndef TIMETRACKER_H
#define TIMETRACKER_H

#include "Models/TasksModel.h"
#include "Models/projectsmodel.h"
#include "DTO/TaskDTO.h"
#include "DTO/ProjectDTO.h"
#include <QObject>
#include <QElapsedTimer>
#include <QTimer>
#include <QDateTime>
#include <QTime>
#include <QDebug>

class TimeTracker : public QObject
{
    Q_OBJECT
public:
    explicit TimeTracker(QObject *parent = nullptr);

    Q_INVOKABLE void start();
    void updateTime();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void unpause();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void setProject(ProjectsModel* list, int row);
    Q_INVOKABLE void setTask(TasksModel* list, int row);

    Q_PROPERTY(QString projectName READ getProjectName WRITE setProjectName NOTIFY projectNameChanged);
    Q_PROPERTY(QString taskName READ getTaskName WRITE setTaskName NOTIFY taskNameChanged);
    Q_PROPERTY(QTime mainTime MEMBER _allWorkingTime NOTIFY timeChanged)
    Q_PROPERTY(bool isRunning MEMBER _isRunning NOTIFY runningChanged)
    Q_PROPERTY(bool isTaskSelected MEMBER _isTaskSelected NOTIFY taskSelected)
    Q_PROPERTY(bool isActive MEMBER _isActive NOTIFY statusChanged)

    QString getTaskName() const;
    QString getProjectName() const;
    void setTaskName(const QString &taskName);
    void setProjectName(const QString &projectName);

private:
    QElapsedTimer _workingTime;
    QElapsedTimer _pauseTime;
    TaskDTO _task;
    ProjectDTO _project;
    QString _projectName;
    QTime _allWorkingTime;
    QTime _allPauseTime;

    bool isPaused = true;
    bool _isRunning = false;
    bool _isTaskSelected = false;
    bool _isActive = true;

    QTimer *timer;
    QDateTime _startDateTime;
    QDateTime _endDateTime;

signals:
    void projectNameChanged();
    void taskNameChanged();
    void timeChanged();
    void runningChanged();
    void taskSelected();
    void statusChanged();
};

#endif // TIMETRACKER_H
