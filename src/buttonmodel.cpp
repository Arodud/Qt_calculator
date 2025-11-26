#include "buttonmodel.h"

ButtonModel::ButtonModel(QObject *parent)
    : QAbstractListModel(parent)
{

    m_buttons = {
        {"C", "#ff9500", "function"},
        {"±", "#a6a6a6", "function"},
        {"←", "#a6a6a6", "function"},
        {"÷", "#ff9500", "operator"},

        {"7", "#232323", "number"},
        {"8", "#232323", "number"},
        {"9", "#232323", "number"},
        {"×", "#ff9500", "operator"},

        {"4", "#232323", "number"},
        {"5", "#232323", "number"},
        {"6", "#232323", "number"},
        {"−", "#ff9500", "operator"},

        {"1", "#232323", "number"},
        {"2", "#232323", "number"},
        {"3", "#232323", "number"},
        {"+", "#ff9500", "operator"},

        {"0", "#232323", "number"},
        {".", "#232323", "number"},
        {"=", "#ff9500", "operator"}
    };
}

int ButtonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_buttons.size();
}

QVariant ButtonModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_buttons.size())
        return QVariant();

    const ButtonData &button = m_buttons.at(index.row());

    switch (role) {
    case TextRole:
        return button.text;
    case ColorRole:
        return button.color;
    case TypeRole:
        return button.type;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> ButtonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TextRole] = "buttonText";
    roles[ColorRole] = "buttonColor";
    roles[TypeRole] = "buttonType";
    return roles;
}
