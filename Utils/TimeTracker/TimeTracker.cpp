#include "TimeTracker.h"

TimeTracker::TimeTracker(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    //_allWorkingTime.setHMS(0, 0, 0);
    //_allPauseTime.setHMS(0, 0, 0);
    connect(timer, &QTimer::timeout, this, &TimeTracker::updateTime);
}

void TimeTracker::start()
{
    qDebug() << "Нажал старт";
    _startDateTime = QDateTime::currentDateTime();
    //_history.startDateTime = QDateTime::currentDateTime();
    //_startDateTime = QDateTime::currentDateTime();
    _isRunning = true;
    timer->start(50);
    _workingTime.start();
    emit runningChanged();
}


void TimeTracker::updateTime()
{
    if (_isRunning)
    {
        _allWorkingTime = _workingTime.elapsed();
        //qDebug() << "Время: " << _allWorkingTime;
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
    _allPauseTime += _pauseTime.elapsed();
    _isActive = true;
    emit statusChanged();
}

void TimeTracker::stop()
{
    qDebug() << "Нажал стоп";
    _isRunning = false;
    _isTaskSelected = false;

    _endDateTime = QDateTime::currentDateTime();
    //_history.endDateTime = QDateTime::currentDateTime();
    //qDebug() << _allWorkingTime.secsTo();
    _history.startDateTime = _startDateTime;
    _history.endDateTime = _endDateTime;
    _efficientTime =  _startDateTime.time().secsTo(_endDateTime.time()) - _allPauseTime;
    //qDebug() << _allWorkingTime.secsTo(_st);
    //_history.efficientTime = _allWorkingTime.secsTo(_allWorkingTime) - _allPauseTime.secsTo(_allPauseTime);
    //_endDateTime = QDateTime::currentDateTime();
    qDebug() << "Общее время: " << _allWorkingTime / 1000;
    qDebug() << "Время начала: " << _startDateTime;
    qDebug() << "Время окончания: " << _endDateTime;
    qDebug() << "Время паузы: " << _allPauseTime / 1000;
    qDebug() << "Полезное время: " << _efficientTime;

    _project.projectName = "";
    _task.taskName = "";
    //_allWorkingTime.setHMS(0, 0, 0);
    emit timeChanged();
    emit runningChanged();
    emit taskSelected();
    emit projectNameChanged();
    emit taskNameChanged();
//    emit stopWorking(HistoryOfWorkDTO{_efficientTime, _startDateTime, _endDateTime,
//                     QDate::currentDate(), _project.projectId, _task.taskId, 1,
//                     QDateTime::currentDateTime(), QDateTime::currentDateTime()});
    emit stopWorking();
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
