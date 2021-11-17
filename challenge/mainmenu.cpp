#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMessageBox>

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_pushButton_clicked()
{
//    metaData newWindow; //Modal approach, opens new window
//    hide(); //Hides main menu window
//    newWindow.setModal(true); //enables modal approach
//    newWindow.exec(); //executes window open
    newWindow = new metaData(this);
    newWindow->show();
}


void MainMenu::on_pushButton_5_clicked()
{
    QApplication::quit();
}


void MainMenu::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

