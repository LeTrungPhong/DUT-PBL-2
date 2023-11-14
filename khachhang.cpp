#include "khachhang.h"
#include <ctime>

KhachHang::KhachHang()
{
    this->CCCD = "0";
    this->Ten = "0";
    this->SDT = "0";
    this->Birth.Ngay = 0;
    this->Birth.Thang = 0;
    this->Birth.Nam = 0;
    this->Birth.Gio = 0;
    this->NgayDen.Ngay = 0;
    this->NgayDen.Thang = 0;
    this->NgayDen.Nam = 0;
    this->NgayDen.Gio = 0;
    this->NgayDi.Ngay = 0;
    this->NgayDi.Thang = 0;
    this->NgayDi.Nam = 0;
    this->NgayDi.Gio = 0;
    this->TenPhong = "0";
    this->TongTien = 0;
    for(int i = 0; i < 4; i++)
    {
        (this->DichVu).push_back(0);
    }
}

KhachHang::~KhachHang()
{ }

const KhachHang& KhachHang::operator = (const KhachHang& kh)
{
    if(this != &kh)
    {
        this->CCCD = kh.CCCD;
        this->Ten = kh.Ten;
        this->SDT = kh.SDT;
        this->Birth = kh.Birth;
        this->TenPhong = kh.TenPhong;
        this->DichVu = kh.DichVu;
        this->NgayDen = kh.NgayDen;
        this->NgayDi = kh.NgayDi;
        this->TongTien = kh.TongTien;
    }
    return *this;
}

void KhachHang::NhapPhongKhachHangDat(string tenp)
{
    this->TenPhong = tenp;
}

void KhachHang::NhapThongTinKhac(string tenp, vector<int> dv, int gioden, int ngayden, int thangden, int namden)
{
    this->TenPhong = tenp;
    this->DichVu = dv;
    this->NgayDen.Gio = gioden;
    this->NgayDen.Ngay = ngayden;
    this->NgayDen.Thang = thangden;
    this->NgayDen.Nam = namden;
}

void KhachHang::NhapThongTinKhac(string tenp, vector<int> dv, int gioden, int ngayden, int thangden, int namden, int giodi, int ngaydi, int thangdi, int namdi, long long gp)
{
    this->TenPhong = tenp;
    this->DichVu = dv;
    this->NgayDen.Gio = gioden;
    this->NgayDen.Ngay = ngayden;
    this->NgayDen.Thang = thangden;
    this->NgayDen.Nam = namden;
    this->NgayDi.Gio = giodi;
    this->NgayDi.Ngay = ngaydi;
    this->NgayDi.Thang = thangdi;
    this->NgayDi.Nam = namdi;
    this->TongTien = gp;
}

void KhachHang::NhapNgayDatPhong(int ng, int thg, int nam, int h)
{
    this->NgayDen.Ngay = ng;
    this->NgayDen.Thang = thg;
    this->NgayDen.Nam = nam;
    this->NgayDen.Gio = h;
}

void KhachHang::NhapNgayTraPhong(int ng, int thg, int nam, int h)
{
    this->NgayDi.Ngay = ng;
    this->NgayDi.Thang = thg;
    this->NgayDi.Nam = nam;
    this->NgayDi.Gio = h;
}

Date& KhachHang::LayNgayDatPhong()
{
    return this->NgayDen;
}

Date& KhachHang::LayNgayTraPhong()
{
    return this->NgayDi;
}

ostream& operator << (ostream& o, const KhachHang& k)
{
    o << k.CCCD << " " << k.SDT << " " << k.Birth.Ngay << " " << k.Birth.Thang << " " << k.Birth.Nam << " " << k.TenPhong << endl;
    return o;
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

    if (this->Birth.Thang < 1 || this->Birth.Thang > 12)
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

string KhachHang::LayTenPhong()
{
    return this->TenPhong;
}

vector<int> KhachHang::LayDichVu()
{
    return this->DichVu;
}

void KhachHang::TangDichVu(int i)
{
    this->DichVu[i]++;
}

void KhachHang::TinhTienPhong(long long gt)
{
    this->TongTien = 0;
    long long tiendv = 30000*DichVu[0] + 35000*DichVu[1] + 50000*DichVu[2] + 40000*DichVu[3];
    int gioden = this->NgayDen.Gio;
    int ngayden = this->NgayDen.Ngay;
    int thangden = this->NgayDen.Thang;
    int namden = this->NgayDen.Nam;
    int giodi = this->NgayDi.Gio;
    int ngaydi = this->NgayDi.Ngay;
    int thangdi = this->NgayDi.Thang;
    int namdi = this->NgayDi.Nam;   
    
    // từ 6h sáng -> 18h tối  : giá * 85%
    // từ 18h tối -> 24h -> 0 -> 6h sáng : giá gốc
    // 1 ngày 00:00 -> 24:00
    // khách hàng đặt phòng tính tiền tối thiểu 6h, tiền tính thêm*45%
    // từ 36 tiếng trở đi : giá mới * 90%

    int dem = 0;
    while(!(ngaydi == ngayden && thangdi == thangden && namdi == namden && giodi == gioden))
    {
        gioden++;
        dem++;
        if(gioden == 24)
        {
            gioden = 0;
            ngayden++;
        }
        if(ngayden == 32 && (thangden == 1 || thangden == 3 || thangden == 5 || thangden == 7 || thangden == 8 || thangden == 10 || thangden == 12))
        {
            ngayden = 1;
            thangden++;
        }
        if(ngayden == 31 && (thangden == 4 || thangden == 6 || thangden == 9 || thangden == 11))
        {
            ngayden = 1;
            thangden++;
        }
        if(ngayden == 30 && thangden == 2 && namden%4 == 0)
        {
            ngayden = 1;
            thangden++;
        }
        if(ngayden == 29 && thangden == 2 && namden%4 != 0)
        {
            ngayden = 1;
            thangden++;
        }
        if(thangden == 13)
        {
            thangden = 1;
            namden++;
        }
        long long money = 0;
        if((gioden >= 0 && gioden < 6) || (gioden >= 18 && gioden < 24))
        {
            money = money + gt*(100.0/100);
        }
        if(gioden >= 6 && gioden < 18)
        {
            money = money + gt*(85.0/100);
        }
        if(dem < 36)
        {
            this->TongTien = this->TongTien + money;
        }
        else
        {
            this->TongTien = this->TongTien + money*(90.0/100);
        }
    }
    if(dem < 6)
    {
        this->TongTien = this->TongTien + (6 - (giodi - gioden))*gt*(45.0/100);
    }
    this->TongTien = this->TongTien + tiendv;
}

long long KhachHang::LayTienPhong()
{
    return this->TongTien;
}

string KhachHang::LayNgayDen()
{
    string str = to_string(this->NgayDen.Gio) + "/" + to_string(this->NgayDen.Ngay) + "/" + to_string(this->NgayDen.Thang) + "/" + to_string(this->NgayDen.Nam);
    return str;
}

string KhachHang::LayNgayDi()
{
    string str = to_string(this->NgayDi.Gio) + "/" + to_string(this->NgayDi.Ngay) + "/" + to_string(this->NgayDi.Thang) + "/" + to_string(this->NgayDi.Nam);
    return str;
}
