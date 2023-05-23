import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import AuthAPI 1.0
import "./ui/Errors"

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
            root.close()
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
