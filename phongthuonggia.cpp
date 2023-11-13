#include "phongthuonggia.h"

PhongThuongGia::PhongThuongGia()
{
    this->TenPhong = "";
    this->TrongPhong = 0;
    this->GiuongDon = -1;
    this->GiuongDoi = -1;
    this->GiaPhong = 0;
}

PhongThuongGia::PhongThuongGia(string Tenp, bool Trongp, int GDon, int GDoi)
    : PhongThuong(Tenp,Trongp,GDon,GDoi)
{ }

PhongThuongGia::~PhongThuongGia()
{ }

void PhongThuongGia::NhapThongTinPhong(string Tenp, bool Trongp, int GDon, int GDoi)
{
    this->TenPhong = Tenp;
    this->TrongPhong = Trongp;
    this->GiuongDon = GDon;
    this->GiuongDoi = GDoi;
    PhongThuongGia::TinhTienPhong();
}

void PhongThuongGia::TinhTienPhong()
{
    this->GiaPhong = (this->GiuongDon)*10000 + (this->GiuongDoi)*15000 + 50000 + 10000 + 5000;
}

const PhongThuongGia& PhongThuongGia::operator = (const PhongThuongGia& p)
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

ostream& operator << (ostream& o, const PhongThuongGia &p)
{
    o << p.TenPhong << " " << p.TrongPhong << " " << p.GiuongDon << " " << p.GiuongDoi << endl;
    return o;
}
