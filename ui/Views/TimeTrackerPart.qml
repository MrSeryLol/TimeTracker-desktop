import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: root
    function startAndStopTimeTracker() {
        if (!_timeTracker.isTaskSelected) {
            startAndStopButton.enabled = false
        }
        else {
            if (_timeTracker.isRunning) {
                _timeTracker.stop();
            }
            else {
                _timeTracker.start();
            }
        }
    }
    function changeStatus() {
        if (!_timeTracker.isTaskSelected) {
            sleepButton.enabled = false
        }
        else {
            if (_timeTracker.isActive) {
                _timeTracker.pause()
            }
            else {
                _timeTracker.unpause()
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 5
        id: i
        RowLayout {
            Layout.alignment: Qt.AlignTop | Qt.AlignCenter
            Image {
                id: timeTrackericon
                source: "qrc:/ui/Assets/stopwatch_icon.png"
                fillMode: Image.PreserveAspectFit
            }
            Label {
                id: timeTrackerLabel
                text: "Учёт рабочего времени"
                color: "#c2c2c2"
                font.bold: true
                font.pixelSize: 20
            }
        }
        ColumnLayout {
            Layout.alignment: Qt.AlignCenter | Qt.AlignBottom
            Label {
                text: "Выберите задачу"
                color: "#c2c2c2"
                font.bold: true
                font.pixelSize: 20
                visible: _timeTracker.projectName === ''
            }
        }
        ColumnLayout {
            Layout.alignment: Qt.AlignTop | Qt.AlignCenter
            Text {
                id: activeProjectLabel
                text: `Проект: ${_timeTracker.projectName}`
                color: "#c2c2c2"
                font.bold: true
                font.pixelSize: 18
                visible: !(_timeTracker.projectName === '')
            }

            Text {
                text: `Текущая активная задача: ${_timeTracker.taskName}`
                color: "#c2c2c2"
                font.bold: true
                font.pixelSize: 16
                visible: !(_timeTracker.taskName === '')
            }
        }
        ColumnLayout {
            Layout.alignment: Qt.AlignCenter | Qt.AlignTop
            Label {
                id: stopWatch
                text: `Времени прошло: ${_timeTracker.mainTime.toLocaleTimeString()}`
                font.bold: true
                color: "#c2c2c2"
                font.pixelSize: 24
            }
            Label {
                id: status
                text: _timeTracker.isActive ? "Статус: Активен" : "Статус: Неактивен"
                font.bold: true
                color: "#c2c2c2"
                font.pixelSize: 10
            }
        }
        RowLayout {
            id: e
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Rectangle {
                id: startAndStopButtonArea
                width: startAndStopButton.width
                height: startAndStopButton.height
                color: "transparent"
                z: -1
                Image {
                    id: startAndStopButton
                    width: 32
                    height: 32
                    source: _timeTracker.isRunning ? "qrc:/ui/Assets/stop_button_icon.png" : "qrc:/ui/Assets/start_button_icon.png"
                }
                MouseArea {
                    anchors.fill: startAndStopButtonArea
                    hoverEnabled: true
                    onClicked: {
                        startAndStopTimeTracker()
                    }
                    onEntered: {
                        startAndStopButtonArea.color = "#6d7dad"
                    }
                    onExited: {
                        startAndStopButtonArea.color = "transparent"
                    }
                }
            }
            Rectangle {
                id: sleepButtonArea
                width: sleepButton.width
                height: sleepButton.height
                color: "transparent"
                z: -1
                Image {
                    id: sleepButton
                    width: 32
                    height: 32
                    source: _timeTracker.isActive ? "qrc:/ui/Assets/sleep_icon.png" : "qrc:/ui/Assets/in_work_icon.png"
                }
                MouseArea {
                    anchors.fill: sleepButtonArea
                    hoverEnabled: true
                    onClicked: {
                        changeStatus()
                    }
                    onEntered: {
                        sleepButtonArea.color = "#6d7dad"
                    }
                    onExited: {
                        sleepButtonArea.color = "transparent"
                    }
                }
            }
        }
    }

}
