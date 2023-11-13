#include "dialognhapkhachhang.h"
#include "ui_dialognhapkhachhang.h"
#include <QLineEdit>
#include <QValidator>
#include <QObject>

DialogNhapKhachHang::DialogNhapKhachHang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNhapKhachHang)
{
    ui->setupUi(this);
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("^[0-9]{0,12}$"), ui->lineEditNhapCCCD);
    ui->lineEditNhapCCCD->setValidator(validator);

    QRegularExpressionValidator *validator1 = new QRegularExpressionValidator(QRegularExpression("^[0-9]{0,11}$"), ui->lineEditNhapSDT);
    ui->lineEditNhapSDT->setValidator(validator1);

    QIntValidator *validator2 = new QIntValidator(this);
    ui->lineEditNhapNgay->setValidator(validator2);

    QIntValidator *validator3 = new QIntValidator(this);
    ui->lineEditNhapThang->setValidator(validator3);

    QIntValidator *validator4 = new QIntValidator(this);
    ui->lineEditNhapNam->setValidator(validator4);
}

DialogNhapKhachHang::~DialogNhapKhachHang()
{
    delete ui;
}

QString DialogNhapKhachHang::LayCCCDNhapVao()
{
    return ui->lineEditNhapCCCD->text();
}

QString DialogNhapKhachHang::LayTenNhapVao()
{
    return ui->lineEditNhapTen->text();
}

QString DialogNhapKhachHang::LaySDTNhapVao()
{
    return ui->lineEditNhapSDT->text();
}

QString DialogNhapKhachHang::LayNgayNhapVao()
{
    return ui->lineEditNhapNgay->text();
}

QString DialogNhapKhachHang::LayThangNhapVao()
{
    return ui->lineEditNhapThang->text();
}

QString DialogNhapKhachHang::LayNamNhapVao()
{
    return ui->lineEditNhapNam->text();
}
