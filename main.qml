import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import AuthAPI 1.0
import "./ui/Errors"

Window {
    id: root

    Connections {
        target: AuthAPI
        function onFailVerification(error) {
            errorMessage.text = error
        }

        function onSuccessVerification() {
            var component = Qt.createComponent("./ui/Views/MainPage.qml")
            component.createObject()
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
            }

            TextField {
                id: loginInput
                placeholderText: "Введите свой логин"
            }

            Text {
                id: passwordLabel
                text: "Пароль"
            }

            TextField {
                id: passwordInput
                placeholderText: "Введите свой пароль"
            }

            Button {
                id: signInBtn
                Layout.preferredWidth: passwordInput.width
                text: "Войти"
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
