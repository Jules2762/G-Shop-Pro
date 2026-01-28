#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QString>

class Button:public QPushButton
{
    Q_OBJECT
public:
    enum BtnType{
        PRIMARY,
        SECONDARY,
        OUTLINED,
        LINK,
        ICON
    };
    Q_ENUM(BtnType)

    explicit Button(const QString &text=QString(),QWidget *parent=nullptr);
    void setType(const BtnType &type=BtnType::PRIMARY);
};

#endif // BUTTON_H
