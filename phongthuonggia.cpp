#include "phongthuonggia.h"

long long PhongThuongGia::DichVuThuongGia = 0;
long long PhongThuongGia::GiaPhongThuongGia = 0;

PhongThuongGia::PhongThuongGia()
{
    this->TenPhong = "";
    this->TrongPhong = 0;
    this->GiuongDon = -1;
    this->GiuongDoi = -1;
    this->GiaPhong = 0;
}

PhongThuongGia::PhongThuongGia(long long gtdvtg, long long gtptg)
{
    this->GiaPhongThuongGia = gtptg;
    this->DichVuThuongGia = gtdvtg;
}

PhongThuongGia::PhongThuongGia(string Tenp, bool Trongp, int GDon, int GDoi)
    : PhongThuong(Tenp,Trongp,GDon,GDoi)
{ }

PhongThuongGia::~PhongThuongGia()
{ }

long long PhongThuongGia::LayDVTG()
{
    return DichVuThuongGia;
}

long long PhongThuongGia::LayGTPTG()
{
    return GiaPhongThuongGia;
}

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
    this->GiaPhong = (this->GiuongDon)*GiaTienGDon + (this->GiuongDoi)*GiaTienGDoi + GiaPhongThuongGia + DichVuThuongGia;
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
