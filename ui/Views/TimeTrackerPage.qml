import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3


Item {
    id: root
    //signal timeTrackerPageReady()
    //property var model: view.model






    Connections {
        target: _project
        function onModelReady(m) {
            projectView.model = m

            //console.log(model.projectName)
            //console.log("Вызван сигнал модели")
        }
    }

    TemplatePage {
        id: timeTrackerPage
        ColumnLayout {
            id: lay
            anchors.fill: parent
            Layout.minimumHeight: 100
            Layout.minimumWidth: 100
            anchors.margins: 10
            RowLayout {
                id: row
                Layout.alignment: Qt.AlignTop | Qt.AlignLeft
                Layout.fillWidth: true
                Rectangle {
                    id: efficientTime
                    Layout.preferredHeight: timeTrackerPage.height / 3
                    Layout.preferredWidth: timeTrackerPage.width / 3
                    radius: 4
                    color: "white"
                    Layout.fillWidth: true

                    Label {
                        text: "Полезное время"
                    }
                }

                Rectangle {
                    id: unefficientTime
                    radius: 4
                    color: "white"
                    Layout.preferredHeight: timeTrackerPage.height / 3
                    Layout.preferredWidth: timeTrackerPage.width / 3
                    Layout.fillWidth: true

                    Label {
                        text: "Бесполезное время"
                    }
                }

                Rectangle {
                    id: projectsCount
                    radius: 4
                    color: "white"
                    Layout.preferredHeight: timeTrackerPage.height / 3
                    Layout.preferredWidth: timeTrackerPage.width / 3
                    Layout.fillWidth: true

                    Label {
                        text: "Количество проектов"

                    }
                }
            }

            Item {
                Layout.fillHeight: true
            }

            GridLayout {
                id: _
                rows: 2
                columns: 3
                Layout.bottomMargin: 5
                Layout.alignment: Qt.AlignTop
                Layout.fillWidth: true
                Layout.fillHeight: true

                //                Rectangle {
                //                    anchors.fill: _
                //                    color: "transparent"
                //                    border.color: "yellow"
                //                }

                Rectangle {
                    id: projectsList
                    radius: 4
                    //color: "white"
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "#0f0f1c" }
                        GradientStop { position: 0.7; color: "#2b1f30" }
                    }

                    Layout.preferredHeight: timeTrackerPage.height / 3.5
                    Layout.preferredWidth: timeTrackerPage.width / 6
                    Layout.column: 0
                    Layout.row: 0
                    Layout.columnSpan: 2
                    Layout.rowSpan: 1
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        id: projectLabel
                        text: "Проекты"
                        color: "#c2c2c2"
                        width: parent.width
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
                        //anchors.bottomMargin: projectLabel.height
                    }
                    GridView {
                        id: projectView
                        //implicitHeight: projectsList.height
                        //implicitWidth: projectsList.width
                        cellWidth: projectsList.width / 3
                        cellHeight: projectsList.height / 3
                        anchors { top: projectLabel.bottom; bottom: projectsList.bottom; left: projectsList.left; right: projectsList.right }
                        anchors.topMargin: 10
                        //model: model
                        delegate: Rectangle {
                            id: item
                            implicitHeight: projectView.cellHeight
                            implicitWidth: projectView.cellWidth
                            color: "#2b1f30"
                            Text {
                                id: projectName
                                color: "#c2c2c2"
                                text: `${model.projectName}`
                                font.bold: true
                                font.pixelSize: 17
                                //anchors.horizontalCenter: parent.horizontalCenter
                                //verticalAlignment: Text.AlignHCenter
                                //horizontalAlignment: Text.AlignVCenter//Дата создания\n${model.projectDate.toLocaleDateString(Qt.locale("ru_RU"))}`
                            }
                            Text {
                                id: projectDate
                                color: "#c2c2c2"
                                text: `Дата создания:\n${model.projectDate.toLocaleString()}`
                                anchors.top: projectName.bottom
                            }

                            MouseArea {
                                id: mouseArea
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered: {
                                    projectView.currentIndex = index

                                    parent.color = "#6d7dad"
                                    console.log(mouseArea.containsMouse)
                                }
                                onExited: {
                                    //parent.gradient = projectsList.gradient
                                    parent.color = "#2b1f30"
                                }

                                onClicked: {
                                    //console.log(model.projectId)
                                    //_project.getProjects()
                                    //_project.getProjectById(model.projectId)
                                    popup.open(model.projectId)
                                }
                            }
                            //                                Rectangle {
                            //                                    anchors.fill: mouseArea
                            //                                    color: "transparent"
                            //                                    border.color: "yellow"
                            //                                }
                        }
                        focus: true
                        clip: true

                        //                                            Rectangle {
                        //                                                anchors.fill: view
                        //                                                color: "transparent"
                        //                                                border.color: "yellow"
                        //                                            }
                    }
                    Loader {
                        id: loader

                    }

                    TaskPopup {
                        id: popup
                        //anchors.top: root

                    }
                }

                Rectangle {
                    id: activity
                    radius: 4
                    color: "white"
                    Layout.preferredHeight: timeTrackerPage.height / 3
                    Layout.preferredWidth: timeTrackerPage.width / 2
                    Layout.column: 2
                    Layout.row: 0
                    Layout.columnSpan: 1
                    Layout.rowSpan: 2
                    Layout.fillHeight: true
                    Label {
                        text: "Недавняя активность"
                    }
                }

                Rectangle {
                    id: timer
                    radius: 4
                    color: "#2b1f30"
                    Layout.preferredHeight: timeTrackerPage.height / 3.5
                    Layout.preferredWidth: timeTrackerPage.width / 6
                    Layout.column: 0
                    Layout.row: 1
                    Layout.columnSpan: 2
                    Layout.rowSpan: 1
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    TimeTrackerPart {
                        id: timeTrackerPart
                        anchors.fill: parent
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        _project.getProjects()
        console.log("Компонент загружен")
    }
}

