#ifndef KHACHHANG_H
#define KHACHHANG_H
#include "nguoi.h"
#include <vector>

class KhachHang : public Nguoi
{
private:
    string MaHD;
//    string TenPhong;
//    long long TongTien;
//    vector<int> DichVu;
//    Date NgayDen;
//    Date NgayDi;
    int SoLuong;
public:
    KhachHang();
    ~KhachHang();
//    void NhapThongTinKhac(string, vector<int>, int, int, int, int);
//    void NhapThongTinKhac(string, vector<int>, int, int, int, int, int, int, int, int, int, long long);
//    void NhapThongTinKhac(string, string, vector<int>, int, int, int, int, int, int, int, int, int);
    void NhapThongTinKhac(string, int);
    void NhapMaHD(string);
//    void DatLaiThongTin();
//    void NhapNgayDatPhong(int, int, int, int);
//    void NhapNgayTraPhong(int, int, int, int);
//    void NhapNgayTraPhong2(Date);
//    Date& LayNgayDatPhong();
//    Date& LayNgayTraPhong();
    const KhachHang& operator = (const KhachHang&);
//    void NhapPhongKhachHangDat(string);
    friend ostream& operator << (ostream&, const KhachHang&);
    bool operator == (const KhachHang&);
    bool KiemTraCCCD(string);
    bool KiemTraThongTinNhapVao();
//    bool KiemTraCapNhatThoiGian();
//    bool KiemTraPhongDuocDatChua(int, int, int, int, int, int, int, int);
//    bool KiemTraQuaGioKhachHang();
    string LayTenPhong();
    vector<int> LayDichVu();
//    void TangDichVu(int);
//    void TinhTienPhong(long long);
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
