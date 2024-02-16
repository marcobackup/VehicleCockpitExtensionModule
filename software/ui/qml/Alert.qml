import QtQuick 2.15
import QtQuick.Layouts 1.3

Item {
    width: 330
    height: 90

    property string alertType
    property string alertIcon
    property string alertTitle
    property string alertDescription
    property string alertIconOverlay: ""

    Rectangle {
        width: parent.width
        height: parent.height
        color: "#D9D9D9"

        Rectangle {
            id: alertBadge
            width: 10
            height: parent.height
            color: {
                if(alertType == "warning")
                    return "#FFAD18"
                else if(alertType == "fault")
                    return "#EE3426"
                else
                    return "#1E1E1E"
            }
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.bottom: parent.bottom
        }

        Rectangle {
            anchors.left: alertBadge.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            RowLayout {
                anchors.fill: parent

                Rectangle {
                    width: 50
                    height: width
                    color: "transparent"
                    Layout.margins: 12

                    Image {
                        source: alertIcon
                        width: 64
                        height: width / sourceSize.width * sourceSize.height
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    Layout.fillWidth: true
                    height: 70

                    ColumnLayout {
                        anchors.fill: parent

                        Text {
                            text: alertTitle
                            color: "#1E1E1E"
                            font.bold: true
                            font.pixelSize: 20
                            font.family: nesLowercaseFont.name
                            Layout.alignment: Qt.AlignBottom
                        }
                        Text {
                            width: 50
                            text: alertDescription
                            color: "#1E1E1E"
                            font.pixelSize: 16
                            wrapMode: Text.WrapAnywhere
                            Layout.alignment: Qt.AlignTop
                        }
                    }
                }
            }
        }
    }
}
