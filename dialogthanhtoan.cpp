#include "dialogthanhtoan.h"
#include "ui_dialogthanhtoan.h"

DialogThanhToan::DialogThanhToan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogThanhToan)
{
    ui->setupUi(this);
    connect(ui->buttonXacNhan,SIGNAL(clicked()),this,SLOT(close()));
}

DialogThanhToan::~DialogThanhToan()
{
    delete ui;
}

