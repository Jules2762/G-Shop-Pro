#include "input.h"
#include <QWidget>
#include <QLineEdit>
#include <QAction>
Input::Input(InputType input_type,QWidget *parent):QLineEdit(parent),type(input_type) {


    this->setStyleSheet( "QLineEdit {"
                        "  background-color: #FFFFFF;"
                        "  color: #0F172A;"
                        "  border: 1px solid #CBD5E1;"
                        "  border-radius: 6px;"
                        "  padding: 8px 10px;"
                        "  font-size: 12px;"
                        "  font-family: 'Inter';"
                        "}"
                        "QLineEdit:focus {"
                        "  border: 1px solid #2563EB;"
                        "}");
    if (type == InputType::SEARCH) {
        this->setClearButtonEnabled(true);
        setIcon();// Ajoute une petite croix pour effacer
    }
};
void Input::setIcon(const QString &iconPath){
    if(this->type==InputType::INPUT){
         this->addAction(QIcon(iconPath),QLineEdit::LeadingPosition);
    } else {
        this->iconAction=new QAction(QIcon(":/icons/assets/search.png"),"",this);
         this->addAction(this->iconAction,QLineEdit::TrailingPosition);
    }
}

