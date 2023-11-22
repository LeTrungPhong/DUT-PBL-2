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
    this->tt.CapNhatDuLieuKhachHang();
    this->tt.CapNhatTrangThaiPhong();
    QIntValidator *validator1 = new QIntValidator(this);
    ui->lineEditMin->setValidator(validator1);
    QIntValidator *validator2 = new QIntValidator(this);
    ui->lineEditMax->setValidator(validator2);

    QIntValidator *validatorGio = new QIntValidator(this);
    ui->lineEditGio->setValidator(validatorGio);
    QIntValidator *validatorNgay = new QIntValidator(this);
    ui->lineEditNgay->setValidator(validatorNgay);
    QIntValidator *validatorThang = new QIntValidator(this);
    ui->lineEditThang->setValidator(validatorThang);
    QIntValidator *validatorNam = new QIntValidator(this);
    ui->lineEditNam->setValidator(validatorNam);

    QIntValidator *validatorGio2 = new QIntValidator(this);
    ui->lineEditGio2->setValidator(validatorGio2);
    QIntValidator *validatorNgay2 = new QIntValidator(this);
    ui->lineEditNgay2->setValidator(validatorNgay2);
    QIntValidator *validatorThang2 = new QIntValidator(this);
    ui->lineEditThang2->setValidator(validatorThang2);
    QIntValidator *validatorNam2 = new QIntValidator(this);
    ui->lineEditNam2->setValidator(validatorNam2);

    ui->stackedWidget->setCurrentIndex(1);
    this->thutu = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    this->tt.CapNhatDuLieuKhachHang();
    this->tt.CapNhatTrangThaiPhong();
    if(ui->stackedWidget3->currentIndex() == 0)
    {
        MainWindow::LuuPhongvaoFile();
        MainWindow::LuuKhachHangMoiVaoFile();
        MainWindow::LuuKhachHangCuVaoFile();
    }
    if(ui->stackedWidget3->currentIndex() == 1)
    {

    }
    if(QMessageBox::question(this,"Cau hoi","Xac nhan thoat chuong trinh",QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Cancel)
    {
        event->ignore();
    }
}

void MainWindow::NhapThongTin(const QuanLy &q, const QuanLyKhachHang &k, const QuanLyPhong &p)
{
    this->ql = q;
    this->ql.NhapThongTinChucNang(k,p);
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
        ui->stackedWidget2->setCurrentIndex(0);
        ui->stackedWidget3->setCurrentIndex(0);
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
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget2->setCurrentIndex(4);
        ui->stackedWidget3->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::warning(this,"Thông báo","Tài khoản hoặc Mật khẩu sai");
    }
}

void MainWindow::on_buttonTimkiem_clicked()
{
    this->tt.CapNhatDuLieuKhachHang();
    this->tt.CapNhatTrangThaiPhong();
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
    this->tt.CapNhatTrangThaiPhong();
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
        QString gt = QLocale().toString(p->LayGiaTien());
        MainWindow::HienThiPhongRaManHinh2(QString::fromStdString(TenPhong),LoaiPhong,gdqt,gdoiqt,ktr,gt);
    }
}

