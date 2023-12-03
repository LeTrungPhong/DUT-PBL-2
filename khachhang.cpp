#include "khachhang.h"
#include <ctime>

KhachHang::KhachHang()
{
    this->MaHD = "0";
    this->CCCD = "0";
    this->Ten = "0";
    this->SDT = "0";
    this->Birth.Ngay = 0;
    this->Birth.Thang = 0;
    this->Birth.Nam = 0;
    this->Birth.Gio = 0;
    this->SoLuong = 0;
}

KhachHang::~KhachHang()
{ }

const KhachHang& KhachHang::operator = (const KhachHang& kh)
{
    if(this != &kh)
    {
        this->MaHD = kh.MaHD;
        this->CCCD = kh.CCCD;
        this->Ten = kh.Ten;
        this->SDT = kh.SDT;
        this->Birth = kh.Birth;
        this->SoLuong = kh.SoLuong;
    }
    return *this;
}

//void KhachHang::NhapPhongKhachHangDat(string tenp)
//{
//    this->TenPhong = tenp;
//}

//void KhachHang::NhapThongTinKhac(string tenp, vector<int> dv, int gioden, int ngayden, int thangden, int namden)
//{
//    this->TenPhong = tenp;
//    this->DichVu = dv;
//    this->NgayDen.Gio = gioden;
//    this->NgayDen.Ngay = ngayden;
//    this->NgayDen.Thang = thangden;
//    this->NgayDen.Nam = namden;
//}

//void KhachHang::NhapThongTinKhac(string tenp, vector<int> dv, int gioden, int ngayden, int thangden, int namden, int giodi, int ngaydi, int thangdi, int namdi, int sl, long long gp)
//{
//    this->TenPhong = tenp;
//    this->DichVu = dv;
//    this->NgayDen.Gio = gioden;
//    this->NgayDen.Ngay = ngayden;
//    this->NgayDen.Thang = thangden;
//    this->NgayDen.Nam = namden;
//    this->NgayDi.Gio = giodi;
//    this->NgayDi.Ngay = ngaydi;
//    this->NgayDi.Thang = thangdi;
//    this->NgayDi.Nam = namdi;
//    this->TongTien = gp;
//    this->SoLuong = sl;
//}

//void KhachHang::NhapThongTinKhac(string mahd, string tenp, vector<int> dv, int gioden, int ngayden, int thangden, int namden, int giodi, int ngaydi, int thangdi, int namdi, int sl)
//{
//    this->MaHD = mahd;
//    this->TenPhong = tenp;
//    this->DichVu = dv;
//    this->NgayDen.Gio = gioden;
//    this->NgayDen.Ngay = ngayden;
//    this->NgayDen.Thang = thangden;
//    this->NgayDen.Nam = namden;
//    this->NgayDi.Gio = giodi;
//    this->NgayDi.Ngay = ngaydi;
//    this->NgayDi.Thang = thangdi;
//    this->NgayDi.Nam = namdi;
//    this->SoLuong = sl;
//}

void KhachHang::NhapThongTinKhac(string mahd, int soluong)
{
    this->MaHD = mahd;
    this->SoLuong = soluong;
}

void KhachHang::NhapMaHD(string mahd)
{
    this->MaHD = mahd;
}

//void KhachHang::DatLaiThongTin()
//{
//    this->MaHD = "0";
//    this->TenPhong = "0";
//    this->NgayDen.Gio = 0;
//    this->NgayDen.Ngay = 0;
//    this->NgayDen.Thang = 0;
//    this->NgayDen.Nam = 0;
//    this->NgayDi.Gio = 0;
//    this->NgayDi.Ngay = 0;
//    this->NgayDi.Thang = 0;
//    this->NgayDi.Nam = 0;
//    for(int i = 0; i < 4; ++i)
//    {
//        this->DichVu[i] = 0;
//    }
//    this->TongTien = 0;
//}

//void KhachHang::NhapNgayDatPhong(int ng, int thg, int nam, int h)
//{
//    this->NgayDen.Ngay = ng;
//    this->NgayDen.Thang = thg;
//    this->NgayDen.Nam = nam;
//    this->NgayDen.Gio = h;
//}

//void KhachHang::NhapNgayTraPhong(int ng, int thg, int nam, int h)
//{
//    this->NgayDi.Ngay = ng;
//    this->NgayDi.Thang = thg;
//    this->NgayDi.Nam = nam;
//    this->NgayDi.Gio = h;
//}

//void KhachHang::NhapNgayTraPhong2(Date x)
//{
//    this->NgayDi = x;
//}

//Date& KhachHang::LayNgayDatPhong()
//{
//    return this->NgayDen;
//}

//Date& KhachHang::LayNgayTraPhong()
//{
//    return this->NgayDi;
//}

