#include "tieptan.h"

TiepTan::TiepTan()
{
    this->CCCD = "0";
    this->SDT = "0";
    this->Birth.Ngay = 0;
    this->Birth.Thang = 0;
    this->Birth.Nam = 0;
}

TiepTan::TiepTan(string CCCD, string SDT, string Ten, int ng, int th, int nam, string tk, string mk, QuanLyKhachHang k, QuanLyPhong p)
    :qlkh(k),qlp(p)
{
    this->CCCD = CCCD;
    this->Ten = Ten;
    this->SDT = SDT;
    this->Birth.Ngay = ng;
    this->Birth.Thang = th;
    this->Birth.Nam = nam;
    this->TaiKhoan = tk;
    this->MatKhau = mk;
}

TiepTan::~TiepTan()
{ }

void TiepTan::NhapTaiKhoanMatKhau(string tk,string mk)
{
    this->TaiKhoan = tk;
    this->MatKhau = mk;
}

void TiepTan::NhapThongTinChucNang(const QuanLyKhachHang &k, const QuanLyPhong &p)
{
    this->qlkh = k;
    this->qlp = p;
}

bool TiepTan::KiemTraTaiKhoanMatKhau(string tk, string mk)
{
    if(this->TaiKhoan == tk && this->MatKhau == mk)
    {
        return true;
    }
    return false;
}

bool TiepTan::KiemTraTenPhong(string str)
{
    return qlp.KiemTraTenPhong(str);
}

bool TiepTan::KiemTraPhongTrong(string str)
{
    return qlp.KiemTraPhongTrong(str);
}

bool TiepTan::KiemTraPhongBaoTri(string str)
{
    return qlkh.KiemTraPhongBaoTri(str);
}

void TiepTan::KhachHangDatPhong(KhachHang &k)
{
    qlkh.NhapKhachHangMoi(k);
}

void TiepTan::HienThiPhong()
{
    qlp.HienThiPhong();
}

void TiepTan::LuuThongTinKhachHang(KhachHang &k, string tp)
{
    k.NhapPhongKhachHangDat(tp);
}

void TiepTan::NhapKhachHangVaoHashTable(string CCCD)
{
    qlkh.NhapKhachHangVaoHashTable(CCCD);
}

void TiepTan::HienThiThongTinKhachHang()
{
    qlkh.HienThiThongTinKhachHang();
}

void TiepTan::HienThiTable()
{
    qlkh.HienThiTable();
}

void TiepTan::ThemPhongCoBan(PhongCoBan p)
{
    qlp.ThemPhongCoBan(p);
}

void TiepTan::ThemPhongThuong(PhongThuong p)
{
    qlp.ThemPhongThuong(p);
}

void TiepTan::ThemPhongThuongGia(PhongThuongGia p)
{
    qlp.ThemPhongThuongGia(p);
}

const TiepTan& TiepTan::operator = (const TiepTan &tt)
{
    if(this != &tt)
    {
        this->CCCD = tt.CCCD;
        this->SDT = tt.SDT;
        this->Birth.Ngay = tt.Birth.Ngay;
        this->Birth.Thang = tt.Birth.Thang;
        this->Birth.Nam = tt.Birth.Nam;
        this->TaiKhoan = tt.TaiKhoan;
        this->MatKhau = tt.MatKhau;
    }
    return *this;
}

vector<string> TiepTan::LayTenCacPhong(int a, int b, int d, int e, long long f, long long g)
{
    return qlp.LayTenCacPhong(a,b,d,e,f,g);
}

vector<string> TiepTan::LayTenCacPhong2(KhachHang &k, long long min, long long max)
{
    return qlp.LayTenCacPhong2(k,min,max);
}

int TiepTan::XacDinhLoaiPhong(string str)
{
    return qlp.XacDinhLoaiPhong(str);
}

PhongCoBan& TiepTan::LayThongTinPhongCoBan(string str)
{
    return qlp.LayThongTinPhongCoBan(str);
}

PhongThuong& TiepTan::LayThongTinPhongThuong(string str)
{
    return qlp.LayThongTinPhongThuong(str);
}

PhongThuongGia& TiepTan::LayThongTinPhongThuongGia(string str)
{
    return qlp.LayThongTinPhongThuongGia(str);
}

KhachHang& TiepTan::KhachHangTheoPhong(string str)
{
    return qlkh.KhachHangTheoPhong(str);
}

void TiepTan::ChuyenTrangThaiPhong(string str)
{
    this->qlp.ChuyenTrangThaiPhong(str);
}

void TiepTan::TangDichVu(int k, string str)
{
    this->qlkh.TangDichVu(k,str);
}

void TiepTan::LuuPhongVaoFile()
{
    (this->qlp).LuuPhongVaoFile();
}

void TiepTan::LuuKhachHangCuVaoFile()
{
    (this->qlkh).LuuKhachHangCuVaoFile();
}

void TiepTan::LuuKhachHangMoiVaoFile()
{
    (this->qlkh).LuuKhachHangMoiVaoFile();
}