void MainWindow::on_buttonXacNhanDatPhong_clicked()
{
    this->tt.CapNhatDuLieuKhachHang();
    this->tt.CapNhatTrangThaiPhong();
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

        int giodi = ui->lineEditGio->text().toInt();
        int ngaydi = ui->lineEditNgay->text().toInt();
        int thangdi = ui->lineEditThang->text().toInt();
        int namdi = ui->lineEditNam->text().toInt();

        int gioden = ui->lineEditGio2->text().toInt();
        int ngayden = ui->lineEditNgay2->text().toInt();
        int thangden = ui->lineEditThang2->text().toInt();
        int namden = ui->lineEditNam2->text().remove(',').toInt();

        time_t now = time(0);
        tm* currentDate = localtime(&now);
        int currentYear = currentDate->tm_year + 1900;
        int currentMonth = currentDate->tm_mon + 1;
        int currentDay = currentDate->tm_mday;
        int currentHour = currentDate->tm_hour;

        KhachHang temp;

        bool check = false;
        if(namden < currentYear) check = true;
        if(namden == currentYear && thangden < currentMonth) check = true;
        if(namden == currentYear && thangden == currentMonth && ngayden < currentDay) check = true;
        if(namden == currentYear && thangden == currentMonth && ngayden == currentDay && gioden < currentHour) check = true;
        if(gioden > 23 || gioden < 0) check = true;
        if(thangden > 12 || thangden < 1) check = true;
        if((thangden == 1 || thangden == 3 || thangden == 5 || thangden == 7 || thangden == 8 || thangden == 10 || thangden == 12) && (ngayden > 31 || ngayden < 1)) check = true;
        if((thangden == 4 || thangden == 6 || thangden == 9 || thangden == 11) && (ngayden > 30 || ngayden < 1)) check = true;
        if((thangden == 2) && ((((namden % 4) == 0 ) && (ngayden > 29 || ngayden < 1))||(((namden % 4) != 0) && (ngayden > 28 || ngayden < 1)))) check = true;

        if(check)
        {
            QMessageBox::warning(this,"Thong bao","Thoi gian den khong hop le");
            return;
        }

        check = false;

        if(namdi < namden) check = true;
        if(namdi == namden && thangdi < thangden) check = true;
        if(namdi == namden && thangdi == thangden && ngaydi < ngayden) check = true;
        if(namdi == namden && thangdi == thangden && ngaydi == ngayden && giodi < gioden) check = true;
        if(giodi > 23 || giodi < 0) check = true;
        if(thangdi > 12 || thangdi < 1) check = true;
        if((thangdi == 1 || thangdi == 3 || thangdi == 5 || thangdi == 7 || thangdi == 8 || thangdi == 10 || thangdi == 12) && (ngaydi > 31 || ngaydi < 1)) check = true;
        if((thangdi == 4 || thangdi == 6 || thangdi == 9 || thangdi == 11) && (ngaydi > 30 || ngaydi < 1)) check = true;
        if((thangdi == 2) && ((((namdi % 4) == 0 ) && (ngaydi > 29 || ngaydi < 1))||(((namdi % 4) != 0) && (ngaydi > 28 || ngaydi < 1)))) check = true;

        if(check)
        {
            QMessageBox::information(this,"Thong bao","Thoi gian di khong hop le");
            return;
        }

        temp.NhapNgayDatPhong(ngayden,thangden,namden,gioden);
        temp.NhapNgayTraPhong(ngaydi,thangdi,namdi,giodi);

        if(!(this->tt.KiemTraPhongDuocDatChua(str,gioden,ngayden,thangden,namden,giodi,ngaydi,thangdi,namdi)))
        {
            QMessageBox::warning(this,"Thong bao","Khoang thoi gian da co nguoi dat");
            return;
        }

        long long giatien;
        int lp = tt.XacDinhLoaiPhong(str);
        if(lp == 0) return;
        if(lp == 1) giatien = tt.LayThongTinPhongCoBan(str).LayGiaTien();
        if(lp == 2) giatien = tt.LayThongTinPhongThuong(str).LayGiaTien();
        if(lp == 3) giatien = tt.LayThongTinPhongThuongGia(str).LayGiaTien();
        temp.TinhTienPhong(giatien);

        if(!(QMessageBox::question(this,"Thong bao", "Tong tien phong: " + QLocale().toString(temp.LayTienPhong()),QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Ok))
        {
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

//                    if(!(this->tt.KiemTraQuaGioKhachHang(str)))
//                    {
//                        QMessageBox::information(this,"Thong bao","Thong bao khach hang phong" + QString::fromStdString(str) + "thanh toan tien phong");
//                    }

                    if(this->tt.KiemTraKhachHangDatPhong(CCCDNhap))
                    {
                        QMessageBox::information(this,"Thong bao","Khach hang da ton tai");
                        return;
                    }

                    temp.NhapThongTin(CCCDNhap,TenNhap,SDTNhap,NgayNhap,ThangNhap,NamNhap);
                    if(!temp.KiemTraThongTinNhapVao())
                    {
                        QMessageBox::warning(this,"Thong bao","Thong tin nhap vao khong hop le");
                        return;
                    }

                    temp.NhapPhongKhachHangDat(str);
                    tt.KhachHangDatPhong(temp);
//                    tt.ChuyenTrangThaiPhong(str);
//                    ui->labelTinhTrang2->setText("Khong trong");
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
    this->tt.CapNhatDuLieuKhachHang();
    this->tt.CapNhatTrangThaiPhong();
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

    Date ndi = kh->LayNgayTraPhong();

    bool check = true;

    if(ndi.Nam < currentYear) check = false;
    if(ndi.Nam == currentYear && ndi.Thang < currentMonth) check = false;
    if(ndi.Nam == currentYear && ndi.Thang == currentMonth && ndi.Ngay < currentDay) check = false;
    if(ndi.Nam == currentYear && ndi.Thang == currentMonth && ndi.Ngay == currentDay && ndi.Gio < currentHour) check = false;

    if(!check)
    {
        kh->NhapNgayTraPhong(currentDay,currentMonth,currentYear,currentHour);
    }
    ndi = kh->LayNgayTraPhong();

    ui->labelThoiGianTra->setText(QLocale().toString(ndi.Ngay) + "/" + QLocale().toString(ndi.Thang) + "/" + QLocale().toString(ndi.Nam) + "\n" + QLocale().toString(ndi.Gio));
    kh->TinhTienPhong(giatien);
    QString tien = QLocale().toString(kh->LayTienPhong());
    ui->labelTongTien->setText(tien);
}

void MainWindow::on_buttonThanhToan_clicked()
{
    this->tt.CapNhatDuLieuKhachHang();
    this->tt.CapNhatTrangThaiPhong();
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
    this->tt.CapNhatDuLieuKhachHang();
    this->tt.CapNhatTrangThaiPhong();
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

void MainWindow::on_buttonRealTime_clicked()
{
    time_t now = time(0);
    tm* currentDate = localtime(&now);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;
    int currentHour = currentDate->tm_hour;

    ui->lineEditGio2->setText(QLocale().toString(currentHour));
    ui->lineEditNgay2->setText(QLocale().toString(currentDay));
    ui->lineEditThang2->setText(QLocale().toString(currentMonth));
    ui->lineEditNam2->setText(QLocale().toString(currentYear));
}

// Quan Ly

void MainWindow::HienThiDanhSach()
{
    int dem = this->thutu;
    ui->labelTKH1->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD1->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT1->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND1->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT1->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS1->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP1->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV11->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV21->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV31->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV41->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT1->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH2->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD2->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT2->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND2->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT2->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS2->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP2->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV12->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV22->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV32->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV42->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT2->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH3->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD3->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT3->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND3->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT3->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS3->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP3->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV13->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV23->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV33->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV43->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT3->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH4->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD4->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT4->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND4->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT4->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS4->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP4->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV14->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV24->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV34->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV44->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT4->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH5->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD5->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT5->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND5->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT5->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS5->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP5->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV15->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV25->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV35->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV45->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT5->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH6->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD6->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT6->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND6->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT6->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS6->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP6->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV16->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV26->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV36->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV46->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT6->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH7->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD7->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT7->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND7->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT7->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS7->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP7->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV17->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV27->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV37->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV47->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT7->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH8->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD8->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT8->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND8->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT8->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS8->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP8->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV18->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV28->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV38->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV48->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT8->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH9->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD9->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT9->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND9->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT9->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS9->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP9->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV19->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV29->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV39->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV49->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT9->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
    dem++;
    ui->labelTKH10->setText(QString::fromStdString((this->k)[dem].LayTen()));
    ui->labelCCCD10->setText(QString::fromStdString((this->k)[dem].LayCCCD()));
    ui->labelSDT10->setText(QString::fromStdString((this->k)[dem].LaySDT()));
    ui->labelND10->setText(QString::fromStdString((this->k)[dem].LayNgayDen()));
    ui->labelNT10->setText(QString::fromStdString((this->k)[dem].LayNgayDi()));
    ui->labelNS10->setText(QString::fromStdString((this->k)[dem].LayBirth()));
    ui->labelTP10->setText(QString::fromStdString((this->k)[dem].LayTenPhong()));
    ui->labelDV110->setText(QLocale().toString((this->k)[dem].LayDichVu()[0]));
    ui->labelDV210->setText(QLocale().toString((this->k)[dem].LayDichVu()[1]));
    ui->labelDV310->setText(QLocale().toString((this->k)[dem].LayDichVu()[2]));
    ui->labelDV410->setText(QLocale().toString((this->k)[dem].LayDichVu()[3]));
    ui->labelTT10->setText(QLocale().toString((this->k)[dem].LayTienPhong()));
}

void MainWindow::on_buttonDSKHM_clicked()
{
    this->k.clear();
    this->k = this->ql.LayDanhSachKhachHangMoi();
    this->thutu = 0;

    int x = this->k.size();
    while((x - 10) >= 0)
    {
        x = x - 10;
    }
    x = 10 - x;
    for(int i = 0; i < x; i++)
    {
        KhachHang temp;
        this->k.push_back(temp);
    }
    MainWindow::HienThiDanhSach();
}

void MainWindow::on_buttonDSKHC_clicked()
{
    this->k.clear();
    this->k = this->ql.LayDanhSachKhachHangCu();
    this->thutu = 0;

    int x = this->k.size();
    while((x - 10) >= 0)
    {
        x = x - 10;
    }
    x = 10 - x;
    for(int i = 0; i < x; i++)
    {
        KhachHang temp;
        this->k.push_back(temp);
    }
    MainWindow::HienThiDanhSach();
}

void MainWindow::on_buttonContinue2_clicked()
{
    if((this->thutu + 10) >= this->k.size())
    {
        return;
    }
    else
    {
        this->thutu = this->thutu + 10;
        MainWindow::HienThiDanhSach();
    }
}

void MainWindow::on_buttonBack2_clicked()
{
    if(this->thutu == 0)
    {
        return;
    }
    else
    {
        this->thutu = this->thutu - 10;
        MainWindow::HienThiDanhSach();
    }
}

void MainWindow::on_buttonQLKH_clicked()
{
    ui->stackedWidget2->setCurrentIndex(4);
}

void MainWindow::on_buttonQLP_clicked()
{
    ui->stackedWidget2->setCurrentIndex(5);
}

void MainWindow::on_buttonTimKiem_clicked()
{
    string CCCD = ui->lineEditNhapCCCD->text().toStdString();
    string TenPhong = ui->lineEditNhapTenPhong->text().toStdString();
    string TenKhachHang = ui->lineEditNhapTenKhachHang->text().toStdString();
    this->k.clear();
    if(ui->radioButtonDSM->isChecked())
    {
        this->k = this->ql.LayDSKHTheoTTDSM(CCCD,TenPhong,TenKhachHang);
    }
    if(ui->radioButtonDSC->isChecked())
    {
        this->k = this->ql.LayDSKHTheoTTDSC(CCCD,TenPhong,TenKhachHang);
    }
    this->thutu = 0;
    int x = this->k.size();
    while((x - 10) >= 0)
    {
        x = x - 10;
    }
    x = 10 - x;
    for(int i = 0; i < x; i++)
    {
        KhachHang temp;
        this->k.push_back(temp);
    }
    MainWindow::HienThiDanhSach();
}



