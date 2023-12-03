#include "quanlykhachhang.h"
#include <fstream>

QuanLyKhachHang::QuanLyKhachHang()
{
    this->size = 1;
    this->kh = new KhachHang[this->size];
}

QuanLyKhachHang::QuanLyKhachHang(int s)
{
    this->size = s;
    this->kh = new KhachHang[this->size];
}

QuanLyKhachHang::QuanLyKhachHang(HashTable<KhachHang> &t, int s)
    :htb(t)
{
    this->size = s;
    this->kh = new KhachHang[this->size];
}

QuanLyKhachHang::QuanLyKhachHang(KhachHang *temp, HashTable<KhachHang> &t, int s)
    :htb(t)
{
    this->size = s;
    this->kh = new KhachHang[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kh + i) = *(temp + i);
    }
}

bool QuanLyKhachHang::KiemTraPhongBaoTri(string str)
{
    for(int i = 0; i < this->size; ++i)
    {
        KhachHang *k = &(*(this->kh + i));
        HoaDon *hd = &(this->htb1.LayThongTinTheoID(k->LayCCCD(),k->LayMaHD()));
        if(str == hd->LayTenPhong())
        {
            return true;
        }
    }
    return false;
}

bool QuanLyKhachHang::KiemTraKhachHangDatPhong(string str)
{
    for(int i = 0; i < this->size; ++i)
    {
        if(str == (this->kh + i)->LayCCCD())
        {
            return true;
        }
    }
    return false;
}

bool QuanLyKhachHang::KiemTraPhongDuocDatChua(string str, int gioden, int ngayden, int thangden, int namden, int giodi, int ngaydi, int thangdi, int namdi)
{
    for(int i = 0; i < this->size; ++i)
    {
        KhachHang *k = &(*(this->kh + i));
        HoaDon *hd = &(this->htb1.LayThongTinTheoID(k->LayCCCD(),k->LayMaHD()));
        if(hd->LayTenPhong() == str)
        {
            if(!(hd->KiemTraPhongDuocDatChua(gioden,ngayden,thangden,namden,giodi,ngaydi,thangdi,namdi))) return false;
        }
    }
    return true;
}

bool QuanLyKhachHang::KiemTraKhachHangCu(KhachHang &k)
{
    return this->htb.KiemTraDuLieuCu(k);
}

bool QuanLyKhachHang::KiemTraThongTin(KhachHang &k)
{
    return this->htb.KiemTraThongTin(k);
}

void QuanLyKhachHang::NhapDuLieu(KhachHang *temp, HashTable<KhachHang> &t, int s, HashTable<HoaDon> &h)
{
    this->htb = t;
    this->htb1 = h;
    this->size = s;
    this->kh = new KhachHang[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kh + i) = *(temp + i);
    }
}

QuanLyKhachHang::QuanLyKhachHang(QuanLyKhachHang &k)
{
    this->size = k.size;
    this->htb = k.htb;
    this->kh = new KhachHang[this->size];
    for(int i = 0; i < this->size; i++)
    {
        *(this->kh + i) = *(k.kh + i);
    }
}

QuanLyKhachHang::~QuanLyKhachHang()
{
    delete[] this->kh;
}

void QuanLyKhachHang::NhapKhachHangMoi(const KhachHang &k)
{
    for(int i = 0; i < this->size; i++)
    {
        if(((this->kh + i)->LayCCCD() == "0"))
        {
            *(this->kh + i) = k;
            return;
        }
    }
}

void QuanLyKhachHang::NhapKhachHangVaoHashTable(string CCCD, int check)
{
    int k = -1;
    for(int i = 0; i < this->size; i++)
    {
        if(CCCD == (this->kh + i)->LayCCCD())
        {
            k = i;
            break;
        }
    }
    if(k < 0) return;
    KhachHang temp;
    this->htb.NhapDuLieuVaoHashTable(*(this->kh + k),check);
    *(this->kh + k) = temp;
}

void QuanLyKhachHang::NhapHoaDonVaoHashTable(HoaDon hd, int check)
{
    this->htb1.NhapDuLieuVaoHashTable(hd,check);
}

void QuanLyKhachHang::HienThiThongTinKhachHang()
{
    for(int i = 0; i < this->size; i++)
    {
        cout << *(this->kh + i);
    }
}

KhachHang& QuanLyKhachHang::KhachHangTheoPhongTime(string tp)
{
    for(int i = 0; i < this->size; i++)
    {
        bool check = false;
        time_t now = time(0);
        tm* currentDate = localtime(&now);
        int currentYear = currentDate->tm_year + 1900;
        int currentMonth = currentDate->tm_mon + 1;
        int currentDay = currentDate->tm_mday;
        int currentHour = currentDate->tm_hour;
        KhachHang *k = &(*(this->kh + i));
        HoaDon *hd = &(this->htb1.LayThongTinTheoID(k->LayCCCD(),k->LayMaHD()));
        Date nden = hd->LayNgayDatPhong();
        int gioden = nden.Gio;
        int ngayden = nden.Ngay;
        int thangden = nden.Thang;
        int namden = nden.Nam;

        if(currentYear < namden) check = true;
        if(currentYear == namden && currentMonth < thangden) check = true;
        if(currentYear == namden && currentMonth == thangden && currentDay < ngayden) check = true;
        if(currentYear == namden && currentMonth == thangden && currentDay == ngayden && currentHour < gioden) check = true;
        if(check)
        {
            continue;
        }
        if(hd->LayTenPhong() == tp)
        {
            return *(this->kh + i);
        }
    }
    KhachHang k;
    return k;
}

