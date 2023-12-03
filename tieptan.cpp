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
}

TiepTan::~TiepTan()
{ }

void TiepTan::NhapThongTinChucNang(const QuanLyKhachHang &k, const QuanLyPhong &p)
{
    this->qlkh = k;
    this->qlp = p;
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
    return this->qlkh.KiemTraPhongBaoTri(str);
}

bool TiepTan::KiemTraKhachHangDatPhong(string str)
{
    return this->qlkh.KiemTraKhachHangDatPhong(str);
}

bool TiepTan::KiemTraPhongDuocDatChua(string str, int gioden, int ngayden, int thangden, int namden, int giodi, int ngaydi, int thangdi, int namdi)
{
    return this->qlkh.KiemTraPhongDuocDatChua(str,gioden,ngayden,thangden,namden,giodi,ngaydi,thangdi,namdi);
}

bool TiepTan::KiemTraKhachHangCu(KhachHang& k)
{
    return this->qlkh.KiemTraKhachHangCu(k);
}

bool TiepTan::KiemTraThongTin(KhachHang &k)
{
    return this->qlkh.KiemTraThongTin(k);
}

void TiepTan::KhachHangDatPhong(KhachHang &k)
{
    this->qlkh.NhapKhachHangMoi(k);
}

void TiepTan::HienThiPhong()
{
    qlp.HienThiPhong();
}

void TiepTan::NhapKhachHangVaoHashTable(string CCCD, int check)
{
    qlkh.NhapKhachHangVaoHashTable(CCCD,check);
}

void TiepTan::NhapHoaDonVaoHashTable(HoaDon hd,int check)
{
    qlkh.NhapHoaDonVaoHashTable(hd,check);
}

void TiepTan::HienThiThongTinKhachHang()
{
    qlkh.HienThiThongTinKhachHang();
}

void TiepTan::HienThiTable()
{
    qlkh.HienThiTable();
}

void TiepTan::LayKhachHanghtb(string cccd)
{
    this->qlkh.LayKhachHanghtb(cccd);
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
    }
    return *this;
}

