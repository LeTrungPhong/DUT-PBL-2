#include "quanly.h"

QuanLy::QuanLy()
{ }

QuanLy::~QuanLy()
{
    delete[] this->tt;
}

void QuanLy::NhapDuLieuQuanLy(string tk, string mk, int size, TiepTan *t)
{
    this->TaiKhoan = tk;
    this->MatKhau = mk;
    this->size = size;
    this->tt = new TiepTan[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->tt + i) = *(t + i);
    }
}

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
        this->TaiKhoan = q.TaiKhoan;
        this->MatKhau = q.MatKhau;
        this->size = q.size;
        this->tt = new TiepTan[this->size];
        for(int i = 0; i < this->size; i++)
        {
            *(this->tt + i) = *(q.tt + i);
        }
    }
    return *this;
}

bool QuanLy::KiemTraTiepTanDangNhap(string tk, string mk)
{
    for(int i = 0; i < this->size; i++)
    {
        if((this->tt + i)->KiemTraTaiKhoanMatKhau(tk,mk))
        {
            return true;
        }
    }
    return false;
}

TiepTan& QuanLy::LayThongTinTiepTan(string tk, string mk)
{
    for(int i = 0; i < this->size; i++)
    {
        if((this->tt + i)->KiemTraTaiKhoanMatKhau(tk,mk))
        {
            return *(this->tt + i);
        }
    }
    TiepTan temp;
    return temp;
}

bool QuanLy::KiemTraQuanLyDangNhap(string tk, string mk)
{
    if(this->TaiKhoan == tk && this->MatKhau == mk)
    {
        return true;
    }
    return false;
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
