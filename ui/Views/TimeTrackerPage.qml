import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3


Item {
    id: root
    signal timeTrackerPageReady()
    Connections {
        target: _project
        function onModelReady(m) {
            view.model = m
            console.log("Вызван сигнал модели")
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
                    color: "white"
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
                    }
                    GridView {
                            id: view
                            implicitHeight: projectsList.height
                            implicitWidth: projectsList.width
                            cellWidth: projectsList.width / 3
                            cellHeight: projectsList.height / 3
                            anchors { top: projectLabel.bottom; bottom: projectsList.bottom; left: projectsList.left; right: projectsList.right }
                            delegate: Rectangle {
                                id: item
                                implicitHeight: view.height / 2
                                implicitWidth: view.width / 3
                                property var view: GridView.view
                                property int itemIndex: index
                                Text {
                                    id: projectName
                                    text: `${model.projectName}\n\n\n ${model.projectDate.toLocaleDateString(Qt.locale("ru_RU"))}`
                                }
                                MouseArea {
                                    id: mouseArea
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    onEntered: {
                                        view.currentIndex = itemIndex
                                        parent.color = "lightsteelblue"
                                        console.log(mouseArea.containsMouse)
                                    }
                                    onExited: {
                                        parent.color = "white"
                                    }

                                    onClicked: {
                                        popup.open()

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
//                            highlight: Rectangle {
//                                id: highlightArea
//                                color: "lightsteelblue"
//                                radius: 5

//                            }
                            onCurrentIndexChanged: {

                                console.log(currentIndex)
                            }


//                                            Rectangle {
//                                                anchors.fill: view
//                                                color: "transparent"
//                                                border.color: "yellow"
//                                            }
                        }
                    Popup {
                        id: popup
                        width: 200
                        height: 300
                        modal: true
                        focus: true
                        closePolicy: Popup.CloseOnEscape

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

                    color: "white"
                    Layout.preferredHeight: timeTrackerPage.height / 3.5
                    Layout.preferredWidth: timeTrackerPage.width / 6
                    Layout.column: 0
                    Layout.row: 1
                    Layout.columnSpan: 2
                    Layout.rowSpan: 1
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    Label {
                        text: "Таймер"
                    }

                }

            }
        }
    }

    Component.onCompleted: {
        _project.getProjects()
        view.currentIndex = -1
        console.log("Компонент загружен")
    }
}

