import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: root

    //var projectId = 0;
    //signal message(string msg)
    property var _model: ({})

    Connections {
        target: _project
        function onProjectDetailsModelReady(model) {
            console.log("Вызван сигнал модели")
            _model = model
            console.log(_model.hasOwnProperty(getProjectName))


        }
    }

    //readonly property alias _model: view.model

    Popup {
        id: taskPopup
        anchors.centerIn: Overlay.overlay
        //anchors.fill: parent
        //width: 200
        //height: 200
        modal: true

        ColumnLayout {

            id: header
            anchors.fill: parent

            Label {
                id: projectName
                text: `Проект: ${_model.getProjectName}`
            }
        }
    }

    function open(projectId) {
        //console.log(projectId)
        taskPopup.open()
        _project.getProjectById(projectId)
        //console.log(projectId)
        //console.log("Инфа")
        //_model = model

    }
}
