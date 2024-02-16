import QtQuick 2.15
import QtQuick.Window 2.15
import "qml"

Window {
    width: 800
    height: 480
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    visible: true
    title: qsTr("ECM dashboard")

    FontLoader {
        id: nesLowercaseFont
        source: "qrc:/resource/font/resource/font/NES_Lowercase.ttf"
    }

    Component {
        id: loadingScreenComponent

        LoadingScreen {
            id: loadingScreen
        }
    }

    Component {
        id: bodyComponent

        Body {
            id: body
        }
    }

    Loader {
        id: appLoader
        anchors.fill: parent
        sourceComponent: loadingScreenComponent
    }

    Timer {
        interval: 750
        onTriggered: {
            appLoader.sourceComponent = bodyComponent
        }
        running: true
        repeat: false
    }
}
