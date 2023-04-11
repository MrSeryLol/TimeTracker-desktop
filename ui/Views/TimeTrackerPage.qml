import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3


Item {
    id: root

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

                Rectangle {
                    anchors.fill: _
                    color: "transparent"
                    border.color: "yellow"
                }

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
                        text: "Проекты"
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
}

