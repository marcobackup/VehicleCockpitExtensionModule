import QtQuick 2.15
import QtGraphicalEffects 1.15

Item {
    y: 115

    property int theme: settingsController.theme
    property int language: settingsController.language
    property int audioStatus: settingsController.audioStatus

    property ListModel homeMenu: ListModel {
        ListElement {
            name: "TEMA"
            value: "home_theme"
        }
        ListElement {
            name: "LINGUA"
            value: "home_language"
        }
        ListElement {
            name: "AUDIO"
            value: "home_audio"
        }
        ListElement {
            name: "INFORMAZIONI"
            value: "home_about"
        }
    }

    property ListModel themeMenu: ListModel {
        ListElement {
            name: "ROSSO SCURO"
            value: "theme_darkred"
        }
        ListElement {
            name: "BLU SCURO"
            value: "theme_darkblue"
        }
        ListElement {
            name: "ORO"
            value: "theme_gold"
        }
        ListElement {
            name: "ARGENTO"
            value: "theme_silver"
        }
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    property ListModel languageMenu: ListModel {
        ListElement {
            name: "ITALIANO"
            value: "language_italian"
        }
        ListElement {
            name: "INGLESE (us)"
            value: "language_englishus"
        }
        ListElement {
            name: "INGLESE (uk)"
            value: "language_englishuk"
        }
        ListElement {
            name: "SPAGNOLO"
            value: "language_spanish"
        }
        ListElement {
            name: "FRANCESE"
            value: "language_french"
        }
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    property ListModel audioMenu: ListModel {
        ListElement {
            name: "DISATTIVO"
            value: "audio_off"
        }
        ListElement {
            name: "ATTIVO"
            value: "audio_on"
        }
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    property ListModel aboutMenu: ListModel {
        ListElement {
            name: "Grafica e firmware\nsviluppato da"
        }
        ListElement {
            name: "marcosgro03@gmail.com"
        }
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    Image {
        source: "qrc:/resource/image/resource/image/settings/systemMenuMask.png"
        anchors.horizontalCenter: parent.horizontalCenter

        ListView {
            id: menuList
            width: parent.width
            height: parent.height / 1.5
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            currentIndex: -1
            clip: true

            model: homeMenu

            onModelChanged: currentIndex = -1

            delegate: Item {
                width: menuList.width
                height: menuList.height / 3

                Rectangle {
                    id: menuItem
                    width: parent.width
                    height: menuList.height / 2
                    color: index === menuList.currentIndex ? "#121111" : "#161517"

                    Text {
                        anchors.centerIn: parent
                        text: model.name
                        color: "#fff"
                        font.family: nesLowercaseFont.name
                        font.pixelSize: 18
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if(!model.value.includes("home")) {
                                menuList.currentIndex = index
                                if(model.value.includes("theme"))
                                    settingsController.theme = index
                                if(model.value.includes("language"))
                                    settingsController.language = index
                                if(model.value.includes("audio"))
                                    settingsController.audioStatus = index
                            } else {
                                if(model.value.includes("theme")) {
                                    menuList.model = themeMenu
                                }
                                if(model.value.includes("language")) {
                                    menuList.model = languageMenu
                                }
                                if(model.value.includes("audio")) {
                                    menuList.model = audioMenu
                                }
                                if(model.value.includes("go")) {
                                    menuList.model = homeMenu
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
