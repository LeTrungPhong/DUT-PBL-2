#include "phongthuong.h"

long long PhongThuong::GiaTienGDoi = 0;
long long PhongThuong::GiaPhongThuong = 0;

PhongThuong::PhongThuong()
{
    this->TenPhong = "";
    this->TrongPhong = 0;
    this->GiuongDon = -1;
    this->GiuongDoi = -1;
    this->GiaPhong = 0;
}

PhongThuong::PhongThuong(long long gtgdoi, long long gtpt)
{
    this->GiaTienGDoi = gtgdoi;
    this->GiaPhongThuong = gtpt;
}

PhongThuong::PhongThuong(string Tenp, bool Trongp, int GDon, int GDoi)
    : PhongCoBan(Tenp,Trongp,GDon),GiuongDoi(GDoi)
{ }

PhongThuong::~PhongThuong()
{ }

long long PhongThuong::LayGTGDoi()
{
    return GiaTienGDoi;
}

long long PhongThuong::LayGTPT()
{
    return GiaPhongThuong;
}

void PhongThuong::NhapThongTinPhong(string Tenp, bool Trongp, int GDon, int GDoi)
{
    this->TenPhong = Tenp;
    this->TrongPhong = Trongp;
    this->GiuongDon = GDon;
    this->GiuongDoi = GDoi;
    PhongThuong::TinhTienPhong();
}

void PhongThuong::TinhTienPhong()
{
    this->GiaPhong = (this->GiuongDon)*GiaTienGDon + (this->GiuongDoi)*GiaTienGDoi + GiaPhongThuong;
}

const PhongThuong& PhongThuong::operator = (const PhongThuong& p)
{
    if(this != &p)
    {
        this->TenPhong = p.TenPhong;
        this->TrongPhong = p.TrongPhong;
        this->GiuongDon = p.GiuongDon;
        this->GiuongDoi = p.GiuongDoi;
        this->GiaPhong = p.GiaPhong;
    }
    return *this;
}

ostream& operator << (ostream& o, const PhongThuong &p)
{
    o << p.TenPhong << " " << p.TrongPhong << " " << p.GiuongDon << " " << p.GiuongDoi << endl;
    return o;
}

int PhongThuong::LaySoLuongGiuongDoi()
{
    return this->GiuongDoi;
}

bool PhongThuong::KiemTraPhongTheoChiDinh(int a, int b, int e, long long f, long long g)
{

    if(a != 0)
    {
        if((a-1) != this->GiuongDon) return false;
    }
    if(b != 0)
    {
        if((b-1) != this->GiuongDoi) return false;
    }
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

void PhongThuong::DatLaiSoGiuongDon(int k)
{
    this->GiuongDon = k;
}

void PhongThuong::DatLaiSoGiuongDoi(int k)
{
    this->GiuongDoi = k;
}
