import QtQuick 2.15
import QtQuick.Layouts 1.3

Item {
    Layout.fillWidth: true
    Layout.fillHeight: true

    property real fuelLevel: carParameterController.fuelLevel

    Rectangle {
        width: parent.width
        height: carOnRoad.implicitHeight
        color: "transparent"

        Rectangle {
            width: 75
            height: width
            color: "transparent"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20

            Image {
                id: fuelLevelIcon
                source: "qrc:/resource/image/resource/image/carParameter/fuelLevelIcon.png"
                width: 60
                height: width / sourceSize.width * sourceSize.height
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                text: fuelLevel
                color: "#fff"
                font.pixelSize: 22
                font.family: nesLowercaseFont.name
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
            }
        }
    }
}