KhachHang& QuanLyKhachHang::KhachHangTheoPhong(string tp)
{
    for(int i = 0; i < this->size; i++)
    {
        if((this->kh + i)->LayTenPhong() == tp)
        {
            return *(this->kh + i);
        }
    }
    KhachHang k;
    return k;
}

KhachHang& QuanLyKhachHang::KhachHangCuTheoCCCD(string cccd)
{
    return this->htb.LayThongTinTheoID(cccd);
}

HoaDon& QuanLyKhachHang::HoaDonTheoCCCDMaHD(string cccd, string mahd)
{
    return this->htb1.LayThongTinTheoID(cccd,mahd);
}

void QuanLyKhachHang::HienThiTable()
{
    htb.HienThiTable();
}

const QuanLyKhachHang& QuanLyKhachHang::operator = (const QuanLyKhachHang &qlkh)
{
    if(this != &qlkh)
    {
        this->htb = qlkh.htb;
        this->htb1 = qlkh.htb1;
        this->size = qlkh.size;
        this->kh = new KhachHang[this->size];
        for(int i = 0; i < this->size; ++i)
        {
            *(this->kh + i) = *(qlkh.kh + i);
        }
    }
    return *this;
}

void QuanLyKhachHang::TangDichVu(int k, string str)
{
    for(int i = 0; i < this->size; i++)
    {
        bool check = false;
        time_t now = time(0);
        tm* currentDate = localtime(&now);
        int currentYear = currentDate->tm_year + 1900;
        int currentMonth = currentDate->tm_mon + 1;
        int currentDay = currentDate->tm_mday;
        int currentHour = currentDate->tm_hour;
        KhachHang *ktemp = &(*(this->kh + i));
        HoaDon *hd = &(this->htb1.LayThongTinTheoID(ktemp->LayCCCD(),ktemp->LayMaHD()));
        Date nden = hd->LayNgayDatPhong();
        int gioden = nden.Gio;
        int ngayden = nden.Ngay;
        int thangden = nden.Thang;
        int namden = nden.Nam;

        if(currentYear < namden) check = true;
        if(currentYear == namden && currentMonth < thangden) check = true;
        if(currentYear == namden && currentMonth == thangden && currentDay < ngayden) check = true;
        if(currentYear == namden && currentMonth == thangden && currentDay == ngayden && currentHour < gioden) check = true;
        if(check)
        {
            continue;
        }
        if(str == hd->LayTenPhong())
        {
            hd->TangDichVu(k);
            return;
        }
    }
    return;
}

void QuanLyKhachHang::LuuKhachHangCuVaoFile()
{
    (this->htb).LuuKhachHangCuVaoFile();
}

void QuanLyKhachHang::LuuKhachHangMoiVaoFile()
{
    ofstream outfile("D:\\HK3\\PBL-Project-3\\Khach_Hang_Moi.txt");
    outfile << this->size << endl;
    for(int i = 0; i < this->size; ++i)
    {
        vector<int> v = (this->kh + i)->LayDichVu();
        outfile << (this->kh + i)->LayMaHD() << "|" << (this->kh + i)->LayCCCD() << "|" << (this->kh + i)->LaySDT() << "|" << (this->kh + i)->LayBirth() << "|" << (this->kh + i)->LaySoLuong() << "|" << (this->kh + i)->LayTen() << endl;
    }
    outfile.close();
}

void QuanLyKhachHang::LuuHoaDonVaoFile()
{
    (this->htb1).LuuHoaDonVaoFile();
}

int QuanLyKhachHang::LaySoLuong()
{
    return this->size;
}

void QuanLyKhachHang::LayKhachHanghtb(string cccd)
{
    return this->htb.XoaKhachHang(cccd);
}

KhachHang& QuanLyKhachHang::operator[](const int& index)
{
    static KhachHang NGU;
    return(index >= 0 && index < this->size)?*(this->kh + index):NGU;
}

vector<KhachHang> QuanLyKhachHang::LayDanhSachKhachHangMoi()
{
    vector<KhachHang> temp;
    for(int i = 0; i < this->size; ++i)
    {
        if((this->kh + i)->LayCCCD() != "0")
        {
            temp.push_back(*(this->kh + i));
        }
    }
    return temp;
}

vector<KhachHang> QuanLyKhachHang::LayDanhSachKhachHangCu()
{
    return this->htb.LayDanhSachKhachHangCu();
}

vector<KhachHang> QuanLyKhachHang::LayDSKHTheoTTDSM(string cccd, string tenphong, string tenkh)
{
    vector<KhachHang> temp;
    for(int i = 0; i < this->size; ++i)
    {
        if(!(((this->kh + i)->LayCCCD() == cccd || cccd == "") && (this->kh + i)->LayCCCD() != "0")) continue;
        if(!(((this->kh + i)->LayTenPhong() == tenphong || tenphong == "") && (this->kh + i)->LayTenPhong() != "0")) continue;
        if(!(((this->kh + i)->LayTen() == tenkh || tenkh == "") && (this->kh + i)->LayTen() != "0")) continue;
        temp.push_back(*(this->kh + i));
    }
    return temp;
}

vector<KhachHang> QuanLyKhachHang::LayDSKHTheoTTDSC(string cccd, string tenphong, string tenkh)
{
    return this->htb.LayDSKHTheoTTDSC(cccd,tenphong,tenkh);
}
