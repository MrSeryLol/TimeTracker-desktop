QT += quick network

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        API/AuthAPI.cpp \
        API/HistoryOfWorkAPI.cpp \
        API/ProjectAPI.cpp \
        API/Token.cpp \
        Models/ProjectDetailsModel.cpp \
        Models/TasksModel.cpp \
        Models/ProjectsModel.cpp \
        Utils/TimeTracker/TimeTracker.cpp \
        Utils/TokenParser/TokenParser.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    API/AuthAPI.h \
    API/HistoryOfWorkAPI.h \
    API/IBaseAPI.h \
    API/BaseURL.h \
    API/ProjectAPI.h \
    API/Token.h \
    DTO/HistoryOfWorkDTO.h \
    DTO/ProjectDTO.h \
    DTO/ProjectDetailsDTO.h \
    DTO/TaskDTO.h \
    Models/ProjectDetailsModel.h \
    Models/TasksModel.h \
    Models/ProjectsModel.h \
    Utils/TimeTracker/TimeTracker.h \
    Utils/TokenParser/TokenParser.h

DISTFILES +=
