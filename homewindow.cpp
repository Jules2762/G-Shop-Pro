#include "homewindow.h"
#include "ui_homewindow.h"
#include "button.h"
#include "buttontool.h"
#include "menusidebar.h"
#include "input.h"

#include <QPushButton>
#include <QList>
#include <QIcon>
#include <QSize>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QToolButton>
#include <QButtonGroup>
#include <QLabel>
#include <QPixmap>
#include <QFrame>

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    this->showMaximized();

    //sidebar
    this->add_sidebar_top_section();
    this->add_sidebar_bottom_section();

    //header
    this->add_header_section_1();
    this->add_header_section_2();
    this->add_header_section_3();

}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::add_sidebar_top_section(){
    //inititation logo
    QLabel *logo=new QLabel();
    QPixmap logo_pix(":/logo/assets/logo_g.png");
    logo->setPixmap(logo_pix.scaled(30,30,Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //creation de ligne horizontal
    QFrame *line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Plain);
    line->setStyleSheet("color: #2b2b3d; margin: 30px 0px;"); // Marges pour ne pas toucher les bords

    //initiation button side bar
    button_home=new ButtonTool(":/icons/assets/home.png","Tableau de bord");
    button_administrator=new ButtonTool(":/icons/assets/setting (1).png","Administration");
    button_inventaire_stock=new ButtonTool(":/icons/assets/app.png","Inventaire et stock");
    button_commercial=new ButtonTool(":/icons/assets/cart.png","Commercial");
    button_finance=new ButtonTool(":/icons/assets/money-bag.png","Finance");

    //groupe de boutton
    sidebar_group_button = new QButtonGroup(this);
    sidebar_group_button->setExclusive(true);
    sidebar_group_button->addButton(button_home);
    sidebar_group_button->addButton(button_administrator);
    sidebar_group_button->addButton(button_commercial);
    sidebar_group_button->addButton(button_finance);
    sidebar_group_button->addButton(button_inventaire_stock);



    //ajout dans le layout
    QVBoxLayout *top_layout=ui->sidebar_top_layout;
    top_layout->addWidget(logo);
    top_layout->addWidget(line);
    top_layout->addWidget(button_home);
    top_layout->addWidget(button_administrator);
    top_layout->addWidget(button_inventaire_stock);
    top_layout->addWidget(button_commercial);
    top_layout->addWidget(button_finance);
}
void HomeWindow::add_sidebar_bottom_section(){
    //initiation button side bar
    button_help=new ButtonTool(":/icons/assets/help-web-button.png","Aide");
    button_setting=new ButtonTool(":/icons/assets/setting.png","Parametre");

    // ajout dans le group button
    sidebar_group_button->addButton(button_setting);
    sidebar_group_button->addButton(button_help);

    //ajout dans le layout
    QVBoxLayout *bottom_layout=ui->sidebar_bottom_layout;
    bottom_layout->addWidget(button_help);
    bottom_layout->addWidget(button_setting);
}

void HomeWindow::add_header_section_1(){
    QLabel *title=new QLabel("G-SHOP Pro");
    QHBoxLayout *layout=ui->header_section_1_layout;
    layout->addWidget(title);
}
void HomeWindow::add_header_section_2(){
    this->header_input_search=new Input(Input::InputType::SEARCH);
    QHBoxLayout *layout=ui->header_section_2_layout;
    layout->addWidget(header_input_search);
}
void HomeWindow::add_header_section_3(){
    QLabel *header_user_icon=new QLabel();
    QPixmap pix_user_icon(":/icons/assets/user (2).png");
    header_user_icon->setPixmap(pix_user_icon.scaled(18,18,Qt::KeepAspectRatio, Qt::SmoothTransformation));


    QHBoxLayout *layout=ui->header_section_3_layout;
    layout->addWidget(header_user_icon);
}


