#ifndef KHACHHANG_H
#define KHACHHANG_H
#include "nguoi.h"
#include <vector>

class KhachHang : public Nguoi
{
private:
    string TenPhong;
    long long TongTien;
    vector<int> DichVu;
    Date NgayDen;
    Date NgayDi;
public:
    KhachHang();
    ~KhachHang();
    void NhapThongTinKhac(string, vector<int>, int, int, int, int);
    void NhapThongTinKhac(string, vector<int>, int, int, int, int, int, int, int, int, long long);
    void NhapThongTinKhac(string, vector<int>, int, int, int, int, int, int, int, int);
    void NhapNgayDatPhong(int, int, int, int);
    void NhapNgayTraPhong(int, int, int, int);
    void NhapNgayTraPhong2(Date);
    Date& LayNgayDatPhong();
    Date& LayNgayTraPhong();
    const KhachHang& operator = (const KhachHang&);
    void NhapPhongKhachHangDat(string);
    friend ostream& operator << (ostream&, const KhachHang&);
    bool KiemTraCCCD(string);
    bool KiemTraThongTinNhapVao();
    bool KiemTraCapNhatThoiGian();
    bool KiemTraPhongDuocDatChua(int, int, int, int, int, int, int, int);
    bool KiemTraQuaGioKhachHang();
    string LayTenPhong();
    vector<int> LayDichVu();
    void TangDichVu(int);
    void TinhTienPhong(long long);
    long long LayTienPhong();
    string LayNgayDen();
    string LayNgayDi();
};

#endif // KHACHHANG_H
