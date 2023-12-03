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

void KhachHang::NhapThongTinKhac(string mahd, int soluong)
{
    this->MaHD = mahd;
    this->SoLuong = soluong;
}

void KhachHang::NhapMaHD(string mahd)
{
    this->MaHD = mahd;
}

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

string KhachHang::LayTenPhong()
{
    return "";
}

vector<int> KhachHang::LayDichVu()
{
    vector<int> v;
    return v;
}

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
