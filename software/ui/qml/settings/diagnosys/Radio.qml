import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {

    property int buttonAnimationDuration: 40

    RowLayout {
        anchors.fill: parent

        Image {
            source: "qrc:/resource/image/resource/image/settings/radio/volumeMaskButton.png"
            Layout.alignment: Qt.AlignCenter

            RowLayout {
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 12

                Image {
                    id: muteVolumeButtonIcon
                    source: "qrc:/resource/image/resource/image/settings/radio/muteButton.png"
                    Layout.alignment: Qt.AlignBottom

                    SequentialAnimation {
                        id: muteButtonAnimation
                        running: false

                        PropertyAnimation {
                            target: muteVolumeButtonIcon
                            property: "scale"
                            from: 1.0
                            to: 1.2
                            duration: buttonAnimationDuration
                        }
                        PropertyAnimation {
                            target: muteVolumeButtonIcon
                            property: "scale"
                            from: 1.2
                            to: 1.0
                            duration: buttonAnimationDuration
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            muteButtonAnimation.running = true
                        }
                    }
                }
                ColumnLayout {
                    Image {
                        id: upVolumeButtonIcon
                        source: "qrc:/resource/image/resource/image/settings/radio/upVolumeButton.png"

                        SequentialAnimation {
                            id: upVolumeButtonAnimation
                            running: false

                            PropertyAnimation {
                                target: upVolumeButtonIcon
                                property: "scale"
                                from: 1.0
                                to: 1.2
                                duration: buttonAnimationDuration
                            }
                            PropertyAnimation {
                                target: upVolumeButtonIcon
                                property: "scale"
                                from: 1.2
                                to: 1.0
                                duration: buttonAnimationDuration
                            }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                upVolumeButtonAnimation.running = true
                            }
                        }
                    }
                    Image {
                        id: downVolumeButtonIcon
                        source: "qrc:/resource/image/resource/image/settings/radio/downVolumeButton.png"

                        SequentialAnimation {
                            id: downVolumeButtonAnimation
                            running: false

                            PropertyAnimation {
                                target: downVolumeButtonIcon
                                property: "scale"
                                from: 1.0
                                to: 1.2
                                duration: buttonAnimationDuration
                            }
                            PropertyAnimation {
                                target: downVolumeButtonIcon
                                property: "scale"
                                from: 1.2
                                to: 1.0
                                duration: buttonAnimationDuration
                            }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                downVolumeButtonAnimation.running = true
                            }
                        }
                    }
                }
            }
        }
        Image {
            source: "qrc:/resource/image/resource/image/settings/radio/sourceMaskButton.png"
            Layout.alignment: Qt.AlignCenter

            RowLayout {
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.left: parent.left
                anchors.leftMargin: 12

                ColumnLayout {
                    Image {
                        id: nextButtonIcon
                        source: "qrc:/resource/image/resource/image/settings/radio/nextButton.png"

                        SequentialAnimation {
                            id: nextButtonAnimation
                            running: false

                            PropertyAnimation {
                                target: nextButtonIcon
                                property: "scale"
                                from: 1.0
                                to: 1.2
                                duration: buttonAnimationDuration
                            }
                            PropertyAnimation {
                                target: nextButtonIcon
                                property: "scale"
                                from: 1.2
                                to: 1.0
                                duration: buttonAnimationDuration
                            }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                nextButtonAnimation.running = true
                            }
                        }
                    }
                    Image {
                        id: previousButtonIcon
                        source: "qrc:/resource/image/resource/image/settings/radio/previousButton.png"

                        SequentialAnimation {
                            id: previousButtonAnimation
                            running: false

                            PropertyAnimation {
                                target: previousButtonIcon
                                property: "scale"
                                from: 1.0
                                to: 1.2
                                duration: buttonAnimationDuration
                            }
                            PropertyAnimation {
                                target: previousButtonIcon
                                property: "scale"
                                from: 1.2
                                to: 1.0
                                duration: buttonAnimationDuration
                            }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                previousButtonAnimation.running = true
                            }
                        }
                    }
                }
                Image {
                    id: srcButtonIcon
                    source: "qrc:/resource/image/resource/image/settings/radio/srcButton.png"
                    Layout.alignment: Qt.AlignBottom

                    SequentialAnimation {
                        id: srcButtonAnimation
                        running: false

                        PropertyAnimation {
                            target: srcButtonIcon
                            property: "scale"
                            from: 1.0
                            to: 1.2
                            duration: buttonAnimationDuration
                        }
                        PropertyAnimation {
                            target: srcButtonIcon
                            property: "scale"
                            from: 1.2
                            to: 1.0
                            duration: buttonAnimationDuration
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            srcButtonAnimation.running = true
                        }
                    }
                }
            }
        }
    }
}
