#include "TimeTracker.h"

TimeTracker::TimeTracker(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    _allWorkingTime.setHMS(0, 0, 0);
    _allPauseTime.setHMS(0, 0, 0);
    connect(timer, &QTimer::timeout, this, &TimeTracker::updateTime);
}

void TimeTracker::start()
{
    qDebug() << "Нажал старт";
    _startDateTime = QDateTime::currentDateTime();
    _isRunning = true;
    timer->start(50);
    _workingTime.start();
    emit runningChanged();
}


void TimeTracker::updateTime()
{
    if (_isRunning)
    {
        _allWorkingTime = _allWorkingTime.addMSecs(_workingTime.restart());
        qDebug() << "Время: " << _allWorkingTime;
        emit timeChanged();
    }
}

void TimeTracker::pause()
{
    if(_isActive && _isRunning)
    {
        _pauseTime.start();
        _isActive = false;
    }
    emit statusChanged();
}

void TimeTracker::unpause()
{
    _allPauseTime = _allPauseTime.addMSecs(_pauseTime.elapsed());
    _isActive = true;
    emit statusChanged();
}

void TimeTracker::stop()
{
    qDebug() << "Нажал стоп";
    _isRunning = false;
    _isTaskSelected = false;
    _endDateTime = QDateTime::currentDateTime();
    qDebug() << "Общее время: " << _allWorkingTime;
    qDebug() << "Время начала: " << _startDateTime;
    qDebug() << "Время окончания: " << _endDateTime;
    qDebug() << "Время паузы: " << _allPauseTime;

    _project.projectName = "";
    _task.taskName = "";
    _allWorkingTime.setHMS(0, 0, 0);
    emit timeChanged();
    emit runningChanged();
    emit taskSelected();
    emit projectNameChanged();
    emit taskNameChanged();
}

void TimeTracker::setProject(ProjectsModel* list, int row)
{
    qDebug() << "Вызвал setProject()";
    qDebug() << row;
    qDebug() << list->data(list->index(row), ProjectsModel::Roles::ProjectNameRole);

    _project.projectId = list->data(list->index(row), ProjectsModel::Roles::ProjectIdRole).toInt();
    _project.projectName = list->data(list->index(row), ProjectsModel::Roles::ProjectNameRole).toString();
    _project.projectDesсription = list->data(list->index(row), ProjectsModel::Roles::ProjectDescriptionRole).toString();
    _project.estimateTime = list->data(list->index(row), ProjectsModel::Roles::ProjectTimeRole).toInt();
    _project.createdAt = list->data(list->index(row), ProjectsModel::Roles::ProjectCreatedDateRole).toDate();
    _project.updatedAt = list->data(list->index(row), ProjectsModel::Roles::ProjectUpdatedDateRole).toDate();

    emit projectNameChanged();
}

void TimeTracker::setTask(TasksModel* list, int row)
{
    qDebug() << "Вызвал setTask()";
    qDebug() << row;
    qDebug() << list->data(list->index(row), TasksModel::Roles::TaskNameRole);

    _task.taskId = list->data(list->index(row), TasksModel::Roles::TaskIdRole).toInt();
    _task.taskName = list->data(list->index(row), TasksModel::Roles::TaskNameRole).toString();
    _task.taskDescription = list->data(list->index(row), TasksModel::Roles::TaskDescriptionRole).toString();
    _task.priority = list->data(list->index(row), TasksModel::Roles::TaskPriorityRole).toString();
    _task.createdAt = list->data(list->index(row), TasksModel::Roles::TaskCreatedDateRole).toDate();
    _task.updatedAt = list->data(list->index(row), TasksModel::Roles::TaskUpdatedDateRole).toDate();

    _isTaskSelected = true;

    emit taskNameChanged();
    emit taskSelected();
}

QString TimeTracker::getTaskName() const
{
    return _task.taskName;
}

QString TimeTracker::getProjectName() const
{
    return _project.projectName;
}

void TimeTracker::setTaskName(const QString &taskName)
{
    if (taskName != _task.taskName)
    {
        _task.taskName = taskName;
    }

}

void TimeTracker::setProjectName(const QString &projectName)
{
    if (projectName != _project.projectName)
    {
        _project.projectName = projectName;
    }
}
