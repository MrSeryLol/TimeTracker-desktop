import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import "./ui/TopBar"
import "./ui/Views"

ApplicationWindow {
    id: root
    width: 1280
    height: 720
    visible: true
    title: qsTr("Hello World")


//    menuBar: MenuBar {

//    }

    header: MenuButtons {
        id: menu
    }



    Rectangle {
        anchors.fill: menu
        border.width: 4
        border.color: "yellow"
        color: "transparent"
    }

//    RowLayout {
//        anchors.fill: parent

//        StackView {
//               id: stack
//               width: root.width
//               height: root.height
//    //           anchors.left: root.left
//    ////           anchors.top: menu.bottom
//    //           anchors.margins: 20
//    //           initialItem: Qt.resolvedUrl("qrc:/ui/Views/TimeTrackerPage.qml")
//    //           anchors.fill: parent
//               initialItem: mainview
//        }
//        TimeTrackerPage {
//            id: mainview
//            backgroundColor: "black"
//            anchors.left: root.left
////            anchors.top: root.top
//    //        width: menu.
//    //        height: 50
//        }
//    }



        StackView {
               id: stack
               width: root.width
               height: root.height - menu.height
    //           anchors.left: root.left
    ////           anchors.top: menu.bottom
    //           anchors.margins: 20
    //           initialItem: Qt.resolvedUrl("qrc:/ui/Views/TimeTrackerPage.qml")
    //           anchors.fill: parent
               initialItem: mainview
        }
        TimeTrackerPage {
            id: mainview
//            Button {
//                   text: "Open"
//                   onClicked: popup.open()
//               }

//               Popup {
//                   id: popup
//                   x: 100
//                   y: 100
//                   width: 200
//                   height: 300
//                   modal: true
//                   focus: true
//                   closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
//               }
//            backgroundColor: "black"
    }






//    Rectangle {
//        anchors.fill: stack
//        border.width: 4
//        border.color: "yellow"
//        color: "transparent"
//    }

//    TimeTrackerPage {
//        id: mainview
//        backgroundColor: "black"
////        Label {
////            id: label
////            Layout.alignment: Qt.AlignHCenter
////            text: "Выберите проект"
////            font.pointSize: 14
////            font.bold: true
////        }
////        anchors.left: root.left
////        anchors.top: root.top
////        width: menu.
////        height: 50
//    }
}

//    RowLayout {
//        anchors.fill: parent

//        StackView {
//               id: stack
//               width: root.width
//               height: root.height - menu.height
//               anchors.left: root.left
//               anchors.top: header.bottom
////               anchors.margins: 20
//    //           initialItem: Qt.resolvedUrl("qrc:/ui/Views/TimeTrackerPage.qml")
//    //           anchors.fill: parent
//               initialItem: mainview
//        }

//        TimeTrackerPage {
//            id: mainview
//            backgroundColor: "black"
//    //        anchors.left: root.left
//    //        anchors.top: menu.top
//    //        width: menu.
//    //        height: 50
//        }
//    }




//    StackView {
//           id: stack
//           width: root.width
//           height: root.height
//           anchors.left: root.left
//           anchors.top: header.bottom
//           anchors.margins: 20
////           initialItem: Qt.resolvedUrl("qrc:/ui/Views/TimeTrackerPage.qml")
////           anchors.fill: parent
//           initialItem: mainview
//    }

//    TimeTrackerPage {
//        id: mainview
//        backgroundColor: "black"
////        anchors.left: root.left
////        anchors.top: menu.top
////        width: menu.
////        height: 50
//    }
//}

//    TimeTrackerPage {
//        id: timeTrackerPage
////        width: root.width
////        height: root.height
////        backgroundColor: "red"

//    }





//    Component {
//            id: mainView

//            Row {
//                spacing: 10

//                Button {
//                    text: "Push"
//                    onClicked: stack.push(mainView)
//                }
//                Button {
//                    text: "Pop"
//                    enabled: stack.depth > 1
//                    onClicked: stack.pop()

//                }
//                Text {
//                    text: stack.depth
//                }
//            }
//    }






//        text: "Рабочее пространство"


//    menuBar: MenuBar {
//            Menu {
//                title: qsTr("&File")
//                Action { text: qsTr("&New...") }
//                Action { text: qsTr("&Open...") }
//                Action { text: qsTr("&Save") }
//                Action { text: qsTr("Save &As...") }
//                MenuSeparator { }
//                Action { text: qsTr("&Quit") }
//            }
//            Menu {
//                title: qsTr("&Edit")
//                Action { text: qsTr("Cu&t") }
//                Action { text: qsTr("&Copy") }
//                Action { text: qsTr("&Paste") }
//            }
//            Menu {
//                title: qsTr("&Help")
//                Action { text: qsTr("&About") }
//            }
//            delegate: MenuBarItem {
//                    id: menuBarItem

//                    enabled: text !== "jjjjjjjj"
//                }
//        }


//    Button {
//        id: fileButton
//        text: "Учёт рабочего времени"
////        onClicked: menu.open()
//        onHoveredChanged: menu.open() ? true : false

//        Menu {
//            id: menu
//            y: fileButton.height

//            MenuItem {
//                text: "New..."
//            }
//            MenuItem {
//                text: "Open..."
//            }
//            MenuItem {
//                text: "Save"
//            }
//        }
//    }