vector<string> TiepTan::LayTenCacPhong(int a, int b, int d, int e, long long f, long long g)
{
    return qlp.LayTenCacPhong(a,b,d,e,f,g);
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

KhachHang& TiepTan::KhachHangTheoPhongTime(string str)
{
    return qlkh.KhachHangTheoPhongTime(str);
}

KhachHang& TiepTan::KhachHangCuTheoCCCD(string str)
{
    return qlkh.KhachHangCuTheoCCCD(str);
}

HoaDon& TiepTan::HoaDonTheoCCCDMaHD(string cccd, string mahd)
{
    return qlkh.HoaDonTheoCCCDMaHD(cccd,mahd);
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

void TiepTan::LuuHoaDonVaoFile()
{
    (this->qlkh).LuuHoaDonVaoFile();
}

void TiepTan::CapNhatTrangThaiPhong()
{
    int sl = this->qlkh.LaySoLuong();
    for(int i = 0; i < sl; ++i)
    {
        KhachHang *k = &((this->qlkh)[i]);
        if(k->LayCCCD() == "0") continue;
        HoaDon *hd = &(this->qlkh.HoaDonTheoCCCDMaHD(k->LayCCCD(),k->LayMaHD()));
        if(hd->KiemTraCapNhatThoiGian())
        {
            string str = hd->LayTenPhong();
            int lp = this->qlp.XacDinhLoaiPhong(str);
            if(lp == 0) continue;
            if(lp == 1) this->qlp.LayThongTinPhongCoBan(str).ChuyenTrangThaiPhongTrong();
            if(lp == 2) this->qlp.LayThongTinPhongThuong(str).ChuyenTrangThaiPhongTrong();
            if(lp == 3) this->qlp.LayThongTinPhongThuongGia(str).ChuyenTrangThaiPhongTrong();
        }
    }
}

bool SoSanhThoiGian(Date x, Date y)
{
    // x <= y
    if(x.Nam < y.Nam) return true;
    if(x.Nam == y.Nam && x.Thang < y.Thang) return true;
    if(x.Nam == y.Nam && x.Thang == y.Thang && x.Ngay < y.Ngay) return true;
    if(x.Nam == y.Nam && x.Thang == y.Thang && x.Ngay == y.Ngay && x.Gio <= y.Gio) return true;
    return false;
}

void TiepTan::CapNhatDuLieuKhachHang()
{
    int sl = this->qlkh.LaySoLuong();
    for(int i = 0; i < sl; ++i)
    {
        KhachHang *kh = &((this->qlkh)[i]);
        if(kh->LayCCCD() == "0") continue;
        HoaDon *hd = &(this->qlkh.HoaDonTheoCCCDMaHD(kh->LayCCCD(),kh->LayMaHD()));
        string str = hd->LayTenPhong();
        vector<int> tt;
        tt.push_back(i);
        int dem = 1;
        for(int x = 0; x < sl; ++x)
        {
            KhachHang *temp = &((this->qlkh)[x]);
            HoaDon *hdt = &(this->qlkh.HoaDonTheoCCCDMaHD(temp->LayCCCD(),temp->LayMaHD()));
            if(i == x) continue;
            if(hdt->LayTenPhong() == str)
            {
                dem++;
                tt.push_back(x);
            }
        }
        for(int x = 1; x < dem; ++x)
        {
            KhachHang *k = &((this->qlkh)[tt[x]]);
            HoaDon *hdt = &(this->qlkh.HoaDonTheoCCCDMaHD(k->LayCCCD(),k->LayMaHD()));
            for(int j = x - 1; j >=0; --j)
            {
                KhachHang *temp = &((this->qlkh)[tt[j]]);
                HoaDon *hdt1 = &(this->qlkh.HoaDonTheoCCCDMaHD(temp->LayCCCD(),temp->LayMaHD()));
                if(SoSanhThoiGian(hdt->LayNgayTraPhong(),hdt1->LayNgayDatPhong()))
                {
                    KhachHang *ct = &((this->qlkh)[tt[j+1]]);
                    *ct = (this->qlkh)[tt[j]];
                }
                else
                {
                    KhachHang *ct = &((this->qlkh)[tt[j+1]]);
                    *ct = *k;
                    break;
                }
                if(j == 0)
                {
                    KhachHang *ct = &((this->qlkh)[tt[0]]);
                    *ct = *k;
                }
            }
        }

        for(int k = dem - 1; k >= 0; --k)
        {
            time_t now = time(0);
            tm* currentDate = localtime(&now);
            int currentYear = currentDate->tm_year + 1900;
            int currentMonth = currentDate->tm_mon + 1;
            int currentDay = currentDate->tm_mday;
            int currentHour = currentDate->tm_hour;
            Date x;
            x.Gio = currentHour;
            x.Ngay = currentDay;
            x.Thang = currentMonth;
            x.Nam = currentYear;
            KhachHang *kht = &((this->qlkh)[tt[k]]);
            HoaDon *hdt = &(this->qlkh.HoaDonTheoCCCDMaHD(kht->LayCCCD(),kht->LayMaHD()));
            if(SoSanhThoiGian(hdt->LayNgayDatPhong(),x))
            {
                for(int j = 0; j < k; ++j)
                {
                    KhachHang *t = &((this->qlkh)[tt[j]]);
                    HoaDon *hdtt = &((this->qlkh).HoaDonTheoCCCDMaHD(t->LayCCCD(),t->LayMaHD()));
                    KhachHang *t1 = &((this->qlkh)[tt[j+1]]);
                    HoaDon *hdtt1 = &((this->qlkh).HoaDonTheoCCCDMaHD(t1->LayCCCD(),t1->LayMaHD()));
                    hdtt->NhapNgayTraPhong(hdtt1->LayNgayDatPhong());
                    hdtt->NhapNgayThucTe(hdtt1->LayNgayDatPhong());
                    string str = hdtt->LayTenPhong();
                    int lp = this->qlp.XacDinhLoaiPhong(str);
                    long long giatien = 0;
                    if(lp == 1) giatien = this->qlp.LayThongTinPhongCoBan(str).LayGiaTien();
                    if(lp == 2) giatien = this->qlp.LayThongTinPhongThuong(str).LayGiaTien();
                    if(lp == 3) giatien = this->qlp.LayThongTinPhongThuongGia(str).LayGiaTien();
                    hdtt->TinhTienPhong(giatien);
                    t->TangSoLuong();
                    this->qlkh.NhapKhachHangVaoHashTable(t->LayCCCD(),0);
                }
                break;
            }
        }
    }
}
