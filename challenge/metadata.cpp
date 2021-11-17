#include "metadata.h"
#include "ui_metadata.h"
#include "mainmenu.h"

metaData::metaData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::metaData)
{
    ui->setupUi(this);
}

metaData::~metaData()
{
    delete ui;
}

void metaData::on_pushButton_clicked()
{
    QDialog::close();
}

