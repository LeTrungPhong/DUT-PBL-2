#include "ui_dialogdangnhap.h"
#include "dialogdangnhap.h"

DialogDangNhap::DialogDangNhap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDangNhap)
{
    ui->setupUi(this);
}

DialogDangNhap::~DialogDangNhap()
{
    delete ui;
}

QString DialogDangNhap::LayTaiKhoanNhapVao()
{
    return ui->lineEditTaiKhoan->text();
}

QString DialogDangNhap::LayMatKhauNhapVao()
{
    return ui->lineEditMatKhau->text();
}

void DialogDangNhap::on_XacNhanDangNhap_accepted()
{
    return accept();
}

void DialogDangNhap::on_XacNhanDangNhap_rejected()
{
    return reject();
}

