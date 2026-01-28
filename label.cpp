#include "label.h"
#include <QWidget>
#include <QLabel>
#include <QString>


Label::Label(const QString &text,QWidget *parent):QLabel(parent) {
    this->setText(text);
    this->setStyleSheet("QLabel {"
                        "  color: #0F172A;"
                        "  font-size: 11px;"
                        "  font-weight: 500;"
                        "  font-family: 'Inter';"
                        "}");
}
