#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QString>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIntValidator *validator1 = new QIntValidator(this);
    ui->lineEditMin->setValidator(validator1);
    QIntValidator *validator2 = new QIntValidator(this);
    ui->lineEditMax->setValidator(validator2);

    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget2->setCurrentIndex(0);
    this->thutu = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    MainWindow::LuuPhongvaoFile();
    MainWindow::LuuKhachHangMoiVaoFile();
    MainWindow::LuuKhachHangCuVaoFile();
    if(QMessageBox::question(this,"Cau hoi","Xac nhan thoat chuong trinh",QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel)
    {
        event->ignore();
    }
}

void MainWindow::NhapThongTin(const QuanLy &q, const QuanLyKhachHang &k, const QuanLyPhong &p)
{
    this->ql = q;
    this->tt.NhapThongTinChucNang(k,p);
}

void MainWindow::on_TiepTanButton_clicked()
{
    DialogDangNhap dialog(this);
    dialog.setModal(true);
    int result = dialog.exec();

    QString strtk = "";
    QString strmk = "";
    if(result == DialogDangNhap::Accepted)
    {
        strtk = dialog.LayTaiKhoanNhapVao();
        strmk = dialog.LayMatKhauNhapVao();
    }
    string tk = strtk.toStdString();
    string mk = strmk.toStdString();

    bool check = ql.KiemTraTiepTanDangNhap(tk,mk);

    if(check)
    {
        QMessageBox::information(this,"Thông báo","Đăng nhập thành công");
//        this->tt = ql.LayThongTinTiepTan(tk,mk);

//        QString strc = QString::fromStdString(tt.LayCCCD());
//        QString strb = QString::fromStdString(tt.LayBirth());

        ////////////////////////////////
//        this->tt.NhapThongTinChucNang(k,p);
        ui->stackedWidget->setCurrentIndex(0);
        MainWindow::on_buttonTimkiem_clicked();
    }
    else
    {
        QMessageBox::warning(this,"Thông báo","Tài khoản hoặc Mật khẩu sai");
    }
}

void MainWindow::on_QuanLyButton_clicked()
{
    DialogDangNhap dialog(this);
    dialog.setModal(true);
    int result = dialog.exec();

    QString strtk = "";
    QString strmk = "";
    if(result == DialogDangNhap::Accepted)
    {
        strtk = dialog.LayTaiKhoanNhapVao();
        strmk = dialog.LayMatKhauNhapVao();
    }
    string tk = strtk.toStdString();
    string mk = strmk.toStdString();

    bool check = ql.KiemTraQuanLyDangNhap(tk,mk);

    if(check)
    {
        QMessageBox::information(this,"Thông báo","Đăng nhập thành công");
    }
    else
    {
        QMessageBox::warning(this,"Thông báo","Tài khoản hoặc Mật khẩu sai");
    }
}

void MainWindow::on_buttonTimkiem_clicked()
{
    string str = ui->lineEditTimKiem->text().toStdString();
    if(tt.KiemTraTenPhong(str))
    {
        ui->buttonPhong1->setText(ui->lineEditTimKiem->text());
        ui->buttonPhong2->setText("");
        ui->buttonPhong3->setText("");
        ui->buttonPhong4->setText("");
        ui->buttonPhong5->setText("");
        ui->buttonPhong6->setText("");
        ui->buttonPhong7->setText("");
        ui->buttonPhong8->setText("");
        ui->buttonPhong9->setText("");
        ui->buttonPhong10->setText("");
        ui->buttonPhong11->setText("");
        ui->buttonPhong12->setText("");
        return;
    }

    if(str != "")
    {
        QMessageBox::warning(this,"Thông báo","Tên Phòng Không Tồn Tại");
    }

    int a = ui->comboBoxGDon->currentIndex();
    int b = ui->comboBoxGDoi->currentIndex();

    int d = ui->comboBoxLP->currentIndex();
    int e = ui->comboBoxTT->currentIndex();

    long long f = 0;
    long long g = 1000000;

    if(!(ui->lineEditMin->text() == ""))
    {
        f = ui->lineEditMin->text().toInt();
    }

    if(!(ui->lineEditMax->text() == ""))
    {
        g = ui->lineEditMax->text().toInt();
    }
    this->v.clear();
    vector<string> temp = MainWindow::LayTenCacPhong(a,b,d,e,f,g);

    this->thutu = 0;
    for(int i = 0; i < temp.size(); i++)
    {
        this->v.push_back(QString::fromStdString(temp[i]));
    }
    int k = temp.size();
    while((k - 12) >= 0)
    {
        k = k - 12;
    }
    k = 12 - k;
    for(int i = 0; i < k; i++)
    {
        this->v.push_back("");
    }
    MainWindow::XuatPhong();
}

