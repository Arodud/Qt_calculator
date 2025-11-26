#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject {
    Q_OBJECT;



public:
    Calculator(QObject *parent = nullptr);

    QString display();
    QString history();

public slots:
    void appendNumber(const QString &number);
    void appendOperator(const QString &op);
    void appendDecimal();
    void clear();
    void clearAll();
    void backspace();
    void calculate();
    void toggleSign();

signals:
    void displayChanged(const QString &display);
    void historyChanged(const QString &history);

private:
    void setDisplay(const QString &display);
    void updateHistory();

    QString m_display;
    QString m_value;
    QString m_operatorBuffer;
    bool m_waitingForNewValue;

    double m_accumulator;
};

#endif // CALCULATOR_H
