import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

import ProjectAPI 1.0
//import TimeTracker 1.0

Item {
    id: root
    property var _model: ({})

    Connections {
        target: ProjectAPI
        function onProjectDetailsModelReady(model) {
            _model = model
            tasksList.model = model.list
        }
    }

    Popup {
        id: taskPopup
        anchors.centerIn: Overlay.overlay
        background: Rectangle {
            color: "#2b1f30"
        }

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
                    color: "#c2c2c2"
                    width: parent.width
                    font.bold: true
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            RowLayout {
                id: headerProjectDates
                Label {
                    id: projectCreatedLabel
                    text: _model == null ? "" : `Дата создания: ${_model.projectCreatedDate.toLocaleString()}`
                    color: "#c2c2c2"
                    width: parent.width
                    font.bold: true
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignHCenter
                }
                Label {
                    id: projectUpdatedLabel
                    text: _model == null ? "" : `Дата обновления: ${_model.projectUpdatedDate.toLocaleString()}`
                    color: "#c2c2c2"
                    width: parent.width
                    font.bold: true
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignHCenter
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
                    color: "#c2c2c2"
                    width: parent.width
                    font.bold: true
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            ListView {
                id: tasksList
                width: parent.width
                height: 200

                header: Rectangle {
                    anchors {left: parent.left; right: parent.right}
                    implicitHeight: taskLabel.implicitHeight
                    Text {
                        id: taskLabel
                        text: "Задачи"
                        color: "#c2c2c2"
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                    }
                }

                delegate: Rectangle {
                    id: tasksRadioBtn
                    implicitHeight: taskName.height
                    implicitWidth: taskName.width
                    color: tasksList.currentIndex == index ? "#6d7dad" : "#2b1f30"

                    Text {
                        id: taskName
                        text: `${model.taskName}`
                        color: "#c2c2c2"
                        font.bold: true
                        font.pixelSize: 17
                        horizontalAlignment: Text.AlignHCenter
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            tasksList.currentIndex = index
                        }
                    }
                }
            }

            Button {
                id: acceptBtn
                Layout.alignment: Qt.AlignHCenter
                width: 100
                height: 100
                text: "Выбрать задачу"
                onClicked: {
                    _timeTracker.setTask(tasksList.model, tasksList.currentIndex)
                    _timeTracker.setProject(projectView.model, projectView.currentIndex)
                    taskPopup.close()
                }
            }
        }
    }

    function open(projectId) {
        taskPopup.open()
        ProjectAPI.getProjectById(projectId)
    }
}
