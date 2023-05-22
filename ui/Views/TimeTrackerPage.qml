import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: root

    Connections {
        target: _project
        function onModelReady(m) {
            projectView.model = m
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

                Rectangle {
                    id: projectsList
                    radius: 4
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
                    }

                    GridView {
                        id: projectView
                        cellWidth: projectsList.width / 3
                        cellHeight: projectsList.height / 3
                        anchors { top: projectLabel.bottom; bottom: projectsList.bottom; left: projectsList.left; right: projectsList.right }
                        anchors.topMargin: 10
                        delegate: Rectangle {
                            id: projectItem
                            implicitHeight: projectView.cellHeight
                            implicitWidth: projectView.cellWidth
                            color: "#2b1f30"
                            Text {
                                id: projectName
                                color: "#c2c2c2"
                                text: `${model.projectName}`
                                font.bold: true
                                font.pixelSize: 17
                            }
                            Text {
                                id: projectDate
                                color: "#c2c2c2"
                                text: `Дата создания:\n${model.projectDate.toLocaleString()}`
                                anchors.bottom: projectItem.bottom
                            }

                            MouseArea {
                                Loader {
                                    id: loader
                                }
                                id: mouseArea
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered: {
                                    projectView.currentIndex = index
                                    parent.color = "#6d7dad"
                                }
                                onExited: {
                                    parent.color = "#2b1f30"
                                }

                                onClicked: {
                                    loader.source = "TaskPopup.qml"
                                    loader.item.open(model.projectId)
                                }
                            }
                        }
                        focus: true
                        clip: true
                    }
                }

                Rectangle {
                    id: activity
                    radius: 4
                    color: "#2b1f30"
                    Layout.preferredHeight: timeTrackerPage.height / 3
                    Layout.preferredWidth: timeTrackerPage.width / 2
                    Layout.column: 2
                    Layout.row: 0
                    Layout.columnSpan: 1
                    Layout.rowSpan: 2
                    Layout.fillHeight: true
                    Label {
                        text: "Недавняя активность"
                        color: "#c2c2c2"
                        width: parent.width
                        font.bold: true
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignHCenter
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

