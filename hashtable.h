#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <math.h>
#include "khachhang.h"
using namespace std;

class HashTable
{
private:
    long long SoNguyenTo;
    long long size;
    long long SoLuong;
    KhachHang *kh;
    int *kcg;
public:
    HashTable();
    HashTable(long long, long long);
    HashTable(long long, long long, KhachHang*, long long);
    HashTable(HashTable&);
    ~HashTable();
    void NhapDuLieu(long long, long long, KhachHang*, long long);
    bool KiemTraCoPhaiSoNguyenTo();
    void TimSoNguyenTo();
    void LaySoNguyenTo();
    long long hashing(long long);
    void KiemTraHeSoTai();
    void ReHashing();
    bool KiemTraViTri(int);
    void NhapKhachHangVaoHashTable(KhachHang&);
    void Table();
    KhachHang& operator [] (const int&);
    const HashTable& operator = (const HashTable&);
    void HienThiTable();
    void LuuKhachHangCuVaoFile();
    vector<KhachHang> LayDanhSachKhachHangCu();
    vector<KhachHang> LayDSKHTheoTTDSC(string, string, string);
};

#endif // HASHTABLE_H