void MainWindow::XuatPhong()
{
    int dem = this->thutu;
    ui->buttonPhong1->setText(this->v[dem]); dem++;
    ui->buttonPhong2->setText(this->v[dem]); dem++;
    ui->buttonPhong3->setText(this->v[dem]); dem++;
    ui->buttonPhong4->setText(this->v[dem]); dem++;
    ui->buttonPhong5->setText(this->v[dem]); dem++;
    ui->buttonPhong6->setText(this->v[dem]); dem++;
    ui->buttonPhong7->setText(this->v[dem]); dem++;
    ui->buttonPhong8->setText(this->v[dem]); dem++;
    ui->buttonPhong9->setText(this->v[dem]); dem++;
    ui->buttonPhong10->setText(this->v[dem]); dem++;
    ui->buttonPhong11->setText(this->v[dem]); dem++;
    ui->buttonPhong12->setText(this->v[dem]);
}

void MainWindow::on_buttonBack_clicked()
{
    if(this->thutu == 0)
    {
        return;
    }
    else
    {
        this->thutu = this->thutu - 12;
        MainWindow::XuatPhong();
    }
}

void MainWindow::on_buttonContinue_clicked()
{
    if((this->thutu + 12) >= v.size())
    {
        return;
    }
    else
    {
        this->thutu = this->thutu + 12;
        MainWindow::XuatPhong();
    }
}

vector<string> MainWindow::LayTenCacPhong(int a, int b, int d, int e, long long f, long long g)
{
    return this->tt.LayTenCacPhong(a,b,d,e,f,g);
}

void MainWindow::HienThiPhongRaManHinh(QString tp, QString lp, QString gdon, QString gdoi, bool ktr, QString gt)
{
    QString TinhTrang;
    if(ktr)
    {
        TinhTrang = "Trong";
    }
    else TinhTrang = "Khong Trong";
    ui->labelTenPhong->setText(tp);
    ui->labelLoaiPhong->setText(lp);
    ui->labelGiuongDon->setText(gdon);
    ui->labelGiuongDoi->setText(gdoi);
    ui->labelTinhTrang->setText(TinhTrang);
    ui->labelTang->setText(tp[1]);
    ui->labelGiaTien->setText(gt);
}

