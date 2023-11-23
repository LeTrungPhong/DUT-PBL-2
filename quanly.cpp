#include "quanly.h"

QuanLy::QuanLy()
{ }

QuanLy::~QuanLy()
{ }

void QuanLy::NhapThongTinChucNang(const QuanLyKhachHang &k, const QuanLyPhong &p)
{
    this->k = k;
    this->p = p;
}

const QuanLy& QuanLy::operator = (const QuanLy& q)
{
    if(this != &q)
    {
        this->CCCD = q.CCCD;
        this->SDT = q.SDT;
        this->Birth.Ngay = q.Birth.Ngay;
        this->Birth.Thang = q.Birth.Thang;
        this->Birth.Nam = q.Birth.Nam;
    }
    return *this;
}

vector<KhachHang> QuanLy::LayDanhSachKhachHangMoi()
{
    return this->k.LayDanhSachKhachHangMoi();
}

vector<KhachHang> QuanLy::LayDanhSachKhachHangCu()
{
    return this->k.LayDanhSachKhachHangCu();
}

vector<KhachHang> QuanLy::LayDSKHTheoTTDSC(string cccd, string tenphong, string tenkh)
{
    return this->k.LayDSKHTheoTTDSC(cccd,tenphong,tenkh);
}

vector<KhachHang> QuanLy::LayDSKHTheoTTDSM(string cccd, string tenphong, string tenkh)
{
    return this->k.LayDSKHTheoTTDSM(cccd,tenphong,tenkh);
}
