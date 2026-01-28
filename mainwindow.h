#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "input.h"
#include "label.h"
#include "button.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void add_login_page();
    void add_register_page();

    QLabel* createLogo();
    QLabel* createTitle(const QString &text="G-Shop-Pro");
    QLabel* createCaption(const QString &text);
    QHBoxLayout* createDontHaveAccount();
    QHBoxLayout* createHaveAlreadyAccount();


    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //login_page
     Label *login_label_email,*login_label_password;
    Input *login_input_email,*login_input_password;
     QCheckBox *login_checkbox_remember_me;
     Button *login_btn_submit;

     //register_page
     Label *register_label_email,*register_label_name,*register_label_role,*register_label_password,*register_label_confirmation_password;
     Input *register_input_email,*register_input_name,*register_input_password,*register_input_confirmation_password;
     Button *register_btn_submit;

};
#endif // MAINWINDOW_H
