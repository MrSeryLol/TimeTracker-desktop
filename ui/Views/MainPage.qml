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
    title: qsTr("Hello World")

    header: MenuButtons {
        id: menu
    }

//    ListModel {
//        id: names
//        ListElement { name: "Сергей" }
//    }

//    ListView {
//        //width: 100
//        //height: 100

//        model: names

//        delegate: Text {
//            text: model.name
//        }

//    }



    //    Rectangle {
    //        anchors.fill: menu
    //        border.width: 4
    //        border.color: "yellow"
    //        color: "transparent"
    //    }

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
        initialItem: mainView
    }
    TimeTrackerPage {
        id: mainView
        //onTimeTrackerPageReady: () => _project.getProjects()


        //onTimeTrakckerPageReady: _project.getProjects();
//        onTimeTrakckerPageReady: _project.getProjects();
//        ListView {
//            anchors.fill: parent
//            model: _project.model
//            delegate: Text {
//                text: _project.model.projectName
//            }
//        }
    }
   Component.onCompleted: {
       Qt.destroy("../../main.qml")
   }
}
