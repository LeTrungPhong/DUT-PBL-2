#ifndef HOADON_H
#define HOADON_H
#include "khachhang.h"
using namespace std;

class HoaDon
{
private:
    string CCCD;
    string TenPhong;
    long long TongTien;
    vector<int> DichVu;
    Date NgayDen;
    Date NgayDi;
public:
    HoaDon();
    ~HoaDon();
    void NhapThongTin(string, string, vector<int>, const Date&, const Date&, long long);
    bool operator == (const HoaDon&);
    string LayCCCD();
    long long LayCCCD(int);
    vector<int> LayDichVu();
    string LaySDT();
    string LayTenPhong();
    string LayNgayDen();
    string LayNgayDi();
    long long LayTienPhong();
    string LayTen();
    string LayBirth();
};

#endif // HOADON_H
