#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "quanly.h"
#include "dialognhapkhachhang.h"
#include "dialogthanhtoan.h"
#include <string>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
    void NhapThongTin(const QuanLyKhachHang&, const QuanLyPhong&);
    vector<string> LayTenCacPhong(int,int,int,int,long long, long long);

    void HienThiPhongCoBan(string);
    void HienThiPhongThuong(string);
    void HienThiPhongThuongGia(string);
    void HienThiThongTinPhong(string);
    void HienThiPhongRaManHinh(QString,QString,QString,QString,bool,QString);
    void HienThiPhongRaManHinh2(QString,QString,QString,QString,bool, QString);
    void HienThiPhongRaManHinh3(QString,QString,QString,QString, QString);
    void XuatPhong();
    void HienThiDanhSach();

    void LuuPhongvaoFile();
    void LuuKhachHangCuVaoFile();
    void LuuKhachHangMoiVaoFile();

private slots:
    void on_TiepTanButton_clicked();
    void on_QuanLyButton_clicked();
    void on_buttonTimkiem_clicked();
    void on_buttonBack_clicked();
    void on_buttonContinue_clicked();
    void on_buttonPhong1_clicked();
    void on_buttonPhong2_clicked();
    void on_buttonPhong3_clicked();
    void on_buttonPhong4_clicked();
    void on_buttonPhong5_clicked();
    void on_buttonPhong6_clicked();
    void on_buttonPhong7_clicked();
    void on_buttonPhong8_clicked();
    void on_buttonPhong9_clicked();
    void on_buttonPhong10_clicked();
    void on_buttonPhong11_clicked();
    void on_buttonPhong12_clicked();
    void on_buttonTimPhong_clicked();
    void on_buttonDatPhong_clicked();
    void on_buttonChonPhong_clicked();
    void on_buttonTimKiem2_clicked();
    void on_buttonXacNhanDatPhong_clicked();
    void on_buttonTraPhong_clicked();
    void on_buttonTimKiem3_clicked();
    void on_buttonThanhToan_clicked();
    void on_buttonDichVu_clicked();
    void on_buttonTimKiem4_clicked();
    void on_buttonDichVu1_clicked();
    void on_buttonDichVu2_clicked();
    void on_buttonDichVu3_clicked();
    void on_buttonDichVu4_clicked();
    void on_buttonTatCaPhong_clicked();
    void on_buttonMacDinh_clicked();
    void on_buttonRealTime_clicked();
    void on_buttonDSKHM_clicked();
    void on_buttonDSKHC_clicked();
    void on_buttonContinue2_clicked();
    void on_buttonBack2_clicked();
    void on_buttonQLKH_clicked();
    void on_buttonQLP_clicked();
    void on_buttonTimKiem_clicked();
    void on_buttonXacNhan_clicked();
    void on_buttonXacNhan2_clicked();

private:
    Ui::MainWindow *ui;
    QuanLy ql;
    TiepTan tt;
    vector<QString> v;
    vector<KhachHang> k;
    int thutu;
};
#endif // MAINWINDOW_H
