#ifndef INPUT_H
#define INPUT_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QString>


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


};

#endif // INPUT_H
