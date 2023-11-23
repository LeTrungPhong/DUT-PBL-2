#ifndef QUANLY_H
#define QUANLY_H
#include "tieptan.h"

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
    vector<KhachHang> LayDanhSachKhachHangMoi();
    vector<KhachHang> LayDanhSachKhachHangCu();
    vector<KhachHang> LayDSKHTheoTTDSC(string, string, string);
    vector<KhachHang> LayDSKHTheoTTDSM(string, string, string);
};

#endif // QUANLY_H
