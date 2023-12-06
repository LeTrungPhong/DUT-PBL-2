#ifndef QUANLY_H
#define QUANLY_H
#include "nguoi.h"
#include "quanlykhachhang.h"
#include "quanlyphong.h"

class QuanLy : public Nguoi
{
private:
    QuanLyPhong p;
    QuanLyKhachHang k;
public:
    QuanLy();
    ~QuanLy();
    void NhapThongTinChucNang(const QuanLyKhachHang&, const QuanLyPhong&);
    const QuanLy& operator = (const QuanLy&); // khong = qlkh, qlp

    bool KiemTraTenPhong(string);
    bool KiemTraPhongTrong(string);

    vector<KhachHang> LayDanhSachKhachHangMoi();
    vector<KhachHang> LayDanhSachKhachHangCu();
    vector<HoaDon> LayDSHDTheoTTDSC(string, string, string);
    vector<HoaDon> LayDSHDTheoTTDSM(string, string, string);
    vector<HoaDon> LayDSHD();
    vector<HoaDon> LayDSHDM();
    KhachHang& KhachHangCuTheoCCCD(string);

    int XacDinhLoaiPhong(string);
    PhongCoBan& LayThongTinPhongCoBan(string);
    PhongThuong& LayThongTinPhongThuong(string);
    PhongThuongGia& LayThongTinPhongThuongGia(string);

    void ThemPhong(const PhongCoBan&);
    void ThemPhong(const PhongThuong&);
    void ThemPhong(const PhongThuongGia&);

    void XoaPhong(string,int);

    void LayDuLieuTuFilePhong();
    void LayDuLieuTuFileKhachHangCu();
    void LayDuLieuTuFileHoaDon();
    void LayDuLieuTuFileKhachHangMoi();

    void LuuPhongVaoFile();
    void LuuKhachHangCuVaoFile();
    void LuuKhachHangMoiVaoFile();

};

#endif // QUANLY_H
