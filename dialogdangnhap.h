#ifndef DIALOGDANGNHAP_H
#define DIALOGDANGNHAP_H

#include <QDialog>
#include <QString>

namespace Ui {
class DialogDangNhap;
}

class DialogDangNhap : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDangNhap(QWidget *parent = nullptr);
    ~DialogDangNhap();
    QString LayTaiKhoanNhapVao();
    QString LayMatKhauNhapVao();

private slots:


    void on_XacNhanDangNhap_accepted();

    void on_XacNhanDangNhap_rejected();

private:
    Ui::DialogDangNhap *ui;
};

#endif // DIALOGDANGNHAP_H
