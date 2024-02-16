import QtQuick 2.0
import QtQuick.Layouts 1.15

Item {
    Rectangle {
        anchors.fill: parent
        color: "#000000"

        ColumnLayout {
            width: parent.width
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true

                 RowLayout {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom

                    Image {
                        source: "qrc:/resource/image/resource/image/fiatLogo.png"
                    }
                    Image {
                        source: "qrc:/resource/image/resource/image/qtLogo.png"
                    }
                 }
            }

            Rectangle {
                Layout.fillWidth: true
                height: 25
                Layout.alignment: Qt.AlignHCenter
                color: "transparent"

                Text {
                    text: "ECM Dashboard | marcosgro03@gmail.com | 2024"
                    font.pixelSize: 18
                    color: "#d9d9d9"
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }
}
