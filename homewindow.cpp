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
void HomeWindow::init_sidebar_button(ButtonTool *&btn,const QString &iconPath,const QString &tip,QVBoxLayout *&layout,QWidget *page){
    btn=new ButtonTool(iconPath,tip);
    sidebar_group_button->addButton(btn);
    layout->addWidget(btn);
    layout->setAlignment(Qt::AlignHCenter);
    //sidebar_list.append({btn,page,page_title});
    connect(btn,&QToolButton::clicked,this,[=](){
        this->page_name->setText(tip);
    });
    if(page){
        connect(btn,&QToolButton::clicked,this,[=](){
            ui->stackedWidget->setCurrentWidget(page);
        });
    }
}
void HomeWindow::add_sidebar_top_section(){
    //inititation logo
    QLabel *logo=new QLabel();
    QPixmap logo_pix(":/logo/assets/logo_g.png");
    logo->setPixmap(logo_pix.scaled(30,30,Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QVBoxLayout *top_layout=ui->sidebar_top_layout;
    top_layout->setAlignment(Qt::AlignHCenter);
    top_layout->setSpacing(6);
    top_layout->addWidget(logo);

    //creation de ligne horizontal
    QFrame *line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Plain);
    line->setStyleSheet("color: #2b2b3d; margin: 30px 0px;"); // Marges pour ne pas toucher les bords
    top_layout->addWidget(line);

    //groupe de boutton
    sidebar_group_button = new QButtonGroup(this);
    sidebar_group_button->setExclusive(true);

    //initiation button side bar
    init_sidebar_button(button_home,":/icons/assets/home.png","Tableau de bord",ui->sidebar_top_layout);
    button_home->setChecked(true);
    init_sidebar_button(button_administrator,":/icons/assets/setting (1).png","Administration",ui->sidebar_top_layout);
    init_sidebar_button(button_inventaire_stock,":/icons/assets/app.png","Inventaire et stock",ui->sidebar_top_layout);
    init_sidebar_button(button_commercial,":/icons/assets/cart.png","Commercial",ui->sidebar_top_layout);
    init_sidebar_button(button_finance,":/icons/assets/money-bag.png","Finance",ui->sidebar_top_layout);

}
void HomeWindow::add_sidebar_bottom_section(){
    //initiation button side bar
    ui->sidebar_bottom_layout->setSpacing(6);
    init_sidebar_button(button_setting,":/icons/assets/setting.png","Parametre",ui->sidebar_bottom_layout);
    init_sidebar_button(button_help,":/icons/assets/help-web-button.png","Aide",ui->sidebar_bottom_layout);

}

void HomeWindow::add_header_section_1(){
    QLabel *app_title=new QLabel("G-SHOP Pro");
    app_title->setStyleSheet("QLabel{"
                             "color: #0F172A;"
                             "font-size: 16px;"
                            " font-weight: 600;"
                             "}");
    page_name=new QLabel("Tableau de board");
    page_name->setStyleSheet("QLabel{"
                             "color: #64748B;"
                               "  font-size: 12px;"
                             "margin-top: 2px;"
                             "}");
        page_name->setMinimumWidth(100);
    page_name->setMaximumWidth(100);
    QVBoxLayout *layout=ui->header_section_1_layout;
    layout->addWidget(app_title);
    layout->addWidget(page_name);
}
void HomeWindow::add_header_section_2(){
    this->header_input_search=new Input(Input::InputType::SEARCH);
    this->header_input_search->setPlaceholderText("Rechercher Produit,Categorie, etc ...");
    QHBoxLayout *layout=ui->header_section_2_layout;
    layout->addWidget(header_input_search);

    connect(header_input_search,&QLineEdit::textEdited,this,[=](){

    });
}

void HomeWindow::add_header_section_3(){
    QToolButton *header_user_btn = new QToolButton();
    header_button_notification = new QToolButton();
    header_button_notification->setIcon(QIcon(":/icons/assets/bell.png")); // L'icône du bouton lui-même
    header_button_notification->setIconSize(QSize(20, 20));
    header_button_notification->setAutoRaise(true);
    header_button_notification->setStyleSheet("border: none;");

    // 2. Ajout du badge (ton widget personnalisé)
    // On le crée APRES avoir configuré le bouton pour qu'il ait une taille de référence
    this->notifBadge= new QLabel(header_button_notification);
    this->notifBadge->setFixedSize(8,8);
    this->notifBadge->setStyleSheet("QLabel{"
                                    "background-color:red;"
                                    "border-radius:4px;"
                                    "font-size:10px;"
                                    "}");
    if(!this->notifBadge->text().isEmpty()){
        this->notifBadge->show();
    } else {
        this->notifBadge->hide();
    }
    // On lui donne une taille fixe (le rond du badge + l'espace de l'icône)


    // On le positionne en haut à droite du bouton
    // Note: Si le bouton change de taille, utilise un eventFilter comme vu précédemment
    notifBadge->move(15, 1);
    header_user_btn->setIcon(QIcon(":/icons/assets/user (2).png"));
    header_user_btn->setIconSize(QSize(18, 18));
    header_user_btn->setAutoRaise(true); // Rend le bouton plat/invisible sans survol
    header_user_btn->setStyleSheet("border: none;");

    QHBoxLayout *layout=ui->header_section_3_layout;
     layout->setSpacing(6);
    layout->addWidget(header_button_notification);
    layout->addWidget(header_user_btn);


}


