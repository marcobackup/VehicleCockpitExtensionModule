import QtQuick 2.15
import QtQuick.Layouts 1.3

Item {
    width: 100
    height: carOnRoad.implicitHeight

    property real coolantTemperature: carParameterController.coolantTemperature

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
                id: coolantTemperatureIcon
                source: "qrc:/resource/image/resource/image/carParameter/coolantTemperatureIcon.png"
                width: 60
                height: width / sourceSize.width * sourceSize.height
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                text: coolantTemperature + "°C"
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
