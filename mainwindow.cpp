#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "input.h"
#include "label.h"
#include "button.h"
#include "homeWindow.h"
#include <QString>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->add_login_page();
    this->add_register_page();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_login_page(){

    QFormLayout *layout=ui->login_form_layout;
    QHBoxLayout *password_options_layout=new QHBoxLayout();
    Button *login_goto_forgot_password=new Button("Mot de passe oublier?");
    login_goto_forgot_password->setStyleSheet(
        login_goto_forgot_password->styleSheet()+
        "QPushButton{"
        "text-align:right;"
        "}");
    login_goto_forgot_password->setType(Button::BtnType::LINK);
    this->login_checkbox_remember_me=new QCheckBox("Se souvenir de moi");
    password_options_layout->addWidget(this->login_checkbox_remember_me);
    password_options_layout->addWidget(login_goto_forgot_password);
    password_options_layout->setStretch(0,0);
    password_options_layout->setStretch(1,0);

    this->login_label_email=new Label("E-mail");
    this->login_input_email=new Input();
    this->login_input_email->setIcon(":/icons/assets/mail.png");
    this->login_label_password=new Label("Password");
    this->login_input_password=new Input();
    this->login_input_password->setIcon(":/icons/assets/padlock.png");
    this->login_btn_submit=new Button("Se connecter");

    layout->addRow(MainWindow::createLogo());
    layout->addRow(MainWindow::createTitle());
    layout->addRow(MainWindow::createCaption("Accedez à votre espace de travail"));
    layout->addRow(this->login_label_email,this->login_input_email);
    layout->addRow(this->login_label_password,this->login_input_password);
    layout->addRow(password_options_layout);
    layout->addRow(this->login_btn_submit);
    layout->addRow(MainWindow::createDontHaveAccount());
    layout->setRowWrapPolicy(QFormLayout::WrapAllRows);
    ui->label->setAlignment(Qt::AlignCenter);

    connect(login_btn_submit,&QPushButton::clicked,this,[=](){
        HomeWindow *home_window=new HomeWindow();
        home_window->setAttribute(Qt::WA_DeleteOnClose);
        home_window->show();
        connect(home_window,&QObject::destroyed,this,&QWidget::show);
        this->hide();
    });
}
void MainWindow::add_register_page(){
    //label
    this->register_label_name=new Label("Nom");
    this->register_label_email=new Label("E-mail");
    this->register_label_password=new Label("Mot de passe");
    this->register_label_confirmation_password=new Label("Confirmation de mot de passe");
    this->register_label_role=new Label("Rôle");

    //input
    this->register_input_name =new Input();
    this->register_input_name->setIcon(":/icons/assets/user.png");
    this->register_input_email =new Input();
    this->register_input_password =new Input();
    this->register_input_confirmation_password =new Input();

    //checkbox

    //Button submit
    this->register_btn_submit=new Button("S'inscrire");

    //formulaire
    QFormLayout *layout=ui->register_form_layout;
    layout->addRow(MainWindow::createLogo());
    layout->addRow(MainWindow::createTitle("Creer un compte"));
    layout->addRow(MainWindow::createCaption("Veuillez remplir les formulaires"));
    layout->addRow(this->register_label_name,this->register_input_name);
    layout->addRow(this->register_label_email,this->register_input_email);
    layout->addRow(this->register_label_password,this->register_input_password);
    layout->addRow(this->register_label_confirmation_password,this->register_input_confirmation_password);
    layout->addRow(this->register_btn_submit);
    layout->addRow(MainWindow::createHaveAlreadyAccount());
    layout->setRowWrapPolicy(QFormLayout::WrapAllRows);

}

QLabel* MainWindow::createLogo(){
    QLabel *label_icon=new QLabel("");
    QPixmap pix(":/logo/assets/logo_g.png");
    label_icon->setPixmap(pix.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    label_icon->setAlignment(Qt::AlignCenter);
    return label_icon;
}
QLabel* MainWindow::createTitle(const QString &text){
    QLabel *title=new QLabel(text);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("QLabel{"
                         "color:#0F172A;"
                         "font-size:18px;"
                         "font-weight:bold;"
                         "  font-family: 'Inter';"
                         "}");
    return title;
}
QLabel* MainWindow::createCaption(const QString &text){
    QLabel *caption = new QLabel(text);
    caption->setAlignment(Qt::AlignCenter);
    caption->setWordWrap(true);
    caption->setStyleSheet("QLabel{"
                           "color:#475569;"
                           "font-size:13px;"
                           "font-weight:semi-bold;"
                           "}");
    return caption;
}
QHBoxLayout* MainWindow::createDontHaveAccount(){
    QHBoxLayout *hLayout=new QHBoxLayout();
    QLabel *info=new QLabel("Vous n'avez pas de compte ?");
    Button *link=new Button("Creer un compte");
    link->setType(Button::BtnType::LINK);
    link->setStyleSheet(link->styleSheet()+"QPushButton{"
                                             "text-align:left;"
                                             "}");
    hLayout->addWidget(info);
    hLayout->addWidget(link);
    hLayout->addStretch();


    connect(link,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentWidget(ui->register_page);
    });
    return hLayout;

}
QHBoxLayout* MainWindow::createHaveAlreadyAccount(){
    QHBoxLayout *layout=new QHBoxLayout();
    QLabel *info=new QLabel("Vous avez déjà un compte ?");
    Button *link=new Button("Se connecter");
    link->setType(Button::BtnType::LINK);
    link->setStyleSheet(link->styleSheet()+"QPushButton{"
                                             "text-align:left;"
                                             "}");
    layout->addWidget(info);
    layout->addWidget(link);
    connect(link,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentWidget(ui->login_page);
    });
    return layout;

}
