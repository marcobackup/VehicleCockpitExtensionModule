import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.15

Item {
    width: parent.width
    height: 60

    property real environmentalTemperature: topBarController.environmentalTemperature
    property string hour: topBarController.hour
    property bool leftArrowStatus: topBarController.leftArrowStatus
    property bool rightArrowStatus: topBarController.rightArrowStatus
    property bool lowBeamLightStatus: topBarController.lowBeamLightStatus
    property bool highBeamLightStatus: topBarController.highBeamLightStatus

    Rectangle {
        width: parent.width
        height: parent.height
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        color: "transparent"

        RowLayout {
            anchors.fill: parent

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignLeft
                radius: 8
                color: "transparent"

                Image {
                    id: weatherIcon
                    source: {
                        let currentHour = new Date().getHours();
                        if(currentHour >= 23 || currentHour <= 4)
                            return "qrc:/resource/image/resource/image/weather/moonWeatherIcon.png"
                        else {
                            if(environmentalTemperature <= 3)
                                return "qrc:/resource/image/resource/image/weather/snowWeatherIcon.png"
                            else if(environmentalTemperature > 3 && environmentalTemperature <= 12)
                                return "qrc:/resource/image/resource/image/weather/cloudlyWeatherIcon.png"
                            else if(environmentalTemperature > 12 && environmentalTemperature <= 20)
                                return "qrc:/resource/image/resource/image/weather/sunnyWeatherIcon.png"
                            else
                                return "qrc:/resource/image/resource/image/weather/fullSunWeatherIcon.png"
                        }
                    }
                    width: 50
                    height: width / sourceSize.width * sourceSize.height
                    anchors.left: parent.left
                    anchors.leftMargin: 20
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: environmentalTemperature + "°C"
                    font.pixelSize: 28
                    font.family: nesLowercaseFont.name
                    color: "#D9D9D9"
                    anchors.left: weatherIcon.right
                    anchors.leftMargin: 6
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
            Rectangle {
                height: parent.height
                Layout.fillWidth: true
                color: "transparent"

                RowLayout {
                    anchors.fill: parent
                    spacing: 0

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "transparent"

                        Image {
                            id: leftArrow
                            source: "qrc:/resource/image/resource/image/indicatorLight/leftArrow.png"
                            width: 22
                            height: width / sourceSize.width * sourceSize.height
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        ColorOverlay {
                            anchors.fill: leftArrow
                            source: leftArrow
                            color: {
                                if(leftArrowStatus)
                                    return "#64B68B"
                                else
                                    return "#000000"
                            }
                            transform: rotation
                            antialiasing: true
                        }
                    }
                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "transparent"

                        RowLayout {
                            anchors.fill: parent

                            Rectangle {
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "transparent"

                                Image {
                                    id: lowBeamLight
                                    source: "qrc:/resource/image/resource/image/indicatorLight/lowBeamLight.png"
                                    width: 42
                                    height: width / sourceSize.width * sourceSize.height
                                    anchors.left: parent.left
                                    anchors.verticalCenter: parent.verticalCenter
                                }
                                ColorOverlay {
                                    anchors.fill: lowBeamLight
                                    source: lowBeamLight
                                    color: {
                                        if(lowBeamLightStatus)
                                            return "#64B68B"
                                        else
                                            return "#000000"
                                    }
                                    transform: rotation
                                    antialiasing: true
                                }
                            }
                            Rectangle {
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                color: "transparent"

                                Image {
                                    id: highBeamLight
                                    source: "qrc:/resource/image/resource/image/indicatorLight/highBeamLight.png"
                                    width: 42
                                    height: width / sourceSize.width * sourceSize.height
                                    anchors.centerIn: parent
                                }
                                ColorOverlay {
                                    anchors.fill: highBeamLight
                                    source: highBeamLight
                                    color: {
                                        if(highBeamLightStatus)
                                            return "#2C47D5"
                                        else
                                            return "#000000"
                                    }
                                    transform: rotation
                                    antialiasing: true
                                }
                            }
                        }
                    }
                    Rectangle {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: "transparent"

                        Image {
                            id: rightArrow
                            source: "qrc:/resource/image/resource/image/indicatorLight/rightArrow.png"
                            width: 22
                            height: width / sourceSize.width * sourceSize.height
                            anchors.right: parent.right
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        ColorOverlay {
                            anchors.fill: rightArrow
                            source: rightArrow
                            color: {
                                if(rightArrowStatus)
                                    return "#64B68B"
                                else
                                    return "#000000"
                            }
                            transform: rotation
                            antialiasing: true
                        }
                    }
                }
            }
            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignRight
                color: "transparent"

                Image {
                    id: hourIcon
                    source: "qrc:/resource/image/resource/image/clockIcon.png"
                    width: 50
                    height: width / sourceSize.width * sourceSize.height
                    anchors.right: parent.right
                    anchors.rightMargin: 20
                    anchors.verticalCenter: parent.verticalCenter
                }
                Text {
                    text: hour
                    font.pixelSize: 28
                    font.family: nesLowercaseFont.name
                    color: "#D9D9D9"
                    anchors.right: hourIcon.left
                    anchors.rightMargin: 6
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }

    Timer {
        interval: 100
        running: true
        repeat: true
        onTriggered: {
            topBarController.hour = Qt.formatTime(new Date(), "hh:mm");
        }
    }
}
