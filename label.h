#ifndef LABEL_H
#define LABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QString>

class Label:public QLabel
{
    Q_OBJECT
public:

     Label(const QString &text,QWidget *parent=nullptr);
};

#endif // LABEL_H