ostream& operator << (ostream& o, const KhachHang& k)
{
    o << k.CCCD << " " << k.SDT << " " << k.Birth.Ngay << " " << k.Birth.Thang << " " << k.Birth.Nam << endl;
    return o;
}

bool KhachHang::operator == (const KhachHang& kh)
{
    bool check = true;
    if(this->CCCD == kh.CCCD)
    {
        if(this->Ten != kh.Ten) check = false;
        if(this->Birth.Ngay != kh.Birth.Ngay) check = false;
        if(this->Birth.Thang != kh.Birth.Thang) check = false;
        if(this->Birth.Nam != kh.Birth.Nam) check = false;
    }
    else
    {
        check = false;
    }
    return check;
}

bool KhachHang::KiemTraCCCD(string str)
{
    return str == this->CCCD;
}

bool KhachHang::KiemTraThongTinNhapVao()
{
    if (this->CCCD.length() != 12) {
        return false;
    }

    for (int i = 0; i < this->CCCD.length(); i++) {
        if (!isdigit(this->CCCD[i])) {
            return false;
        }
    }

    for (int i = 0; i < this->Ten.length(); i++) {
        if (isdigit(this->Ten[i])) {
            return false;
        }
    }

    if(this->Ten == "")
    {
        return false;
    }

    if (this->SDT.length() < 10 || this->SDT.length() > 11) {
        return false;
    }

    if (this->SDT[0] != '0') {
        return false;
    }

    for (int i = 1; i < this->SDT.length(); i++)
    {
        if (!isdigit(this->SDT[i])) {
            return false;
        }
    }

    time_t now = time(0);
    tm* currentDate = localtime(&now);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;

    if (this->Birth.Nam < currentYear - 122 || this->Birth.Nam > currentYear)
    {
        return false;
    }

    if(currentYear - this->Birth.Nam < 18 || currentYear - this->Birth.Nam == 18 && currentMonth - this->Birth.Thang < 0 || currentYear - this->Birth.Nam == 18 && currentMonth - this->Birth.Thang == 0 && currentDay - this->Birth.Ngay < 0)
    {
        return false;
    }

    if(this->Birth.Thang < 1 || this->Birth.Thang > 12)
    {
        return false;
    }

    int days_in_month = 0;
    switch (this->Birth.Thang) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days_in_month = 31;
        break;
    case 4:
    case 6:
    case 9:
        days_in_month = 30;
        break;
    case 2:
        if (this->Birth.Nam % 4 == 0) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
        break;
    }

    if (this->Birth.Ngay < 1 || this->Birth.Ngay > days_in_month) {
        return false;
    }

    return true;
}

//bool KhachHang::KiemTraCapNhatThoiGian()
//{
//    time_t now = time(0);
//    tm* currentDate = localtime(&now);
//    int currentYear = currentDate->tm_year + 1900;
//    int currentMonth = currentDate->tm_mon + 1;
//    int currentDay = currentDate->tm_mday;
//    int currentHour = currentDate->tm_hour;

//    bool check = false;

//    int gioden = this->NgayDen.Gio;
//    int ngayden = this->NgayDen.Ngay;
//    int thangden = this->NgayDen.Thang;
//    int namden = this->NgayDen.Nam;

//    if(namden < currentYear) check = true;
//    if(namden == currentYear && thangden < currentMonth) check = true;
//    if(namden == currentYear && thangden == currentMonth && ngayden < currentDay) check = true;
//    if(namden == currentYear && thangden == currentMonth && ngayden == currentDay && gioden <= currentHour) check = true;

//    return check;
//}

//bool KhachHang::KiemTraPhongDuocDatChua(int gioden, int ngayden, int thangden, int namden, int giodi, int ngaydi, int thangdi, int namdi)
//{
//    if(this->NgayDi.Nam < namden) return true;
//    if(this->NgayDi.Nam == namden && this->NgayDi.Thang < thangden) return true;
//    if(this->NgayDi.Nam == namden && this->NgayDi.Thang == thangden && this->NgayDi.Ngay < ngayden) return true;
//    if(this->NgayDi.Nam == namden && this->NgayDi.Thang == thangden && this->NgayDi.Ngay == ngayden && this->NgayDi.Gio < gioden) return true;

//    if(namdi < this->NgayDen.Nam) return true;
//    if(namdi == this->NgayDen.Nam && thangdi < this->NgayDen.Thang) return true;
//    if(namdi == this->NgayDen.Nam && thangdi == this->NgayDen.Thang && ngaydi < this->NgayDen.Ngay) return true;
//    if(namdi == this->NgayDen.Nam && thangdi == this->NgayDen.Thang && ngaydi == this->NgayDen.Ngay && giodi < this->NgayDen.Gio) return true;

//    return false;
//}

