#ifndef BUTTONTOOL_H
#define BUTTONTOOL_H

#include <QObject>
#include <QWidget>
#include <QToolButton>
#include <QIcon>
#include <QString>

class ButtonTool:public QToolButton
{
    Q_OBJECT
public:
    ButtonTool(const QString &iconPath,const QString &tip=QString());
};

#endif // BUTTONTOOL_H
