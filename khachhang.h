#ifndef KHACHHANG_H
#define KHACHHANG_H
#include "nguoi.h"
#include <vector>

class KhachHang : public Nguoi
{
private:
    string MaHD;
    int SoLuong;
public:
    KhachHang();
    ~KhachHang();
    void NhapThongTinKhac(string, int);
    void NhapMaHD(string);
    const KhachHang& operator = (const KhachHang&);
    friend ostream& operator << (ostream&, const KhachHang&);
    bool operator == (const KhachHang&);
    bool KiemTraCCCD(string);
    bool KiemTraThongTinNhapVao();
    string LayTenPhong();
    vector<int> LayDichVu();
    long long LayTienPhong();
    int LaySoLuong();
    void NhapSoLuong(int);
    void TangSoLuong();
    string LayNgayDen();
    string LayNgayDi();
    string LayNgayDiThucTe();
    string LayMaHD();
};

#endif // KHACHHANG_H
