#include "quanly.h"

QuanLy::QuanLy()
{ }

QuanLy::~QuanLy()
{ }

void QuanLy::NhapThongTinChucNang(const QuanLyKhachHang &k, const QuanLyPhong &p)
{
    this->p = p;
    this->k = k;
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

bool QuanLy::KiemTraTenPhong(string str)
{
    return this->p.KiemTraTenPhong(str);
}

bool QuanLy::KiemTraPhongTrong(string str)
{
    return this->k.KiemTraPhongBaoTri(str);
}

vector<KhachHang> QuanLy::LayDanhSachKhachHangMoi()
{
    return this->k.LayDanhSachKhachHangMoi();
}

vector<KhachHang> QuanLy::LayDanhSachKhachHangCu()
{
    return this->k.LayDanhSachKhachHangCu();
}

vector<HoaDon> QuanLy::LayDSHDTheoTTDSC(string cccd, string tenphong, string mahd)
{
    return this->k.LayDSHDTheoTTDSC(cccd,tenphong,mahd);
}

vector<HoaDon> QuanLy::LayDSHDTheoTTDSM(string cccd, string tenphong, string mahd)
{
    return this->k.LayDSHDTheoTTDSM(cccd,tenphong,mahd);
}

vector<HoaDon> QuanLy::LayDSHD()
{
    return this->k.LayDSHD();
}

vector<HoaDon> QuanLy::LayDSHDM()
{
    return this->k.LayDSHDM();
}

KhachHang& QuanLy::KhachHangCuTheoCCCD(string str)
{
    return this->k.KhachHangCuTheoCCCD(str);
}

int QuanLy::XacDinhLoaiPhong(string str)
{
    return p.XacDinhLoaiPhong(str);
}

PhongCoBan& QuanLy::LayThongTinPhongCoBan(string str)
{
    return p.LayThongTinPhongCoBan(str);
}

PhongThuong& QuanLy::LayThongTinPhongThuong(string str)
{
    return p.LayThongTinPhongThuong(str);
}

PhongThuongGia& QuanLy::LayThongTinPhongThuongGia(string str)
{
    return p.LayThongTinPhongThuongGia(str);
}

void QuanLy::ThemPhong(const PhongCoBan &p)
{
    this->p.ThemPhong(p);
}

void QuanLy::ThemPhong(const PhongThuong &p)
{
    this->p.ThemPhong(p);
}

void QuanLy::ThemPhong(const PhongThuongGia &p)
{
    this->p.ThemPhong(p);
}

void QuanLy::XoaPhong(string str, int lp)
{
    this->p.XoaPhong(str,lp);
}

void QuanLy::LuuPhongVaoFile()
{
    (this->p).LuuPhongVaoFile();
}

void QuanLy::LuuKhachHangCuVaoFile()
{
    (this->k).LuuKhachHangCuVaoFile();
}

void QuanLy::LuuKhachHangMoiVaoFile()
{
    (this->k).LuuKhachHangMoiVaoFile();
}

void QuanLy::LayDuLieuTuFilePhong()
{
    this->p.LayDuLieuTuFilePhong();
}

void QuanLy::LayDuLieuTuFileKhachHangCu()
{
    this->k.LayDuLieuTuFileKhachHangCu();
}

void QuanLy::LayDuLieuTuFileHoaDon()
{
    this->k.LayDuLieuTuFileHoaDon();
}

void QuanLy::LayDuLieuTuFileKhachHangMoi()
{
    this->k.LayDuLieuTuFileKhachHangMoi();
}
