#ifndef MENUSIDEBAR_H
#define MENUSIDEBAR_H

#include <QObject>
#include <QWidget>
#include <QMenu>

class MenuSidebar : public QMenu
{
    Q_OBJECT
public:
    MenuSidebar(QWidget *parent=nullptr);
};

#endif // MENUSIDEBAR_H
