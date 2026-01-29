#ifndef INPUT_H
#define INPUT_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QAction>


class Input: public QLineEdit
{
    Q_OBJECT

public:
    enum InputType{
        INPUT,
        SEARCH
    };
    Q_ENUM(InputType)
    Input(InputType input_type=InputType::INPUT,QWidget *parent=nullptr);
    void setIcon(const QString &iconPath="");
    InputType type;
    QAction *iconAction;
};

#endif // INPUT_H
