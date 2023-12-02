#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <math.h>
#include "khachhang.h"
#include "hoadon.h"
using namespace std;

template<class T>
class HashTable
{
private:
    long long SoNguyenTo;
    long long size;
    long long SoLuong;
    T *kh;
    int *kcg;
public:
    HashTable();
    HashTable(long long, long long);
    HashTable(long long, long long, T*, long long);
    HashTable(HashTable&);
    ~HashTable();
    void NhapDuLieu(long long, long long, T*, long long);
    bool KiemTraCoPhaiSoNguyenTo();
    void TimSoNguyenTo();
    void LaySoNguyenTo();
    long long hashing(long long);
    void KiemTraHeSoTai();
    void ReHashing();
    bool KiemTraViTri(int);
    void NhapDuLieuVaoHashTable(T&);
    void XoaKhachHang(string);
    bool KiemTraDuLieuCu(T&);
    bool KiemTraThongTin(T&);
    void Table();
    T& operator [] (const int&);
    const HashTable& operator = (const HashTable&);
    void HienThiTable();
    void LuuHoaDonVaoFile();
    void LuuKhachHangCuVaoFile();
    T& LayThongTinTheoID(string);
    T& LayThongTinTheoID(string, string);
    vector<T> LayDanhSachKhachHangCu();
    vector<T> LayDSKHTheoTTDSC(string, string, string);
};

#endif // HASHTABLE_H
