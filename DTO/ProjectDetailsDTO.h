#ifndef PROJECTDETAILSDTO_H
#define PROJECTDETAILSDTO_H


#include "DTO/ProjectDTO.h"
#include "DTO/TaskDTO.h"

class ProjectDetailsDTO
{
public:
    ProjectDTO project;
    QList<TaskDTO> tasks;
};

#endif // PROJECTDETAILSDTO_H
