import QtQuick
import QtQuick.Layouts
import QtQuick.Window

Window {
    width: 320
    height: 480
    visible: true  // ← ВАЖНО: установите visible: true
    title: "Calculator"
    color: "#121212"

    // История вычислений
    Text {
        id: historyText
        text: calculator.history
        color: "#888"
        font.pixelSize: 16
        anchors {
            top: parent.top
            right: parent.right
            margins: 10
        }
    }

    // Основной дисплей
    Text {
        id: displayText
        text: calculator.display
        color: "white"
        font.pixelSize: 32
        font.bold: true
        horizontalAlignment: Text.AlignRight
        anchors {
            right: parent.right
            bottom: buttonGrid.top
            margins: 20
        }
    }

    GridLayout {
        id: buttonGrid
        columns: 4
        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
            margins: 10
        }
        height: 350

        // Кнопки с привязкой к C++ методам
        CalculatorButton {
            text: "C"; buttonColor: "#ff9500";
            onClicked: calculator.clearAll()
        }
        CalculatorButton {
            text: "±"; buttonColor: "#a6a6a6";
            onClicked: calculator.toggleSign()
        }
        CalculatorButton {
            text: "←"; buttonColor: "#a6a6a6";
            onClicked: calculator.backspace()
        }
        CalculatorButton {
            text: "÷"; buttonColor: "#ff9500";
            onClicked: calculator.appendOperator("÷")
        }

        CalculatorButton { text: "7"; onClicked: calculator.appendNumber("7") }
        CalculatorButton { text: "8"; onClicked: calculator.appendNumber("8") }
        CalculatorButton { text: "9"; onClicked: calculator.appendNumber("9") }
        CalculatorButton {
            text: "×"; buttonColor: "#ff9500";
            onClicked: calculator.appendOperator("×")
        }

        CalculatorButton { text: "4"; onClicked: calculator.appendNumber("4") }
        CalculatorButton { text: "5"; onClicked: calculator.appendNumber("5") }
        CalculatorButton { text: "6"; onClicked: calculator.appendNumber("6") }
        CalculatorButton {
            text: "−"; buttonColor: "#ff9500";
            onClicked: calculator.appendOperator("−")
        }

        CalculatorButton { text: "1"; onClicked: calculator.appendNumber("1") }
        CalculatorButton { text: "2"; onClicked: calculator.appendNumber("2") }
        CalculatorButton { text: "3"; onClicked: calculator.appendNumber("3") }
        CalculatorButton {
            text: "+"; buttonColor: "#ff9500";
            onClicked: calculator.appendOperator("+")
        }

        CalculatorButton {
            text: "0";
            Layout.columnSpan: 2;
            Layout.fillWidth: true;
            onClicked: calculator.appendNumber("0")
        }
        CalculatorButton {
            text: ".";
            onClicked: calculator.appendDecimal()
        }
        CalculatorButton {
            text: "="; buttonColor: "#ff9500";
            onClicked: calculator.calculate()
        }
    }
}
