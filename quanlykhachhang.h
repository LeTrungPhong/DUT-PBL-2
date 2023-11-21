#ifndef QUANLYKHACHHANG_H
#define QUANLYKHACHHANG_H
#include <iostream>
#include "hashtable.h"
using namespace std;

class QuanLyKhachHang
{
private:
    HashTable htb;
    KhachHang *kh;
    int size;
public:
    QuanLyKhachHang();
    QuanLyKhachHang(int);
    QuanLyKhachHang(HashTable&, int);
    QuanLyKhachHang(KhachHang*, HashTable&, int);
    QuanLyKhachHang(QuanLyKhachHang&);
    ~QuanLyKhachHang();

    bool KiemTraPhongBaoTri(string);
    bool KiemTraKhachHangDatPhong(string);
    bool KiemTraPhongDuocDatChua(string, int, int, int, int, int, int, int, int);

    void NhapDuLieu(KhachHang*, HashTable&, int);

    void NhapKhachHangMoi(const KhachHang&);
    void NhapKhachHangVaoHashTable(string);
    void HienThiThongTinKhachHang();
    KhachHang& KhachHangTheoPhong(string);
    void HienThiTable();
    const QuanLyKhachHang& operator = (const QuanLyKhachHang&);
    void TangDichVu(int,string);

    void LuuKhachHangCuVaoFile();
    void LuuKhachHangMoiVaoFile();
    int LaySoLuong();
    KhachHang& operator [] (const int&);    
};

#endif // QUANLYKHACHHANG_H
