import QtQuick 2.15
import QtQuick.Controls 2.15
import "diagnosys"
import "diagnosys/vehicleLight"
import "diagnosys/actuator"
import "user"

Item {
    anchors.fill: parent

    Rectangle {
        anchors.fill: parent
        color: "transparent"

        Image {
            source: "qrc:/resource/image/resource/image/settingsMask.png"
            anchors.centerIn: parent
        }

        /*
         *  user
         */
        Component {
            id: userSwipeView

            SwipeView {
                anchors.fill: parent
                anchors.centerIn: parent

                System {
                }

                EnvironmentalLight {
                }
            }
        }

        /*
         *  diagnosys
         */
        Component {
            id: diagnosysSwipeView

            SwipeView {
                anchors.fill: parent
                anchors.centerIn: parent

                System {
                }

                EnvironmentalLight {
                }

                Actuator {
                }

                InstrumentCluster {
                }

                VehicleLight {
                }

                Radio {
                }
            }
        }

        Loader {
            sourceComponent: {
                if(settingsController.settingsDiagnosysOpen)
                    return diagnosysSwipeView
                else
                    return userSwipeView
            }
            anchors.fill: parent
        }

        Image {
            id: goDashboardButtonIcon
            source: "qrc:/resource/image/resource/image/tripFlag.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom

            Text {
                anchors.centerIn: parent
                color: "#fff"
                text: "DASHBOARD"
                font.family: nesLowercaseFont.name
                font.pixelSize: 19
            }

            SequentialAnimation {
                id: goDashboardButtonAnimation
                running: false

                PropertyAnimation {
                    target: goDashboardButtonIcon
                    property: "scale"
                    from: 1.0
                    to: 1.1
                    duration: 30
                }
                PropertyAnimation {
                    target: goDashboardButtonIcon
                    property: "scale"
                    from: 1.1
                    to: 1.0
                    duration: 30
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    goDashboardButtonAnimation.running = true
                    mainComponentLoader.sourceComponent = mainComponent
                }
            }
        }
    }
}
