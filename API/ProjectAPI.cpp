#include "ProjectAPI.h"

ProjectAPI::ProjectAPI(QObject* parent)
    : QObject{parent}
{
    _projects = new QList<ProjectDTO>();
}

ProjectsModel *ProjectAPI::model() const
{
    return _model;
}

ProjectDetailsModel *ProjectAPI::projectDetailsModel()
{
    return _projectDetails;
}


void ProjectAPI::createProjectDetailsModel()
{

}

//Получение всех проектов
void ProjectAPI::getAllProjectsForEmployee()
{
    //Формирование ссылки и заголовка для запроса
    QString url = baseURL + QString("/api/projects/userProjects/%1").arg(TokenParser::getUserId(userToken));
    QNetworkRequest request(url);
    auto header = QString("Bearer %1").arg(userToken);
    request.setRawHeader(QByteArray("Authorization"), header.toUtf8());

    //Отправка get-запроса на сервер
    QNetworkReply* res = _manager.get(request);

    QtFuture::connect(res, &QNetworkReply::finished)
            .then([res]() {
                //Считываем полученные данные
                res->deleteLater();
                return res->readAll();
            })
            .then(QtFuture::Launch::Async, [this](const QByteArray &json) {
                //Парсим полученный Json в модель ProjectDTO
                QJsonObject userInfo = QJsonDocument::fromJson(json).object();
                qDebug() << 1;

                QJsonArray projectsInfo = userInfo["Projects"].toArray();

                for(auto value : projectsInfo)
                {
                    qDebug() << value.toObject();
                    int projectId = value.toObject()["id"].toInt();
                    QString projectName = value.toObject()["project_name"].toString();
                    QString projectDesription = value.toObject()["project_description"].toString();
                    int estimateTime = value.toObject()["estimate_time"].toInt();
                    QDate createdAt = QDate::fromString(value.toObject()["createdAt"].toString(), Qt::DateFormat::ISODate);
                    QDate updatedAt = QDate::fromString(value.toObject()["updatedAt"].toString(), Qt::DateFormat::ISODate);

                    _projects->append(ProjectDTO{projectId, projectName, projectDesription, estimateTime, createdAt, updatedAt});
                }

                for(auto item : *_projects)
                {
                    QString string = QString("%1 %2 %3 %4 %5 %6").arg(item.projectId).arg(item.projectName).arg(item.projectDesсription).arg(item.estimateTime).arg(item.createdAt.toString()).arg(item.updatedAt.toString());
                    qDebug() << string;
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
    //Формирование ссылки и заголовка для запроса
    QString url = baseURL + QString("/api/projects/%1/").arg(id);
    QNetworkRequest request(url);
    auto header = QString("Bearer %1").arg(userToken);
    request.setRawHeader(QByteArray("Authorization"), header.toUtf8());

    //Отправляем get-запрос на сервер
    QNetworkReply* res = _manager.get(request);

    QtFuture::connect(res, &QNetworkReply::finished)
            .then([res]() {
                qDebug() << "Завершился";
                //Считываем полученные данные
                res->deleteLater();
                return res->readAll();
            })
            .then(QtFuture::Launch::Async, [](const QByteArray &json) {
                //Парсим полученный Json в модель ProjectDetailsDTO
                ProjectDetailsDTO projectDetailsDTO;
                qDebug() << userToken;

                QString string = json;
                qDebug() << string;
                QJsonObject projectInfo = QJsonDocument::fromJson(json).object();

                int projectId = projectInfo["project_id"].toInt();
                QString projectName = projectInfo["project_name"].toString();
                QString projectDescription = projectInfo["project_description"].toString();
                int estimateTime = projectInfo["estimate_time"].toInt();
                QDate createdAt = QDate::fromString(projectInfo["created_at"].toString(), Qt::DateFormat::ISODate);
                QDate updatedAt = QDate::fromString(projectInfo["updated_at"].toString(), Qt::DateFormat::ISODate);

                projectDetailsDTO.project = ProjectDTO{projectId, projectName, projectDescription, estimateTime, createdAt, updatedAt};

                projectDetailsDTO.tasks = new QList<TaskDTO>();
                QJsonArray tasksInfo = projectInfo["Tasks"].toArray();

                for (const auto &value : tasksInfo)
                {
                    int taskId = value.toObject()["id"].toInt();
                    QString taskName = value.toObject()["task_name"].toString();
                    QString taskDescription = value.toObject()["task_description"].toString();
                    QString priority = value.toObject()["priority"].toString();
                    QDate createdAt = QDate::fromString(value.toObject()["createdAt"].toString(), Qt::DateFormat::ISODate);
                    QDate updatedAt = QDate::fromString(value.toObject()["updatedAt"].toString(), Qt::DateFormat::ISODate);
                    projectDetailsDTO.tasks->append(TaskDTO{taskId, taskName, taskDescription, priority, createdAt, updatedAt});
                }

                return projectDetailsDTO;
            })
            .then(this, [this](const ProjectDetailsDTO &projectDetailsDTO) {
                //Создаём модель для отображения проектов и отправляем их в QML
                ProjectDetailsModel *model = new ProjectDetailsModel(projectDetailsDTO, this);
                emit projectDetailsModelReady(model);
            });
}

