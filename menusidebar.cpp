#include "menusidebar.h"
#include <QMenu>
#include <QWidget>
MenuSidebar::MenuSidebar(QWidget *parent):QMenu(parent) {
    this->setStyleSheet(
        "QMenu {"
        "  background-color: #FFFFFF;"
        "  border: 1px solid #E2E8F0;"
        "  border-radius: 4px;"
        "  padding: 5px;"
        "}"

        "QMenu::item {"

        "  color: #0F172A;"

        "}"

        "QMenu::item:selected {"

        "  color: #0F172A;"
        "}"


        );



}
