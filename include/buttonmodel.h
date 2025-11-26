#ifndef BUTTONMODEL_H
#define BUTTONMODEL_H

#include <QAbstractListModel>
#include <QString>

struct ButtonData {
    QString text;
    QString color;
    QString type; // "number", "operator", "function"
};

class ButtonModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        TextRole = Qt::UserRole + 1,
        ColorRole,
        TypeRole
    };

    explicit ButtonModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<ButtonData> m_buttons;
};


#endif // BUTTONMODEL_H
