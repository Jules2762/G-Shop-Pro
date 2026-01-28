#include "button.h"
#include <QPushButton>
#include <QString>
#include <QWidget>
#include <QIcon>
#include <QPixmap>

Button::Button(const QString &text,QWidget *parent):QPushButton(parent) {
    if(!text.isEmpty()){
        this->setText(text);
    }
    this->setType(BtnType::PRIMARY);

}
void Button::setType(const BtnType &type){
    QString bg_color;
    QString bg_color_hovered;
    QString bg_color_pressed;
    QString color;
    QString border;
    switch(type){
    case SECONDARY:
        bg_color="transparent";
        bg_color_hovered="#F1F5F9";
        bg_color_pressed="#E2E8F0";
        color="#0F172A";
        border="1px solid #CBD5E1";
        break;
    case OUTLINED:
        bg_color="#DC2626";
        bg_color_hovered="#B91C1C";
        bg_color_pressed="#991B1B";
        color="#FFFFFF";
        border="none";
        break;
    case LINK:
        bg_color="transparent";
        bg_color_hovered="transparent";
        bg_color_pressed="transparent";
        color="blue";
        border="none";
        break;
    case ICON:
        bg_color="transparent";
        bg_color_hovered="transparent";
        bg_color_pressed="transparent";
        color="white";
        border="none";
        break;

    default:
        bg_color="#2563EB";
        bg_color_hovered="#1D4ED8";
        bg_color_pressed="#1E40AF";
        color="#FFFFFF";
        border="none";
        break;
    }
    this->setStyleSheet(QString("QPushButton {"
                                "  background-color: %1;"
                                "  color: %4;"
                                "  border: %5;"
                                "  border-radius: 6px;"
                                "  padding: 10px 16px;"
                                "  font-size: 11px;"
                                "  font-weight: 500;"
                                "  font-family: 'Inter';"
                                "}"
                                "QPushButton:hover {"
                                "  background-color: %2;"
                                "}"
                                "QPushButton:pressed {"
                                "  background-color: %3;"
                                "}"
                                "QPushButton:disabled{"
                                "background-color: #e5e7eb;" // Gris clair (Désactivé)
                                "   color: #9ca3af;"           // Texte gris
                                "   border: 1px solid #d1d5db;"
                                "}").arg(bg_color,bg_color_hovered,bg_color_pressed,color,border));
    if(type==Button::LINK){
        this->setStyleSheet(
            this->styleSheet()+"QPushButton:hover{"
                                 "text-decoration: underline;"
                                 "}"
            );
    }
}