//bool KhachHang::KiemTraQuaGioKhachHang()
//{
//    time_t now = time(0);
//    tm* currentDate = localtime(&now);
//    int currentYear = currentDate->tm_year + 1900;
//    int currentMonth = currentDate->tm_mon + 1;
//    int currentDay = currentDate->tm_mday;
//    int currentHour = currentDate->tm_hour;

//    bool check = false;

//    if(this->NgayDi.Nam < currentYear) check = true;
//    if(this->NgayDi.Nam == currentYear && this->NgayDi.Thang < currentMonth) check = true;
//    if(this->NgayDi.Nam == currentYear && this->NgayDi.Thang == currentMonth && this->NgayDi.Ngay < currentDay) check = true;
//    if(this->NgayDi.Nam == currentYear && this->NgayDi.Thang == currentMonth && this->NgayDi.Ngay == currentDay && this->NgayDi.Gio <= currentHour) check = true;

//    if(check == true)
//    {
//        this->NgayDi.Nam = currentYear;
//        this->NgayDi.Thang = currentMonth;
//        this->NgayDi.Ngay = currentDay;
//        this->NgayDi.Gio = currentHour;
//        return true;
//    }
//    return false;
//}

string KhachHang::LayTenPhong()
{
    return "";
}

vector<int> KhachHang::LayDichVu()
{
    vector<int> v;
    return v;
}

//void KhachHang::TangDichVu(int i)
//{
//    this->DichVu[i]++;
//}

//void KhachHang::TinhTienPhong(long long gt)
//{
//    this->TongTien = 0;
//    long long tiendv = 30000*DichVu[0] + 35000*DichVu[1] + 50000*DichVu[2] + 40000*DichVu[3];
//    int gioden = this->NgayDen.Gio;
//    int ngayden = this->NgayDen.Ngay;
//    int thangden = this->NgayDen.Thang;
//    int namden = this->NgayDen.Nam;
//    int giodi = this->NgayDi.Gio;
//    int ngaydi = this->NgayDi.Ngay;
//    int thangdi = this->NgayDi.Thang;
//    int namdi = this->NgayDi.Nam;

    // từ 6h sáng -> 18h tối  : giá * 85%
    // từ 18h tối -> 24h -> 0 -> 6h sáng : giá gốc
    // 1 ngày 00:00 -> 24:00
    // khách hàng đặt phòng tính tiền tối thiểu 6h, tiền tính thêm*45%
    // từ 36 tiếng trở đi : giá mới * 90%

//    int dem = 0;
//    while(!(ngaydi == ngayden && thangdi == thangden && namdi == namden && giodi == gioden))
//    {
//        gioden++;
//        dem++;
//        if(gioden == 24)
//        {
//            gioden = 0;
//            ngayden++;
//        }
//        if(ngayden == 32 && (thangden == 1 || thangden == 3 || thangden == 5 || thangden == 7 || thangden == 8 || thangden == 10 || thangden == 12))
//        {
//            ngayden = 1;
//            thangden++;
//        }
//        if(ngayden == 31 && (thangden == 4 || thangden == 6 || thangden == 9 || thangden == 11))
//        {
//            ngayden = 1;
//            thangden++;
//        }
//        if(ngayden == 30 && thangden == 2 && namden%4 == 0)
//        {
//            ngayden = 1;
//            thangden++;
//        }
//        if(ngayden == 29 && thangden == 2 && namden%4 != 0)
//        {
//            ngayden = 1;
//            thangden++;
//        }
//        if(thangden == 13)
//        {
//            thangden = 1;
//            namden++;
//        }
//        long long money = 0;
//        if((gioden >= 0 && gioden < 6) || (gioden >= 18 && gioden < 24))
//        {
//            money = money + gt*(100.0/100);
//        }
//        if(gioden >= 6 && gioden < 18)
//        {
//            money = money + gt*(85.0/100);
//        }
//        if(dem < 36)
//        {
//            this->TongTien = this->TongTien + money;
//        }
//        else
//        {
//            this->TongTien = this->TongTien + money*(90.0/100);
//        }
//    }
//    if(dem < 6)
//    {
//        this->TongTien = this->TongTien + (6 - (giodi - gioden))*gt*(45.0/100);
//    }
//    this->TongTien = this->TongTien + tiendv;
//}

long long KhachHang::LayTienPhong()
{
    return 0;
}

int KhachHang::LaySoLuong()
{
    return this->SoLuong;
}

void KhachHang::NhapSoLuong(int k)
{
    this->SoLuong = k;
}

void KhachHang::TangSoLuong()
{
    this->SoLuong++;
}

string KhachHang::LayNgayDen()
{
    return "";
}

string KhachHang::LayNgayDi()
{
    return "";
}

string KhachHang::LayNgayDiThucTe()
{
    return "";
}

string KhachHang::LayMaHD()
{
    return this->MaHD;
}
