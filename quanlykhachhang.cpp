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

QuanLyKhachHang::QuanLyKhachHang(HashTable &t, int s)
    :htb(t)
{
    this->size = s;
    this->kh = new KhachHang[this->size];
}

QuanLyKhachHang::QuanLyKhachHang(KhachHang *temp, HashTable &t, int s)
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
        if(str == (this->kh + i)->LayTenPhong())
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
        if((this->kh + i)->LayTenPhong() == str)
        {
            if(!((this->kh + i)->KiemTraPhongDuocDatChua(gioden,ngayden,thangden,namden,giodi,ngaydi,thangdi,namdi))) return false;
        }
    }
    return true;
}

void QuanLyKhachHang::NhapDuLieu(KhachHang *temp, HashTable &t, int s)
{
    this->htb = t;
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
        if(((this->kh + i)->LayTenPhong() == "0"))
        {
            *(this->kh + i) = k;
            return;
        }
    }
}

void QuanLyKhachHang::NhapKhachHangVaoHashTable(string CCCD)
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
    htb.NhapKhachHangVaoHashTable(*(this->kh + k));
    *(this->kh + k) = temp;
}

void QuanLyKhachHang::HienThiThongTinKhachHang()
{
    for(int i = 0; i < this->size; i++)
    {
        cout << *(this->kh + i);
    }
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

void QuanLyKhachHang::HienThiTable()
{
    htb.HienThiTable();
}

const QuanLyKhachHang& QuanLyKhachHang::operator = (const QuanLyKhachHang &qlkh)
{
    if(this != &qlkh)
    {
        this->htb = qlkh.htb;
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
        if(str == (this->kh + i)->LayTenPhong())
        {
            (this->kh + i)->TangDichVu(k);
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
        outfile << (this->kh + i)->LayCCCD() << "|" << (this->kh + i)->LaySDT() << "|" << (this->kh + i)->LayTenPhong() << "|" << (this->kh + i)->LayBirth() << "|" << (this->kh + i)->LayNgayDen() << "|" << (this->kh + i)->LayNgayDi() << "|" << v[0] << "|" << v[1] << "|" << v[2] << "|" << v[3] << "|" << (this->kh + i)->LayTen() << endl;
    }
    outfile.close();
}

int QuanLyKhachHang::LaySoLuong()
{
    return this->size;
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
