#include "calculator.h"

Calculator::Calculator(QObject *parent)
    : QObject(parent)
    , m_display("0")
    , m_value("")
    , m_operatorBuffer("")
    , m_waitingForNewValue(false)
    , m_accumulator(0.0)
{}

QString Calculator::display()
{
    return m_display;
}

QString Calculator::history()
{
    return m_value + " " + m_operatorBuffer;
}

void Calculator::setDisplay(const QString &display)
{
    if (m_display != display) {
        m_display = display;
        emit displayChanged(m_display);
    }
}

void Calculator::appendNumber(const QString &number)
{
    if (m_waitingForNewValue || m_display == "0" || m_display == "Error") {
        setDisplay(number);
        m_waitingForNewValue = false;
    } else {
        setDisplay(m_display + number);
    }
}

void Calculator::appendOperator(const QString &op)
{
    if (m_operatorBuffer.isEmpty()) {
        m_accumulator = m_display.toDouble();
    } else {
        calculate();
    }

    m_operatorBuffer = op;
    m_value = m_display;
    m_waitingForNewValue = true;
    updateHistory();
}

void Calculator::appendDecimal()
{
    if (m_waitingForNewValue || m_display == "Error") {
        setDisplay("0.");
        m_waitingForNewValue = false;
    } else if (!m_display.contains('.')) {
        setDisplay(m_display + ".");
    }
}

void Calculator::clear()
{
    setDisplay("0");
    m_waitingForNewValue = false;
}

void Calculator::clearAll()
{
    setDisplay("0");
    m_value.clear();
    m_operatorBuffer.clear();
    m_waitingForNewValue = false;
    m_accumulator = 0.0;
    emit historyChanged(history());
}

void Calculator::backspace()
{
    if (m_display.length() > 1 && m_display != "Error") {
        setDisplay(m_display.left(m_display.length() - 1));
    } else {
        setDisplay("0");
    }
}

void Calculator::calculate()
{
    if (m_operatorBuffer.isEmpty() || m_value.isEmpty()) {
        return;
    }

    double currentValue = m_display.toDouble();
    double result = 0.0;

    try {
        if (m_operatorBuffer == "+") {
            result = m_accumulator + currentValue;
        } else if (m_operatorBuffer == "−") {
            result = m_accumulator - currentValue;
        } else if (m_operatorBuffer == "×") {
            result = m_accumulator * currentValue;
        } else if (m_operatorBuffer == "÷") {
            if (currentValue == 0) {
                throw std::runtime_error("Division by zero");
            }
            result = m_accumulator / currentValue;
        } else if (m_operatorBuffer == "%") {
            result = m_accumulator * (currentValue / 100.0);
        }


        QString resultStr = QString::number(result, 'g', 10);
        if (resultStr.length() > 15) {
            resultStr = QString::number(result, 'e', 8);
        }

        setDisplay(resultStr);
        m_accumulator = result;
        m_operatorBuffer.clear();
        m_value.clear();
        updateHistory();

    } catch (const std::exception &exceptiom) {
        setDisplay("Error");
        m_operatorBuffer.clear();
        m_value.clear();
        updateHistory();


    }
}

void Calculator::toggleSign()
{
    if (m_display != "0" && m_display != "Error") {
        if (m_display.startsWith('-')) {
            setDisplay(m_display.mid(1));
        } else {
            setDisplay('-' + m_display);
        }
    }
}

void Calculator::updateHistory()
{
    emit historyChanged(history());
}
