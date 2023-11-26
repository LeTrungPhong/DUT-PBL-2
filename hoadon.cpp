#include "hoadon.h"

HoaDon::HoaDon()
{
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

bool HoaDon::operator == (const HoaDon& hd)
{
    bool check = true;
    if(this->CCCD != hd.CCCD) check = false;
    if(this->TenPhong != hd.TenPhong) check = false;
    if(this->DichVu != hd.DichVu) check = false;
    if(this->NgayDen.Ngay != hd.NgayDen.Ngay) check = false;
    if(this->NgayDen.Thang != hd.NgayDen.Thang) check = false;
    if(this->NgayDen.Nam != hd.NgayDen.Nam) check = false;
    if(this->NgayDen.Gio != hd.NgayDen.Gio) check = false;
    if(this->NgayDi.Ngay != hd.NgayDi.Ngay) check = false;
    if(this->NgayDi.Thang != hd.NgayDi.Thang) check = false;
    if(this->NgayDi.Nam != hd.NgayDi.Nam) check = false;
    if(this->NgayDi.Gio != hd.NgayDi.Gio) check = false;
    if(this->NgayDiThucTe.Ngay != hd.NgayDiThucTe.Ngay) check = false;
    if(this->NgayDiThucTe.Thang != hd.NgayDiThucTe.Thang) check = false;
    if(this->NgayDiThucTe.Nam != hd.NgayDiThucTe.Nam) check = false;
    if(this->NgayDiThucTe.Gio != hd.NgayDiThucTe.Gio) check = false;
    if(this->TongTien != hd.TongTien) check = false;
    return check;
}

const HoaDon& HoaDon::operator = (const HoaDon& temp)
{
    if(this != &temp)
    {
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
