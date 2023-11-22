#ifndef QUANLY_H
#define QUANLY_H
#include "tieptan.h"

class QuanLy : public Nguoi
{
private:
    string TaiKhoan;
    string MatKhau;
    TiepTan *tt;
    int size;
    QuanLyPhong p;
    QuanLyKhachHang k;
public:
    QuanLy();
    ~QuanLy();
    void NhapDuLieuQuanLy(string, string, int, TiepTan*);
    void NhapThongTinChucNang(const QuanLyKhachHang&, const QuanLyPhong&);
    const QuanLy& operator = (const QuanLy&); // khong = qlkh, qlp
    bool KiemTraTiepTanDangNhap(string, string);
    TiepTan& LayThongTinTiepTan(string, string);
    bool KiemTraQuanLyDangNhap(string, string);
    vector<KhachHang> LayDanhSachKhachHangMoi();
    vector<KhachHang> LayDanhSachKhachHangCu();
    vector<KhachHang> LayDSKHTheoTTDSC(string, string, string);
    vector<KhachHang> LayDSKHTheoTTDSM(string, string, string);
};

#endif // QUANLY_H
