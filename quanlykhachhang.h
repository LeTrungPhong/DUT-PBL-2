#ifndef QUANLYKHACHHANG_H
#define QUANLYKHACHHANG_H
#include <iostream>
#include "hashtable.h"
using namespace std;

class QuanLyKhachHang
{
private:
    HashTable<KhachHang> htb;
    HashTable<HoaDon> htb1;
    KhachHang *kh;
    int size;
public:
    QuanLyKhachHang();
    QuanLyKhachHang(int);
    QuanLyKhachHang(HashTable<KhachHang>&, int);
    QuanLyKhachHang(KhachHang*, HashTable<KhachHang>&, int);
    QuanLyKhachHang(QuanLyKhachHang&);
    ~QuanLyKhachHang();

    bool KiemTraPhongBaoTri(string);
    bool KiemTraKhachHangDatPhong(string);
    bool KiemTraPhongDuocDatChua(string, int, int, int, int, int, int, int, int);
    bool KiemTraKhachHangCu(KhachHang&);
    bool KiemTraThongTin(KhachHang&);
    bool KiemTraSDT(string, string);

    void NhapDuLieu(KhachHang*, HashTable<KhachHang>&, int, HashTable<HoaDon>&);

    void NhapKhachHangMoi(const KhachHang&);
    void NhapKhachHangVaoHashTable(string,int);
    void NhapHoaDonVaoHashTable(HoaDon,int);
    void HienThiThongTinKhachHang();
    KhachHang& KhachHangTheoPhong(string);
    KhachHang& KhachHangTheoPhongTime(string);
    KhachHang& KhachHangCuTheoCCCD(string);
    HoaDon& HoaDonTheoCCCDMaHD(string, string);
    void HienThiTable();
    const QuanLyKhachHang& operator = (const QuanLyKhachHang&);
    void TangDichVu(int,string);

    void LayDuLieuTuFileKhachHangCu();
    void LayDuLieuTuFileHoaDon();
    void LayDuLieuTuFileKhachHangMoi();

    void LuuKhachHangCuVaoFile();
    void LuuKhachHangMoiVaoFile();
    void LuuHoaDonVaoFile();
    void LayKhachHanghtb(string);
    int LaySoLuong();
    KhachHang& operator [] (const int&);

    vector<KhachHang> LayDanhSachKhachHangMoi();
    vector<KhachHang> LayDanhSachKhachHangCu();
    vector<HoaDon> LayDSHDTheoTTDSM(string, string, string);
    vector<HoaDon> LayDSHDTheoTTDSC(string, string, string);
    vector<HoaDon> LayDSHD();
    vector<HoaDon> LayDSHDM();

    vector<string> split(string,string);
};

#endif // QUANLYKHACHHANG_H
