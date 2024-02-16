import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.15

Item {
    width: parent.width
    height: 50
    anchors.bottom: parent.bottom

    property bool handBrakeStatus: bottomBarController.handBrakeStatus
    property bool steeringWheelFaultStatus: bottomBarController.steeringWheelFaultStatus
    property bool sbrRLStatus: bottomBarController.sbrRLStatus
    property bool sbrRCStatus: bottomBarController.sbrRCStatus
    property bool sbrRRStatus: bottomBarController.sbrRRStatus
    property bool bonnetStatus: bottomBarController.bonnetStatus
    property bool lightFaultStatus: bottomBarController.lightFaultStatus

    Rectangle {
        anchors.fill: parent
        color: "#050505"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top

        RowLayout {
            anchors.fill: parent

            RowLayout {
                Layout.alignment: Qt.AlignLeft
                Layout.leftMargin: 10

                Rectangle {
                    width: 50
                    Layout.fillHeight: true
                    color: "transparent"

                    Image {
                        id: handBrakeIcon
                        source: "qrc:/resource/image/resource/image/indicatorLight/handBrake.png"
                        width: 46
                        height: width / sourceSize.width * sourceSize.height
                        anchors.centerIn: parent
                    }
                    ColorOverlay {
                        anchors.fill: handBrakeIcon
                        source: handBrakeIcon
                        color: {
                            if(handBrakeStatus)
                                return "#EE3426"
                            else
                                return "#000000"
                        }
                        transform: rotation
                        antialiasing: true
                    }
                }
                Rectangle {
                    width: 50
                    Layout.fillHeight: true
                    color: "transparent"

                    Image {
                        id: steeringWheelFaultIcon
                        source: "qrc:/resource/image/resource/image/indicatorLight/steeringWheelFault.png"
                        width: 37
                        height: width / sourceSize.width * sourceSize.height
                        anchors.centerIn: parent
                    }
                    ColorOverlay {
                        anchors.fill: steeringWheelFaultIcon
                        source: steeringWheelFaultIcon
                        color: {
                            if(steeringWheelFaultStatus)
                                return "#EE3426"
                            else
                                return "#000000"
                        }
                        transform: rotation
                        antialiasing: true
                    }
                }
            }
            RowLayout {
                Layout.alignment: Qt.AlignCenter

                Rectangle {
                    width: 40
                    Layout.fillHeight: true
                    color: "transparent"

                    Image {
                        id: sbrRLIcon
                        source: "qrc:/resource/image/resource/image/indicatorLight/sbr.png"
                        width: 32
                        height: width / sourceSize.width * sourceSize.height
                        anchors.centerIn: parent
                    }
                    ColorOverlay {
                        anchors.fill: sbrRLIcon
                        source: sbrRLIcon
                        color: {
                            if(!sbrRLStatus)
                                return "#EE3426"
                            else
                                return "#000000"
                        }
                        transform: rotation
                        antialiasing: true
                    }
                }
                Rectangle {
                    width: 40
                    Layout.fillHeight: true
                    color: "transparent"

                    Image {
                        id: sbrRCIcon
                        source: "qrc:/resource/image/resource/image/indicatorLight/sbr.png"
                        width: 32
                        height: width / sourceSize.width * sourceSize.height
                        anchors.centerIn: parent
                    }
                    ColorOverlay {
                        anchors.fill: sbrRCIcon
                        source: sbrRCIcon
                        color: {
                            if(!sbrRCStatus)
                                return "#EE3426"
                            else
                                return "#000000"
                        }
                        transform: rotation
                        antialiasing: true
                    }
                }
                Rectangle {
                    width: 40
                    Layout.fillHeight: true
                    color: "transparent"

                    Image {
                        id: sbrRRIcon
                        source: "qrc:/resource/image/resource/image/indicatorLight/sbr.png"
                        width: 32
                        height: width / sourceSize.width * sourceSize.height
                        anchors.centerIn: parent
                    }
                    ColorOverlay {
                        anchors.fill: sbrRRIcon
                        source: sbrRRIcon
                        color: {
                            if(!sbrRRStatus)
                                return "#EE3426"
                            else
                                return "#000000"
                        }
                        transform: rotation
                        antialiasing: true
                    }
                }
            }
            RowLayout {
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 10

                Rectangle {
                    width: 50
                    Layout.fillHeight: true
                    color: "transparent"

                    Image {
                        id: lightFaultIcon
                        source: "qrc:/resource/image/resource/image/indicatorLight/lightFault.png"
                        width: 44
                        height: width / sourceSize.width * sourceSize.height
                        anchors.centerIn: parent
                    }
                    ColorOverlay {
                        anchors.fill: lightFaultIcon
                        source: lightFaultIcon
                        color: {
                            if(lightFaultStatus)
                                return "#FFAD18"
                            else
                                return "#000000"
                        }
                        transform: rotation
                        antialiasing: true
                    }
                }
                Rectangle {
                    width: 50
                    Layout.fillHeight: true
                    color: "transparent"

                    Image {
                        id: bonnetIcon
                        source: "qrc:/resource/image/resource/image/indicatorLight/bonnet.png"
                        width: 43
                        height: width / sourceSize.width * sourceSize.height
                        anchors.centerIn: parent
                    }
                    ColorOverlay {
                        anchors.fill: bonnetIcon
                        source: bonnetIcon
                        color: {
                            if(bonnetStatus)
                                return "#EE3426"
                            else
                                return "#000000"
                        }
                        transform: rotation
                        antialiasing: true
                    }
                }
            }
        }
    }
}
