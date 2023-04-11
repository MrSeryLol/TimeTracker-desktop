import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    readonly property alias defMargin: menuBar.implicitHeight



    id: menuBar
    anchors.left: parent.left
    implicitWidth: parent.width
    implicitHeight: companyBtn.height + 10
    anchors.leftMargin: 10

    Button {
        id: workingSpaceBtn
        text: "Рабочее пространство"
        anchors.left: menuBar.left
        anchors.top: menuBar.top
        anchors.topMargin: (defMargin - workingSpaceBtn.height) / 2
        anchors.leftMargin: 30

        onClicked: {
            printInfo()
        }
    }

    Button {
        id: companyBtn
        text: "Компания"
        anchors.left: workingSpaceBtn.right
        anchors.top: menuBar.top
        anchors.topMargin: (defMargin - companyBtn.height) / 2

        anchors.leftMargin: 30

        onClicked: {
            printInfo()
        }

        MouseArea {
            id: mouseAreaBtn
            anchors.fill: companyBtn
            hoverEnabled: true
            onEntered: menu.open()
        }

        Menu {
            id: menu
            y: companyBtn.height


            MenuItem {
                text: "Проекты"
            }
        }
    }
    function printInfo() {
        console.log(companyBtn.height)
        console.log(menuBar.implicitHeight)
    }
}


