import QtQuick 2.15
import QtQuick.Layouts 1.3

Item {
    width: 100
    height: carOnRoad.implicitHeight

    property real turboPressure: carParameterController.turboPressure

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
                id: turboPressureIcon
                source: "qrc:/resource/image/resource/image/carParameter/turboPressureIcon.png"
                width: 70
                height: width / sourceSize.width * sourceSize.height
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                text: {
                    return (Math.round(turboPressure / 100) / 10) + " bar"
                }
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
