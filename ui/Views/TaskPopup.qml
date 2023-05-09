import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: root
    property var _model: ({})

    Connections {
        target: _project
        function onProjectDetailsModelReady(model) {
            console.log("Вызван сигнал модели")
            console.log(_model.toString())
            _model = model
            tasksList.model = model.list
            console.log(_model.toString())
            console.log(model.projectName)
            console.log(_model.list)
        }
    }
    Popup {
        id: taskPopup
        anchors.centerIn: Overlay.overlay
        //contentWidth: headerWraper.width
        //contentHeight: headerWraper.height
        modal: true
        ColumnLayout {
                    id: popupWrapper
                    anchors.fill: parent
                    RowLayout {
                        id: headerProjectInfo

                        Image {
                            id: projectIcon
                            source: "qrc:/ui/Assets/project_icon.png"
                        }
                        Label {
                            id: projectNameLabel
                            text: _model == null ? "" : `Проект: ${_model.projectName}`
                        }
                    }
                    RowLayout {
                        id: headerProjectDates
                        Label {
                            id: projectCreatedLabel
                            text: _model == null ? "" : `Дата создания: ${_model.projectCreatedDate.toLocaleString()}`
                        }
                        Label {
                            id: projectUpdatedLabel
                            text: _model == null ? "" : `Дата обновления: ${_model.projectUpdatedDate.toLocaleString()}`
                        }
                    }
                    RowLayout {
                        id: descriptionPart
                        Image {
                            id: descriptionIcon
                            source: "qrc:/ui/Assets/description_icon.png"
                        }
                        Label {
                            id: projectDescriptionLabel
                            text: _model == null ? "" : `Описание: ${_model.projectDescription}`
                        }
                    }


                    ListView {
                        id: tasksList
                        width: parent.width
                        height: 100
                        header: Rectangle {
                            anchors {left: parent.left; right: parent.right}
                            implicitHeight: taskLabel.implicitHeight
                            Text {
                                id: taskLabel
                                text: "Задачи"
                            }
                        }

                        delegate: Rectangle {
                            id: tasksCheckBoxArea
                            color: "grey"
                            implicitHeight: tasksCheckBox.implicitHeight
                            anchors { left: taskPopup.left; right: taskPopup.right }
                            implicitWidth: tasksCheckBox.implicitWidth
                            CheckBox {
                                id: tasksCheckBox
                                text: model.taskName
                                onClicked: {
                                    tasksList.currentIndex = index
                                    _timeTracker.setTask(tasksList.model, tasksList.currentIndex)
                                    _timeTracker.setProject(projectView.model, projectView.currentIndex)
                                    console.log(_model.projectName)
                                    //console.log(projectView.currentIndex)
                                }
                            }
                        }
                    }

        }

    }

    function open(projectId) {
        taskPopup.open()
        _project.getProjectById(projectId)
    }
}
