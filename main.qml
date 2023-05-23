import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import AuthAPI 1.0
import "./ui/Errors"

import "./ui/TopBar"
import "./ui/Views"

//Instantiator {
//    id: root
//    delegate: MainPage
//}

//ApplicationWindow {
//    id: root
//    width: 1280
//    height: 720
//    visible: true
//    title: qsTr("Hello World")

//    header: MenuButtons {
//        id: menu
//    }

////    ListModel {
////        id: names
////        ListElement { name: "Сергей" }
////    }

////    ListView {
////        //width: 100
////        //height: 100

////        model: names

////        delegate: Text {
////            text: model.name
////        }

////    }



//    //    Rectangle {
//    //        anchors.fill: menu
//    //        border.width: 4
//    //        border.color: "yellow"
//    //        color: "transparent"
//    //    }

//    //    RowLayout {
//    //        anchors.fill: parent

//    //        StackView {
//    //               id: stack
//    //               width: root.width
//    //               height: root.height
//    //    //           anchors.left: root.left
//    //    ////           anchors.top: menu.bottom
//    //    //           anchors.margins: 20
//    //    //           initialItem: Qt.resolvedUrl("qrc:/ui/Views/TimeTrackerPage.qml")
//    //    //           anchors.fill: parent
//    //               initialItem: mainview
//    //        }
//    //        TimeTrackerPage {
//    //            id: mainview
//    //            backgroundColor: "black"
//    //            anchors.left: root.left
//    ////            anchors.top: root.top
//    //    //        width: menu.
//    //    //        height: 50
//    //        }
//    //    }



//    StackView {
//        id: stack
//        width: root.width
//        height: root.height - menu.height
//        //           anchors.left: root.left
//        ////           anchors.top: menu.bottom
//        //           anchors.margins: 20
//        //           initialItem: Qt.resolvedUrl("qrc:/ui/Views/TimeTrackerPage.qml")
//        //           anchors.fill: parent
//        initialItem: mainView
//    }
//    TimeTrackerPage {
//        id: mainView
//        //onTimeTrackerPageReady: () => _project.getProjects()


//        //onTimeTrakckerPageReady: _project.getProjects();
////        onTimeTrakckerPageReady: _project.getProjects();
////        ListView {
////            anchors.fill: parent
////            model: _project.model
////            delegate: Text {
////                text: _project.model.projectName
////            }
////        }
//    }
////   Component.onCompleted: {
////       Qt.destroy("../../main.qml")
////   }

//}

Window {
    id: root
    color: "#2b1f30"
    property var mainWindow: ({})

    Connections {
        target: AuthAPI
        function onFailVerification(error) {
            errorMessage.text = error
        }

        function onSuccessVerification() {
            var component = Qt.createComponent("./ui/Views/MainPage.qml")
            mainWindow = component.createObject(null, { "id": "root" })
            root.hide()
        }
    }

    title: "Вход в систему"
    width: 600
    height: 400
    visible: true
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    flags: Qt.Dialog | Qt.CustomizeWindowHint | Qt.WindowTitleHint | Qt.WindowCloseButtonHint | Qt.WindowSystemMenuHint

    ColumnLayout {
        id: lay
        anchors.fill: parent

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignCenter

            Text {
                id: loginLabel
                text: "Логин"
                color: "#c2c2c2"
                font.bold: true
                font.pixelSize: 17
            }

            TextField {
                id: loginInput
                placeholderText: "Введите свой логин"
            }

            Text {
                id: passwordLabel
                text: "Пароль"
                color: "#c2c2c2"
                font.bold: true
                font.pixelSize: 17
            }

            TextField {
                id: passwordInput
                placeholderText: "Введите свой пароль"
                echoMode: TextInput.Password
            }

            RoundButton  {
                id: signInBtn
                Layout.preferredWidth: passwordInput.width
                text: "Войти"
                font.bold: true
                font.pixelSize: 17

                background: Rectangle {
                    opacity: enabled ? 1 : 0.3
                    border.color: signInBtn.down ? "white" : "#c2c2c2"
                    border.width: 1
                    color: "#2b1f30"
                    radius: 2
                }

                contentItem: Text {
                    text: signInBtn.text
                    font: signInBtn.font
                    color: "#c2c2c2"
                    opacity: enabled ? 1.0 : 0.3
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }


                onClicked: {
                    console.log("Введён пароль")
                    AuthAPI.signIn(loginInput.text, passwordInput.text)
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignCenter | Qt.AlignTop
            ErrorMessage {
                id: errorMessage
            }
        }

        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
