import QtQuick

Rectangle {
    id: button

    property string text: ""
    property color textColor: "white"
    property color buttonColor: "#232323"
    property color pressedColor: Qt.darker(buttonColor, 1.2)

    signal clicked()

    width: 64
    height: 64
    radius: 8
    color: mouseArea.pressed ? pressedColor : buttonColor

    Text {
        id: buttonText
        text: parent.text
        color: textColor
        font.pixelSize: 24
        font.bold: true
        anchors.centerIn: parent
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: button.clicked()
    }
}
