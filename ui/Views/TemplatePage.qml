import QtQuick 2.15
import QtQuick.Controls 2.5

Page {
    id: root


    property alias backgroundColor: backgroundColor.color
    height: parent.height
    width: parent.width




    background: Rectangle {
        id: backgroundColor
        color: "grey"
    }


}
