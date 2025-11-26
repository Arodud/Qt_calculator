#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QString>

class Calculator : public QObject {
    Q_OBJECT;

    Q_PROPERTY(QString display READ display WRITE setDisplay NOTIFY displayChanged)
    Q_PROPERTY(QString history READ history NOTIFY historyChanged)

public:
    Calculator(QObject *parent = nullptr);

    QString display() const;
    QString history() const;

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
