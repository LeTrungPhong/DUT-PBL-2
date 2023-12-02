#include "hoadon.h"

HoaDon::HoaDon()
{
    this->MaHD = "0";
    this->NgayDen.Ngay = 0;
    this->NgayDen.Thang = 0;
    this->NgayDen.Nam = 0;
    this->NgayDen.Gio = 0;
    this->NgayDi.Ngay = 0;
    this->NgayDi.Thang = 0;
    this->NgayDi.Nam = 0;
    this->NgayDi.Gio = 0;
    this->NgayDiThucTe.Ngay = 0;
    this->NgayDiThucTe.Thang = 0;
    this->NgayDiThucTe.Nam = 0;
    this->NgayDiThucTe.Gio = 0;
    this->TenPhong = "0";
    this->CCCD = "0";
    this->TongTien = 0;
    for(int i = 0; i < 4; i++)
    {
        (this->DichVu).push_back(0);
    }
}

HoaDon::~HoaDon()
{ }

void HoaDon::NhapThongTin(string cccd, string tp, vector<int> dv, const Date& nden, const Date& ndi, const Date& nditt, long long tt)
{
    this->CCCD = cccd;
    this->TenPhong = tp;
    this->DichVu = dv;
    this->NgayDen = nden;
    this->NgayDi = ndi;
    this->NgayDiThucTe = nditt;
    this->TongTien = tt;
}

void HoaDon::NhapThongTin(string MaHD, string cccd, string tp, vector<int> dv, const Date& nden, const Date& ndi, const Date& nditt, long long tt)
{
    this->MaHD = MaHD;
    this->CCCD = cccd;
    this->TenPhong = tp;
    this->DichVu = dv;
    this->NgayDen = nden;
    this->NgayDi = ndi;
    this->NgayDiThucTe = nditt;
    this->TongTien = tt;
}

void HoaDon::NhapThongTin(const Date& nden, const Date& ndi)
{
    this->NgayDen = nden;
    this->NgayDi = ndi;
}

void HoaDon::NhapTenPhong(string tp)
{
    this->TenPhong = tp;
}

void HoaDon::NhapCCCD(string cccd)
{
    this->CCCD = cccd;
}

void HoaDon::NhapNgayThucTe(const Date& ngtt)
{
    this->NgayDiThucTe = ngtt;
}

void HoaDon::NhapNgayTraPhong(const Date & hd)
{
    this->NgayDi = hd;
}

bool HoaDon::operator == (const HoaDon& hd)
{
    bool check = true;
    if(this->MaHD != hd.MaHD) check = false;
    return check;
}

const HoaDon& HoaDon::operator = (const HoaDon& temp)
{
    if(this != &temp)
    {
        this->MaHD = temp.MaHD;
        this->CCCD = temp.CCCD;
        this->TenPhong = temp.TenPhong;
        this->DichVu = temp.DichVu;
        this->NgayDen = temp.NgayDen;
        this->NgayDi = temp.NgayDi;
        this->NgayDiThucTe = temp.NgayDiThucTe;
        this->TongTien = temp.TongTien;
    }
    return *this;
}

string HoaDon::LayCCCD()
{
    return this->CCCD;
}

long long HoaDon::LayCCCD(int i)
{
    stringstream ss(this->CCCD);
    long long num;
    ss >> num;
    return num;
}

vector<int> HoaDon::LayDichVu()
{
    return this->DichVu;
}

string HoaDon::LaySDT()
{
    return "";
}

string HoaDon::LayTenPhong()
{
    return this->TenPhong;
}

string HoaDon::LayNgayDen()
{
    string str = to_string(this->NgayDen.Gio) + "/" + to_string(this->NgayDen.Ngay) + "/" + to_string(this->NgayDen.Thang) + "/" + to_string(this->NgayDen.Nam);
    return str;
}

string HoaDon::LayNgayDi()
{
    string str = to_string(this->NgayDi.Gio) + "/" + to_string(this->NgayDi.Ngay) + "/" + to_string(this->NgayDi.Thang) + "/" + to_string(this->NgayDi.Nam);
    return str;
}

string HoaDon::LayNgayDiThucTe()
{
    string str = to_string(this->NgayDiThucTe.Gio) + "/" + to_string(this->NgayDiThucTe.Ngay) + "/" + to_string(this->NgayDiThucTe.Thang) + "/" + to_string(this->NgayDiThucTe.Nam);
    return str;
}

long long HoaDon::LayTienPhong()
{
    return this->TongTien;
}

string HoaDon::LayTen()
{
    return "";
}

string HoaDon::LayBirth()
{
    return "";
}

int HoaDon::LaySoLuong()
{
    return 0;
}

void HoaDon::TaoMaHD()
{
    this->MaHD = to_string(this->NgayDen.Gio) + to_string(this->NgayDen.Ngay) + to_string(this->NgayDen.Thang) + to_string(this->NgayDen.Nam) + this->TenPhong;
}

string HoaDon::LayMaHD()
{
    return this->MaHD;
}

void HoaDon::TinhTienPhong(long long gt)
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

void HoaDon::TangDichVu(int k)
{
    this->DichVu[k]++;
}

Date& HoaDon::LayNgayDatPhong()
{
    return this->NgayDen;
}

Date& HoaDon::LayNgayTraPhong()
{
    return this->NgayDi;
}

bool HoaDon::KiemTraCapNhatThoiGian()
{
    time_t now = time(0);
    tm* currentDate = localtime(&now);
    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;
    int currentHour = currentDate->tm_hour;

    bool check = false;

    int gioden = this->NgayDen.Gio;
    int ngayden = this->NgayDen.Ngay;
    int thangden = this->NgayDen.Thang;
    int namden = this->NgayDen.Nam;

    if(namden < currentYear) check = true;
    if(namden == currentYear && thangden < currentMonth) check = true;
    if(namden == currentYear && thangden == currentMonth && ngayden < currentDay) check = true;
    if(namden == currentYear && thangden == currentMonth && ngayden == currentDay && gioden <= currentHour) check = true;

    return check;
}
