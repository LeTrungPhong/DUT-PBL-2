#ifndef QUANLYPHONG_H
#define QUANLYPHONG_H
#include "phongthuonggia.h"

class QuanLyPhong
{
private:
    PhongCoBan *pcb;
    PhongThuong *pt;
    PhongThuongGia *ptg;
    vector<int> size;
public:
    QuanLyPhong();
    QuanLyPhong(int, int, int, PhongCoBan*, PhongThuong*, PhongThuongGia*);
    QuanLyPhong(QuanLyPhong&);
    ~QuanLyPhong();

    bool KiemTraTenPhong(string);
    bool KiemTraPhongTrong(string);
    void ChuyenTrangThaiPhong(string);

    bool KiemTraPhongTrong(PhongCoBan&);
    void ChuyenTrangThaiPhong(PhongCoBan&);
    bool KiemTraPhongTrong(PhongThuong&);
    void ChuyenTrangThaiPhong(PhongThuong&);
    bool KiemTraPhongTrong(PhongThuongGia&);
    void ChuyenTrangThaiPhong(PhongThuongGia&);
    void HienThiPhong();

    //// còn sai
    void ThemPhongCoBan(const PhongCoBan&);
    void ThemPhongThuong(const PhongThuong&);
    void ThemPhongThuongGia(const PhongThuongGia&);
    ///

    const QuanLyPhong& operator = (const QuanLyPhong&);

    vector<string> LayTenCacPhong(int,int,int,int, long long, long long);

    int XacDinhLoaiPhong(string);
    PhongCoBan& LayThongTinPhongCoBan(string);
    PhongThuong& LayThongTinPhongThuong(string);
    PhongThuongGia& LayThongTinPhongThuongGia(string);

    void LuuPhongVaoFile();
};

#endif // QUANLYPHONG_H
