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

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:

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
    //top_sidebar_section
    ButtonTool *button_home,*button_administrator,*button_inventaire_stock,*button_commercial,*button_finance;

    //bottom_sidebar_section
    ButtonTool *button_help,*button_setting;

    //button group
    QButtonGroup *sidebar_group_button;

    //header
    Input *header_input_search;

};

#endif // HOMEWINDOW_H
