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
};

#endif // QUANLYKHACHHANG_H
