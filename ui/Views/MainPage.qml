import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import "../TopBar"

ApplicationWindow {
    id: root
    width: 1280
    height: 720
    visible: true
    title: qsTr("Учёт рабочего времени сотрудников")

    header: MenuButtons {
        id: menu
    }

    StackView {
        id: stack
        width: root.width
        height: root.height - menu.height
        initialItem: mainView
    }
    TimeTrackerPage {
        id: mainView
    }
}
