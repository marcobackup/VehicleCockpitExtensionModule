import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.15

Item {

    property int ambientLightSource: settingsController.ambientLightSource
    property real ambientLightLRSeatLevel: settingsController.ambientLightLRSeatLevel
    property real ambientLightRRSeatLevel: settingsController.ambientLightRRSeatLevel

    function map(value, fromLow, fromHigh, toLow, toHigh) {
        value = Math.min(Math.max(value, fromLow), fromHigh);
        var ratio = (value - fromLow) / (fromHigh - fromLow);
        return toLow + ratio * (toHigh - toLow);
    }

    RowLayout {
        anchors.fill: parent

        ColumnLayout {
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignRight

            Image {
                Layout.alignment: Qt.AlignHCenter
                source: "qrc:/resource/image/resource/image/settings/seat.png"

                Rectangle {
                    id: ambientLightLRSeatRepr
                    width: parent.width - 30
                    height: 40
                    color: "#fff"
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    radius: 360
                    opacity: map(settingsController.ambientLightLRSeatLevel, 0, 255, 0, 1)
                }
            }
            Slider {
                id: ambientLightLRSeatSlider
                Layout.alignment: Qt.AlignHCenter
                enabled: true

                onValueChanged: {
                    settingsController.ambientLightLRSeatLevel = map(ambientLightLRSeatSlider.value, 0, 1, 0, 255)
                }
            }
        }
        Rectangle {
            width: ambientLightSource.width
            Layout.alignment: Qt.AlignHCenter
            Layout.fillHeight: true
            color: "transparent"

            Text {
                text: "SORGENTE"
                font.pixelSize: 24
                font.family: nesLowercaseFont.name
                color: "#fff"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: ambientLightSource.top
                anchors.bottomMargin: 10
            }
            ComboBox {
                id: ambientLightSource
                width: 200
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 50

                model: ListModel {
                    ListElement {
                        text: "Veicolo"
                    }
                    ListElement {
                        text: "Regolazione"
                    }
                }

                onCurrentIndexChanged: {
                    settingsController.ambientLightSource = ambientLightSource.currentIndex
                }
            }
        }
        ColumnLayout {
            width: 200
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignLeft

            Image {
                Layout.alignment: Qt.AlignHCenter
                source: "qrc:/resource/image/resource/image/settings/seat.png"

                Rectangle {
                    id: ambientLightRRSeatRepr
                    width: parent.width - 30
                    height: 40
                    color: "#fff"
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    radius: 360
                    opacity: map(settingsController.ambientLightRRSeatLevel, 0, 255, 0, 1)
                }
            }
            Slider {
                id: ambientLightRRSeatSlider
                Layout.alignment: Qt.AlignHCenter
                enabled: true
                onValueChanged: {
                    settingsController.ambientLightRRSeatLevel = map(ambientLightRRSeatSlider.value, 0, 1, 0, 255)
                }
            }
        }
    }
}
