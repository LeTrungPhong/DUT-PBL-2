#ifndef HOADON_H
#define HOADON_H
#include "khachhang.h"
using namespace std;

class HoaDon
{
private:
    string MaHD;
    string CCCD;
    string TenPhong;
    long long TongTien;
    vector<int> DichVu;
    Date NgayDen;
    Date NgayDi;
    Date NgayDiThucTe;
public:
    HoaDon();
    ~HoaDon();
    void NhapThongTin(string, string, vector<int>, const Date&, const Date&, const Date&, long long);
    void NhapThongTin(string, string, string, vector<int>, const Date&, const Date&, const Date&, long long);
    void NhapThongTin(const Date&, const Date&);
    void NhapTenPhong(string);
    void NhapCCCD(string);
    void NhapNgayThucTe(const Date&);
    void NhapNgayTraPhong(const Date&);
    bool operator == (const HoaDon&);
    const HoaDon& operator = (const HoaDon&);
    string LayCCCD();
    long long LayCCCD(int);
    vector<int> LayDichVu();
    string LaySDT();
    string LayTenPhong();
    string LayNgayDen();
    string LayNgayDi();
    string LayNgayDiThucTe();
    long long LayTienPhong();
    string LayTen();
    string LayBirth();
    int LaySoLuong();
    void TaoMaHD();
    string LayMaHD();
    void TinhTienPhong(long long);
    void TangDichVu(int);
    Date& LayNgayDatPhong();
    Date& LayNgayTraPhong();

    bool KiemTraCapNhatThoiGian();
};

#endif // HOADON_H
