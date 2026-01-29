#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H


#include "button.h"
#include "input.h"

#include <QMainWindow>
#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>
#include <QMenu>
#include <QToolButton>
#include "buttontool.h"
#include <QButtonGroup>
#include <QLabel>
#include <QVBoxLayout>

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    struct struct_sidebar_button{
        ButtonTool *btn;
        QWidget *page;
        QString page_title;
    };
    explicit HomeWindow(QWidget *parent = nullptr);
    //sidebar
    void add_sidebar_top_section();
    void add_sidebar_bottom_section();
    //header
    void add_header_section_1();
    void add_header_section_2();
    void add_header_section_3();



    ~HomeWindow();

private:
    Ui::HomeWindow *ui;
    //notification
    QLabel *notifBadge;

    void init_sidebar_button(ButtonTool *&btn,const QString &iconPath,const QString &tip,QVBoxLayout *&layout,QWidget *page=nullptr);
    //top_sidebar_section
    ButtonTool *button_home,*button_administrator,*button_inventaire_stock,*button_commercial,*button_finance;

    //bottom_sidebar_section
    ButtonTool *button_help,*button_setting;

    //button group
    QButtonGroup *sidebar_group_button;

    //header
    Input *header_input_search;
    QLabel *page_name;

    QToolButton *header_button_notification;

    QList<struct_sidebar_button> sidebar_list;

};

#endif // HOMEWINDOW_H