void MainWindow::HienThiThongTinPhong(string str)
{
    int lp = (this->tt).XacDinhLoaiPhong(str);
    if(lp == 0) return;
    if(lp == 1)
    {
        PhongCoBan *p = &(tt.LayThongTinPhongCoBan(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Co Ban";
        int gd = p->LaySoLuongGiuongDon();
        QString gdoiqt = "";
        QString gdqt = QLocale().toString(gd);
        bool ktr = p->KiemTraPhongTrong();
        QString gt = QLocale().toString(p->LayGiaTien());
        MainWindow::HienThiPhongRaManHinh(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
    }
    if(lp == 2)
    {
        PhongThuong *p = &(tt.LayThongTinPhongThuong(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Thuong";
        int gd = p->LaySoLuongGiuongDon();
        int gdoi = p->LaySoLuongGiuongDoi();
        QString gdqt = QLocale().toString(gd);
        QString gdoiqt = QLocale().toString(gdoi);
        bool ktr = p->KiemTraPhongTrong();
        QString gt = QLocale().toString(p->LayGiaTien());
        MainWindow::HienThiPhongRaManHinh(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
    }
    if(lp == 3)
    {
        PhongThuongGia *p = &(tt.LayThongTinPhongThuongGia(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Thuong Gia";
        int gd = p->LaySoLuongGiuongDon();
        int gdoi = p->LaySoLuongGiuongDoi();
        QString gdqt = QLocale().toString(gd);
        QString gdoiqt = QLocale().toString(gdoi);
        bool ktr = p->KiemTraPhongTrong();
        QString gt = QLocale().toString(p->LayGiaTien());
        MainWindow::HienThiPhongRaManHinh(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
    }
}

void MainWindow::on_buttonPhong1_clicked()
{
    QString temp = ui->buttonPhong1->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong2_clicked()
{
    QString temp = ui->buttonPhong2->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong3_clicked()
{
    QString temp = ui->buttonPhong3->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}


void MainWindow::on_buttonPhong4_clicked()
{
    QString temp = ui->buttonPhong4->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong5_clicked()
{
    QString temp = ui->buttonPhong5->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong6_clicked()
{
    QString temp = ui->buttonPhong6->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong7_clicked()
{
    QString temp = ui->buttonPhong7->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong8_clicked()
{
    QString temp = ui->buttonPhong8->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong9_clicked()
{
    QString temp = ui->buttonPhong9->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong10_clicked()
{
    QString temp = ui->buttonPhong10->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong11_clicked()
{
    QString temp = ui->buttonPhong11->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonPhong12_clicked()
{
    QString temp = ui->buttonPhong12->text();
    string str = temp.toStdString();
    MainWindow::HienThiThongTinPhong(str);
}

void MainWindow::on_buttonTimPhong_clicked()
{
    ui->stackedWidget2->setCurrentIndex(0);
}

void MainWindow::on_buttonDatPhong_clicked()
{

    ui->stackedWidget2->setCurrentIndex(1);
}

void MainWindow::HienThiPhongRaManHinh2(QString tp, QString lp, QString gdon, QString gdoi, bool ktr, QString gt)
{
    QString TinhTrang;
    if(ktr)
    {
        TinhTrang = "Trong";
    }
    else TinhTrang = "Khong Trong";
    ui->labelTenPhong2->setText(tp);
    ui->labelLoaiPhong2->setText(lp);
    ui->labelGiuongDon2->setText(gdon);
    ui->labelGiuongDoi2->setText(gdoi);
    ui->labelTinhTrang2->setText(TinhTrang);
    ui->labelTang2->setText(tp[1]);
    ui->labelGiaTien2->setText(gt);
}

void MainWindow::on_buttonChonPhong_clicked()
{
    string str = ui->labelTenPhong->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        return;
    }
    if(QMessageBox::question(this,"","Xac Nhan Chon Phong " + ui->labelTenPhong->text(),QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Ok)
    {
        if(!tt.KiemTraPhongTrong(str))
        {
            QMessageBox::warning(this,"Thong bao","Phong da duoc dat");
            return;
        }
        int lp = tt.XacDinhLoaiPhong(str);
        if(lp == 0) return;
        if(lp == 1)
        {
            ui->stackedWidget2->setCurrentIndex(1);
            PhongCoBan *p = &(tt.LayThongTinPhongCoBan(str));
            string TenPhong = p->LayTenPhong();
            QString LoaiPhong = "Phong Co Ban";
            int gd = p->LaySoLuongGiuongDon();
            QString gdoiqt = "";
            QString gdqt = QLocale().toString(gd);
            bool ktr = p->KiemTraPhongTrong();
            QString gt = QLocale().toString(p->LayGiaTien());
            MainWindow::HienThiPhongRaManHinh2(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
        }
        if(lp == 2)
        {
            ui->stackedWidget2->setCurrentIndex(1);
            PhongThuong *p = &(tt.LayThongTinPhongThuong(str));
            string TenPhong = p->LayTenPhong();
            QString LoaiPhong = "Phong Thuong";
            int gd = p->LaySoLuongGiuongDon();
            int gdoi = p->LaySoLuongGiuongDoi();
            QString gdqt = QLocale().toString(gd);
            QString gdoiqt = QLocale().toString(gdoi);
            bool ktr = p->KiemTraPhongTrong();
            QString gt = QLocale().toString(p->LayGiaTien());
            MainWindow::HienThiPhongRaManHinh2(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
        }
        if(lp == 3)
        {
            ui->stackedWidget2->setCurrentIndex(1);
            PhongThuongGia *p = &(tt.LayThongTinPhongThuongGia(str));
            string TenPhong = p->LayTenPhong();
            QString LoaiPhong = "Phong Thuong Gia";
            int gd = p->LaySoLuongGiuongDon();
            int gdoi = p->LaySoLuongGiuongDoi();
            QString gdqt = QLocale().toString(gd);
            QString gdoiqt = QLocale().toString(gdoi);
            bool ktr = p->KiemTraPhongTrong();
            QString gt = QLocale().toString(p->LayGiaTien());
            MainWindow::HienThiPhongRaManHinh2(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
        }
    }
}

void MainWindow::on_buttonTimKiem2_clicked()
{
    string str = ui->lineEditTimKiem2->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        QMessageBox::warning(this,"Thông báo","Tên Phòng Không Tồn Tại");
    }

    int lp = tt.XacDinhLoaiPhong(str);
    long long giatien = 0;
    if(lp == 0) return;
    if(lp == 1)
    {
        PhongCoBan *p = &(tt.LayThongTinPhongCoBan(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Co Ban";
        int gd = p->LaySoLuongGiuongDon();
        QString gdoiqt = "";
        QString gdqt = QLocale().toString(gd);
        bool ktr = p->KiemTraPhongTrong();
        giatien = p->LayGiaTien();
        QString gt = QLocale().toString(p->LayGiaTien());
        MainWindow::HienThiPhongRaManHinh2(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
    }
    if(lp == 2)
    {
        PhongThuong *p = &(tt.LayThongTinPhongThuong(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Thuong";
        int gd = p->LaySoLuongGiuongDon();
        int gdoi = p->LaySoLuongGiuongDoi();
        QString gdqt = QLocale().toString(gd);
        QString gdoiqt = QLocale().toString(gdoi);
        bool ktr = p->KiemTraPhongTrong();
        giatien = p->LayGiaTien();
        QString gt = QLocale().toString(p->LayGiaTien());
        MainWindow::HienThiPhongRaManHinh2(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
    }
    if(lp == 3)
    {
        PhongThuongGia *p = &(tt.LayThongTinPhongThuongGia(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Thuong Gia";
        int gd = p->LaySoLuongGiuongDon();
        int gdoi = p->LaySoLuongGiuongDoi();
        QString gdqt = QLocale().toString(gd);
        QString gdoiqt = QLocale().toString(gdoi);
        bool ktr = p->KiemTraPhongTrong();
        giatien = p->LayGiaTien();
        QString gt = QLocale().toString(p->LayGiaTien());
        MainWindow::HienThiPhongRaManHinh2(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
    }

    int giodi = ui->lineEditGio->text().toInt();
    int ngaydi = ui->lineEditNgay->text().toInt();
    int thangdi = ui->lineEditThang->text().toInt();
    int namdi = ui->lineEditNam->text().toInt();

    time_t now = time(0);
    tm* currentDate = localtime(&now);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;
    int currentHour = currentDate->tm_hour;

    bool check = false;
    if(namdi < currentYear) check = true;
    if(namdi == currentYear && thangdi < currentMonth) check = true;
    if(namdi == currentYear && thangdi == currentMonth && ngaydi < currentDay) check = true;
    if(namdi == currentYear && thangdi == currentMonth && ngaydi == currentDay && giodi < currentHour) check = true;
    if(giodi > 23 || giodi < 0) check = true;
    if(thangdi > 12 || thangdi < 1) check = true;
    if((thangdi == 1 || thangdi == 3 || thangdi == 5 || thangdi == 7 || thangdi == 8 || thangdi == 10 || thangdi == 12) && (ngaydi > 31 || ngaydi < 1)) check = true;
    if((thangdi == 4 || thangdi == 6 || thangdi == 9 || thangdi == 11) && (ngaydi > 30 || ngaydi < 1)) check = true;
    if((thangdi == 2) && ((((namdi % 4) == 0 ) && (ngaydi > 29 || ngaydi < 1))||(((namdi % 4) != 0) && (ngaydi > 28 || ngaydi < 1)))) check = true;

    if(check)
    {
        QMessageBox::information(this,"Thong bao","Thoi gian khong hop le");
        return;
    }

    KhachHang k;
    k.NhapNgayDatPhong(currentDay,currentMonth,currentYear,currentHour);
    k.NhapNgayTraPhong(ngaydi,thangdi,namdi,giodi);
    k.TinhTienPhong(giatien);
}

void MainWindow::on_buttonXacNhanDatPhong_clicked()
{
    if(QMessageBox::question(this,"","Xac Nhan Dat Phong " + ui->labelTenPhong2->text(),QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Ok)
    {
        string str = ui->labelTenPhong2->text().toStdString();
        if(!tt.KiemTraTenPhong(str))
        {
            QMessageBox::warning(this,"Thông báo","Phòng không xác định");
            return;
        }

        if(!tt.KiemTraPhongTrong(str))
        {
            QMessageBox::warning(this,"Thông báo","Phòng đã được đặt");
            return;
        }

        while(1)
        {
            DialogNhapKhachHang dialog(this);
            dialog.setModal(true);
            int result = dialog.exec();
            if(result == DialogNhapKhachHang::Accepted)
            {
                if(QMessageBox::question(this,"","Xác nhận thông tin khách hàng",QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok)
                {
                    string CCCDNhap = dialog.LayCCCDNhapVao().toStdString();
                    string SDTNhap = dialog.LaySDTNhapVao().toStdString();
                    string TenNhap = dialog.LayTenNhapVao().toStdString();
                    int NgayNhap = dialog.LayNgayNhapVao().toInt();
                    int ThangNhap = dialog.LayThangNhapVao().toInt();
                    int NamNhap = dialog.LayNamNhapVao().toInt();
                    KhachHang temp;
                    temp.NhapThongTin(CCCDNhap,TenNhap,SDTNhap,NgayNhap,ThangNhap,NamNhap);
                    if(!temp.KiemTraThongTinNhapVao())
                    {
                        QMessageBox::warning(this,"Thong bao","Thong tin nhap vao khong hop le");
                        return;
                    }

                    time_t now = time(0);
                    tm* currentDate = localtime(&now);
                    int currentYear = currentDate->tm_year + 1900;
                    int currentMonth = currentDate->tm_mon + 1;
                    int currentDay = currentDate->tm_mday;
                    int currentHour = currentDate->tm_hour;
                    temp.NhapNgayDatPhong(currentDay,currentMonth,currentYear,currentHour);
                    temp.NhapPhongKhachHangDat(str);
                    tt.KhachHangDatPhong(temp);
                    tt.ChuyenTrangThaiPhong(str);
                    ui->labelTinhTrang2->setText("Khong trong");
                    return;
                }
            }
            else
            {
                return;
            }
        }
    }
    else
    {
        return;
    }
}

void MainWindow::on_buttonTraPhong_clicked()
{
    ui->stackedWidget2->setCurrentIndex(3);
}

void MainWindow::HienThiPhongRaManHinh3(QString tp, QString lp, QString gdon, QString gdoi, QString gt)
{
    ui->labelTenPhong3->setText(tp);
    ui->labelLoaiPhong3->setText(lp);
    ui->labelGiuongDon3->setText(gdon);
    ui->labelGiuongDoi3->setText(gdoi);
    ui->labelTang3->setText(tp[1]);
    ui->labelGiaTien3->setText(gt);
}

void MainWindow::on_buttonTimKiem3_clicked()
{
    string str = ui->lineEditTimKiem3->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        QMessageBox::warning(this,"Thong bao","Phong khong ton tai");
        return;
    }
    if(tt.KiemTraPhongTrong(str))
    {
        QMessageBox::warning(this,"Thong bao","Phong dang trong");
        return;
    }
    if(!tt.KiemTraPhongBaoTri(str))
    {
        QMessageBox::information(this,"Thong bao","Phong dang bao tri");
        return;
    }
    long long giatien;
    int lp = tt.XacDinhLoaiPhong(str);
    if(lp == 0) return;
    if(lp == 1)
    {
        PhongCoBan *p = &(tt.LayThongTinPhongCoBan(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Co Ban";
        int gd = p->LaySoLuongGiuongDon();
        QString gdoiqt = "";
        QString gdqt = QLocale().toString(gd);
        giatien = p->LayGiaTien();
        QString gt = QLocale().toString(giatien);
        MainWindow::HienThiPhongRaManHinh3(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,gt);
    }
    if(lp == 2)
    {
        PhongThuong *p = &(tt.LayThongTinPhongThuong(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Thuong";
        int gd = p->LaySoLuongGiuongDon();
        int gdoi = p->LaySoLuongGiuongDoi();
        QString gdqt = QLocale().toString(gd);
        QString gdoiqt = QLocale().toString(gdoi);
        giatien = p->LayGiaTien();
        QString gt = QLocale().toString(giatien);
        MainWindow::HienThiPhongRaManHinh3(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,gt);
    }
    if(lp == 3)
    {
        PhongThuongGia *p = &(tt.LayThongTinPhongThuongGia(str));
        string TenPhong = p->LayTenPhong();
        QString LoaiPhong = "Phong Thuong Gia";
        int gd = p->LaySoLuongGiuongDon();
        int gdoi = p->LaySoLuongGiuongDoi();
        QString gdqt = QLocale().toString(gd);
        QString gdoiqt = QLocale().toString(gdoi);
        giatien = p->LayGiaTien();
        QString gt = QLocale().toString(giatien);
        MainWindow::HienThiPhongRaManHinh3(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,gt);
    }

    KhachHang *kh = &(tt.KhachHangTheoPhong(str));
    Date date = kh->LayNgayDatPhong();
    vector<int> dv = kh->LayDichVu();
    ui->labelCCCD->setText(QString::fromStdString(kh->LayCCCD()));
    ui->labelTenKhachHang->setText(QString::fromStdString(kh->LayTen()));
    ui->labelSDT->setText(QString::fromStdString(kh->LaySDT()));
    ui->labelNgaySinh->setText(QString::fromStdString(kh->LayBirth()));
    ui->labelThoiGianDat->setText(QLocale().toString(date.Ngay) + "/" + QLocale().toString(date.Thang) + "/" + QLocale().toString(date.Nam) + "\n" + QLocale().toString(date.Gio));
    ui->labelDichVu1->setText(QLocale().toString(dv[0]));
    ui->labelDichVu2->setText(QLocale().toString(dv[1]));
    ui->labelDichVu3->setText(QLocale().toString(dv[2]));
    ui->labelDichVu4->setText(QLocale().toString(dv[3]));
    time_t now = time(0);
    tm* currentDate = localtime(&now);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;
    int currentHour = currentDate->tm_hour;
    kh->NhapNgayTraPhong(currentDay,currentMonth,currentYear,currentHour);
    ui->labelThoiGianTra->setText(QLocale().toString(currentDay) + "/" + QLocale().toString(currentMonth) + "/" + QLocale().toString(currentYear) + "\n" + QLocale().toString(currentHour)
                                  );
    kh->TinhTienPhong(giatien);
    QString tien = QLocale().toString(kh->LayTienPhong());
    ui->labelTongTien->setText(tien);
}

void MainWindow::on_buttonThanhToan_clicked()
{
    string str = ui->lineEditTimKiem3->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        QMessageBox::warning(this,"Thong bao","Phong khong ton tai");
        return;
    }
    if(tt.KiemTraPhongTrong(str))
    {
        QMessageBox::warning(this,"Thong bao","Phong dang trong");
        return;
    }

    if (QMessageBox::question(this,"Thong bao","Xac nhan thanh toan",QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok)
    {
        DialogThanhToan dialog(this);
        dialog.setModal(true);
        dialog.exec();
        tt.ChuyenTrangThaiPhong(str);
        tt.NhapKhachHangVaoHashTable((this->tt).KhachHangTheoPhong(str).LayCCCD());
    }
    else
    {
        return;
    }
}

void MainWindow::on_buttonDichVu_clicked()
{
    ui->stackedWidget2->setCurrentIndex(2);
}

void MainWindow::on_buttonTimKiem4_clicked()
{
    string str = ui->lineEditTimKiem4->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong khong ton tai");
        return;
    }
    if(tt.KiemTraPhongTrong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong dang trong");
        return;
    }
    if(!tt.KiemTraPhongBaoTri(str))
    {
        QMessageBox::information(this,"Thong bao","Phong dang bao tri");
        return;
    }
    KhachHang *kh = &(tt.KhachHangTheoPhong(str));
    vector<int> v = kh->LayDichVu();
    ui->labelSoluongDichVu1->setText(QLocale().toString(v[0]));
    ui->labelSoluongDichVu2->setText(QLocale().toString(v[1]));
    ui->labelSoluongDichVu3->setText(QLocale().toString(v[2]));
    ui->labelSoluongDichVu4->setText(QLocale().toString(v[3]));
}

void MainWindow::on_buttonDichVu1_clicked()
{
    string str = ui->lineEditTimKiem4->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong khong ton tai");
        return;
    }
    if(tt.KiemTraPhongTrong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong dang trong");
        return;
    }
    if(QMessageBox::question(this,"Thong bao","Xac nhan khach hang su dung dich vu 1",QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok)
    {
        tt.TangDichVu(0,str);
        QMessageBox::information(this,"Thong bao","Thanh cong");
        int k = ui->labelSoluongDichVu1->text().toInt();
        k++;
        ui->labelSoluongDichVu1->setText(QLocale().toString(k));
    }
}

void MainWindow::on_buttonDichVu2_clicked()
{
    string str = ui->lineEditTimKiem4->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong khong ton tai");
        return;
    }
    if(tt.KiemTraPhongTrong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong dang trong");
        return;
    }
    if(QMessageBox::question(this,"Thong bao","Xac nhan khach hang su dung dich vu 2",QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok)
    {
        tt.TangDichVu(1,str);
        QMessageBox::information(this,"Thong bao","Thanh cong");
        int k = ui->labelSoluongDichVu2->text().toInt();
        k++;
        ui->labelSoluongDichVu2->setText(QLocale().toString(k));
    }
}

void MainWindow::on_buttonDichVu3_clicked()
{
    string str = ui->lineEditTimKiem4->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong khong ton tai");
        return;
    }
    if(tt.KiemTraPhongTrong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong dang trong");
        return;
    }
    if(QMessageBox::question(this,"Thong bao","Xac nhan khach hang su dung dich vu 3",QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok)
    {
        tt.TangDichVu(2,str);
        QMessageBox::information(this,"Thong bao","Thanh cong");
        int k = ui->labelSoluongDichVu3->text().toInt();
        k++;
        ui->labelSoluongDichVu3->setText(QLocale().toString(k));
    }
}

void MainWindow::on_buttonDichVu4_clicked()
{
    string str = ui->lineEditTimKiem4->text().toStdString();
    if(!tt.KiemTraTenPhong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong khong ton tai");
        return;
    }
    if(tt.KiemTraPhongTrong(str))
    {
        QMessageBox::information(this,"Thong bao","Phong dang trong");
        return;
    }
    if(QMessageBox::question(this,"Thong bao","Xac nhan khach hang su dung dich vu 1",QMessageBox::Ok,QMessageBox::Cancel) == QMessageBox::Ok)
    {
        tt.TangDichVu(3,str);
        QMessageBox::information(this,"Thong bao","Thanh cong");
        int k = ui->labelSoluongDichVu4->text().toInt();
        k++;
        ui->labelSoluongDichVu4->setText(QLocale().toString(k));
    }
}

void MainWindow::LuuPhongvaoFile()
{
    (this->tt).LuuPhongVaoFile();
}

void MainWindow::LuuKhachHangCuVaoFile()
{
    (this->tt).LuuKhachHangCuVaoFile();
}

void MainWindow::LuuKhachHangMoiVaoFile()
{
    (this->tt).LuuKhachHangMoiVaoFile();
}

void MainWindow::on_buttonTatCaPhong_clicked()
{
    this->v.clear();
    vector<string> temp = MainWindow::LayTenCacPhong(0,0,0,0,0,1000000);

    this->thutu = 0;
    for(int i = 0; i < temp.size(); ++i)
    {
        this->v.push_back(QString::fromStdString(temp[i]));
    }
    int k = temp.size();
    while((k - 12) >= 0)
    {
        k = k - 12;
    }
    k = 12 - k;
    for(int i = 0; i < k; i++)
    {
        this->v.push_back("");
    }
    MainWindow::XuatPhong();
}

void MainWindow::on_buttonMacDinh_clicked()
{
    ui->lineEditTimKiem->setText("");
    ui->lineEditMin->setText("");
    ui->lineEditMax->setText("");
    ui->comboBoxGDon->setCurrentIndex(0);
    ui->comboBoxGDoi->setCurrentIndex(0);
    ui->comboBoxLP->setCurrentIndex(0);
    ui->comboBoxTT->setCurrentIndex(0);
}
