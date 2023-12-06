#ifndef QUANLYPHONG_H
#define QUANLYPHONG_H
#include "phongthuonggia.h"
#include "khachhang.h"

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

    void NhapThongTinPhong(int, int, int, PhongCoBan*, PhongThuong*, PhongThuongGia*);
    bool KiemTraTenPhong(string);
    bool KiemTraPhongTrong(string);
    void ChuyenTrangThaiPhong(string);

    void HienThiPhong();

    //// còn sai
    void ThemPhong(const PhongCoBan&);
    void ThemPhong(const PhongThuong&);
    void ThemPhong(const PhongThuongGia&);

    void XoaPhong(string,int);
    ///

    const QuanLyPhong& operator = (const QuanLyPhong&);

    vector<string> LayTenCacPhong(int,int,int,int, long long, long long);

    int XacDinhLoaiPhong(string);
    PhongCoBan& LayThongTinPhongCoBan(string);
    PhongThuong& LayThongTinPhongThuong(string);
    PhongThuongGia& LayThongTinPhongThuongGia(string);

    void LayDuLieuTuFilePhong();
    void LuuPhongVaoFile();
};

#endif // QUANLYPHONG_H
