#include "buttontool.h"
#include <QSize>
#include <QIcon>
#include <QToolButton>
#include <QSizePolicy>

ButtonTool::ButtonTool(const QString &iconPath,const QString &tip):QToolButton() {
    this->setIcon(QIcon(iconPath));
    this->setIconSize(QSize(20, 20)); // Taille standard pro

    if(!tip.isEmpty()){
        this->setToolTip(tip);
    }
    // 2. Comportement
    this->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    this->setPopupMode(QToolButton::InstantPopup);
    this->setAutoRaise(true);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setStyleSheet("QToolButton {"
                        " background-color: transparent;"
                        "  color: #a2a3b7;" /* Gris clair */
                        "  border: none;"
                        "}"
                        "QToolButton::menu-indicator { image: none; }");
}
