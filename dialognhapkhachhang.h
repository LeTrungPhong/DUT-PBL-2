#ifndef DIALOGNHAPKHACHHANG_H
#define DIALOGNHAPKHACHHANG_H

#include <QDialog>

namespace Ui {
class DialogNhapKhachHang;
}

class DialogNhapKhachHang : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNhapKhachHang(QWidget *parent = nullptr);
    ~DialogNhapKhachHang();
    QString LayCCCDNhapVao();
    QString LayTenNhapVao();
    QString LaySDTNhapVao();
    QString LayNgayNhapVao();
    QString LayThangNhapVao();
    QString LayNamNhapVao();
private:
    Ui::DialogNhapKhachHang *ui;
};

#endif // DIALOGNHAPKHACHHANG_H
