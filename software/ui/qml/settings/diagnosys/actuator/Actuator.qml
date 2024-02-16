import QtQuick 2.0
import QtQuick.Layouts 1.15

Item {

    RowLayout {
        width: 210
        height: parent.height
        anchors.centerIn: parent

        ButtonActuator {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignVCenter
        }
        Image {
            source: "qrc:/resource/image/resource/image/settings/settingsCar.png"
        }
        ButtonActuator {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignVCenter
        }
    }
}
