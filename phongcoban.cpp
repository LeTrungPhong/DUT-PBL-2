#include "phongcoban.h"

long long PhongCoBan::GiaTienGDon = 0;
long long PhongCoBan::GiaPhongCoBan = 0;

PhongCoBan::PhongCoBan()
{
    this->TenPhong = "";
    this->TrongPhong = 0;
    this->GiuongDon = -1;
    this->GiaPhong = 0;
}

PhongCoBan::PhongCoBan(long long gtgdon, long long gtpcb)
{
    this->GiaTienGDon = gtgdon;
    this->GiaPhongCoBan = gtpcb;
}

PhongCoBan::PhongCoBan(string Tenp, bool Trongp)
    :TenPhong(Tenp),TrongPhong(Trongp),GiuongDon(1)
{ }

PhongCoBan::PhongCoBan(string Tenp, bool Trongp, int GDon)
    :TenPhong(Tenp),TrongPhong(Trongp),GiuongDon(GDon)
{ }

PhongCoBan::~PhongCoBan()
{ }

long long PhongCoBan::LayGTGDon()
{
    return GiaTienGDon;
}

long long PhongCoBan::LayGTPCB()
{
    return GiaPhongCoBan;
}

void PhongCoBan::NhapThongTinPhong(string Tenp, bool Trongp)
{
    this->TenPhong = Tenp;
    this->TrongPhong = Trongp;
    this->GiuongDon = 1;
    PhongCoBan::TinhTienPhong();
}

void PhongCoBan::TinhTienPhong()
{
    this->GiaPhong = (this->GiuongDon)*GiaTienGDon + GiaPhongCoBan;
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

void PhongCoBan::ChuyenTrangThaiPhongTrong()
{
    this->TrongPhong = false;
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

bool PhongCoBan::KiemTraPhongTheoChiDinh(int a, int b, int e, long long f, long long g)
{
    if(a != 0)
    {
        if((a-1) != this->GiuongDon) return false;
    }
    if(b != 0) return false;
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
    if(!(this->GiaPhong >= f && this->GiaPhong <= g)) return false;
    return true;
}
