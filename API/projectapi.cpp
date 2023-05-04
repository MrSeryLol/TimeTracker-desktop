#include "projectapi.h"

ProjectAPI::ProjectAPI(QObject* parent)
    : QObject{parent}
{
    _projects = new QList<ProjectDTO>();
}

ProjectsModel *ProjectAPI::model() const
{
    return _model;
}


void ProjectAPI::createProjectDetailsModel()
{

}

//Получение всех проектов
void ProjectAPI::getProjects()
{
    //Отправка get-запроса на сервер
    QNetworkReply* res = _manager.get(QNetworkRequest(QUrl(baseURL + "/api/projects/")));

    QtFuture::connect(res, &QNetworkReply::finished)
            .then([res]() {
                //Считываем полученные данные
                res->deleteLater();
                return res->readAll();
            })
            .then(QtFuture::Launch::Async, [this](const QByteArray &json) {
                //Парсим полученный Json в модель ProjectDTO
                QJsonArray info = QJsonDocument::fromJson(json).array();

                qDebug() << 1;

                for(auto value : info)
                {
                    //qDebug() << value.toObject();
                    int projectId = value.toObject()["project_id"].toInt();
                    QString projectName = value.toObject()["project_name"].toString();
                    QString projectDesription = value.toObject()["project_description"].toString();
                    int estimateTime = value.toObject()["estimate_time"].toInt();
                    QDate createdAt = QDate::fromString(value.toObject()["createdAt"].toString(), Qt::DateFormat::ISODate);
                    QDate updatedAt = QDate::fromString(value.toObject()["updatedAt"].toString(), Qt::DateFormat::ISODate);

                    _projects->append(ProjectDTO{projectId, projectName, projectDesription, estimateTime, createdAt, updatedAt});
                }

                for(auto item : *_projects)
                {
                    QString string = QString("%1 %2 %3 %4 %5 %6").arg(item.projectId).arg(item.projectName).arg(item.projectDesription).arg(item.estimateTime).arg(item.createdAt.toString()).arg(item.updatedAt.toString());
                    //qDebug() << string;
                }
                return _projects;
            })
            .then(this, [this](QList<ProjectDTO>* _projects) {
                //Создаём модель для отображения проектов и отправляем их в QML
                _model = new ProjectsModel(_projects, this);
                emit modelReady(_model);
            });
}

void ProjectAPI::getProjectById(int id)
{
    QString link = baseURL + QString("/api/projects/%1").arg(id);
    //Отправляем get-запрос на сервер
    QNetworkReply* res = _manager.get(QNetworkRequest(QUrl(link)));

    QtFuture::connect(res, &QNetworkReply::finished)
            .then([res]() {
                //Считываем полученные данные
                res->deleteLater();
                return res->readAll();
            })
            .then(QtFuture::Launch::Async, [this](const QByteArray &json) {
                //Парсим полученный Json в модель ProjectDetailsDTO
                ProjectDetailsDTO projectDetailsDTO;

                QString string = json;
                qDebug() << string;
                QJsonObject projectInfo = QJsonDocument::fromJson(json).object();

                int projectId = projectInfo["project_id"].toInt();
                QString projectName = projectInfo["project_name"].toString();
                QString projectDescription = projectInfo["project_description"].toString();
                int estimateTime = projectInfo["estimate_time"].toInt();
                QDate createdAt = QDate::fromString(projectInfo["createdAt"].toString(), Qt::DateFormat::ISODate);
                QDate updatedAt = QDate::fromString(projectInfo["updatedAt"].toString(), Qt::DateFormat::ISODate);

                projectDetailsDTO.project = ProjectDTO{projectId, projectName, projectDescription, estimateTime, createdAt, updatedAt};

                QJsonArray tasksInfo = projectInfo["tasks"].toArray();

                for (const auto &value : tasksInfo)
                {
                    int taskId = value.toObject()["task_id"].toInt();
                    QString taskName = value.toObject()["task_name"].toString();
                    QString taskDescription = value.toObject()["task_description"].toString();
                    QString priority = value.toObject()["priority"].toString();
                    QDate createdAt = QDate::fromString(value.toObject()["createdAt"].toString(), Qt::DateFormat::ISODate);
                    QDate updatedAt = QDate::fromString(value.toObject()["updatedAt"].toString(), Qt::DateFormat::ISODate);
                    projectDetailsDTO.tasks.append(TaskDTO{taskId, taskName, taskDescription, priority, createdAt, updatedAt});
                }

                return projectDetailsDTO;
            })
            .then(this, [this](const ProjectDetailsDTO &projectDetailsDTO) {
                //Создаём модель для отображения проектов и отправляем их в QML
                ProjectDetailsModel *model = new ProjectDetailsModel(projectDetailsDTO, this);
                qDebug() << model->getProjectName();
                emit projectDetailsModelReady(model);
            });
}

