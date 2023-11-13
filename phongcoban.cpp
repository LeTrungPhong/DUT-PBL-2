#include "phongcoban.h"

PhongCoBan::PhongCoBan()
{
    this->TenPhong = "";
    this->TrongPhong = 0;
    this->GiuongDon = -1;
    this->GiaPhong = 0;
}

PhongCoBan::PhongCoBan(string Tenp, bool Trongp)
    :TenPhong(Tenp),TrongPhong(Trongp),GiuongDon(1)
{ }

PhongCoBan::PhongCoBan(string Tenp, bool Trongp, int GDon)
    :TenPhong(Tenp),TrongPhong(Trongp),GiuongDon(GDon)
{ }

PhongCoBan::~PhongCoBan()
{ }

void PhongCoBan::NhapThongTinPhong(string Tenp, bool Trongp)
{
    this->TenPhong = Tenp;
    this->TrongPhong = Trongp;
    this->GiuongDon = 1;
    PhongCoBan::TinhTienPhong();
}

void PhongCoBan::TinhTienPhong()
{
    this->GiaPhong = (this->GiuongDon)*10000 + 30000;
}

const PhongCoBan& PhongCoBan::operator = (const PhongCoBan& p)
{
    if(this != &p)
    {
        this->TenPhong = p.TenPhong;
        this->TrongPhong = p.TrongPhong;
        this->GiuongDon = p.GiuongDon;
        this->GiaPhong = p.GiaPhong;
    }
    return *this;
}

int PhongCoBan::KiemTraPhongTrong()
{
    return this->TrongPhong?1:0;
}

void PhongCoBan::ChuyenTrangThaiPhong()
{
    this->TrongPhong ? this->TrongPhong = false : this->TrongPhong = true;
}

ostream& operator << (ostream& o, const PhongCoBan &p)
{
    o << p.TenPhong << " " << p.TrongPhong << " " << p.GiuongDon << endl;
    return o;
}

string PhongCoBan::LayTenPhong()
{
    return this->TenPhong;
}

int PhongCoBan::LaySoLuongGiuongDon()
{
    return this->GiuongDon;
}

long long PhongCoBan::LayGiaTien()
{
    return this->GiaPhong;
}

bool PhongCoBan::KiemTraPhongTheoChiDinh(int a, int b,int c, int e)
{
    if(a != 0)
    {
        if((a-1) != this->GiuongDon) return false;
    }
    if(b != 0) return false;
//    if(c != this->Tang) return false;
    if(e != 0)
    {
        int check;
        if(PhongCoBan::KiemTraPhongTrong())
        {
            check = 1;
        }
        else check = 2;
        if(check == e && e == 1)
        {
            return true;
        }
        if(check == e && e == 2)
        {
            return true;
        }
        return false;
    }
    return true;
}


