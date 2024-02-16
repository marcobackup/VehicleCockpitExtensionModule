import QtQuick 2.0
import QtQuick.Controls 2.15
import "gauge"

Item {
    anchors.left: parent.left
    anchors.right: parent.right

    Rectangle {
        anchors.fill: parent
        color: "transparent"

        SwipeView {
            anchors.left: parent.lelft
            anchors.right: parent.right
            height: 190
            anchors.horizontalCenter: parent.horizontalCenter

            Speed {
            }

            Rpm {
            }
        }

        CarParameter {
            anchors.bottom: parent.bottom
        }

        Image {
            source: {
                if(bottomBarController.handBrakeStatus || bottomBarController.bonnetStatus) {
                    return "qrc:/resource/image/resource/image/car/carParked.png"
                } else {
                    if(topBarController.lowBeamLightStatus || topBarController.highBeamLightStatus)
                        return "qrc:/resource/image/resource/image/car/carLightOn.png"
                    else
                        return "qrc:/resource/image/resource/image/car/carLightOff.png"
                }
            }
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
        }

        Image {
            id: goSettingsButtonIcon
            source: "qrc:/resource/image/resource/image/tripFlag.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom

            Text {
                anchors.centerIn: parent
                color: "#fff"
                text: "IMPOSTAZIONI"
                font.family: nesLowercaseFont.name
                font.pixelSize: 19
            }

            SequentialAnimation {
                id: goSettingsButtonAnimation
                running: false

                PropertyAnimation {
                    target: goSettingsButtonIcon
                    property: "scale"
                    from: 1.0
                    to: 1.1
                    duration: 30
                }
                PropertyAnimation {
                    target: goSettingsButtonIcon
                    property: "scale"
                    from: 1.1
                    to: 1.0
                    duration: 30
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    goSettingsButtonAnimation.running = true
                    mainComponentLoader.sourceComponent = settingsComponent
                }
            }
        }
    }
}
