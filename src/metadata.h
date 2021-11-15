#ifndef METADATA_H
#define METADATA_H

#include <QDialog>

namespace Ui {
class metaData;
}

class metaData : public QDialog
{
    Q_OBJECT

public:
    explicit metaData(QWidget *parent = nullptr);
    ~metaData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::metaData *ui;
};

#endif // METADATA_H
