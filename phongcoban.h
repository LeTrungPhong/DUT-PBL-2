#ifndef PHONGCOBAN_H
#define PHONGCOBAN_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PhongCoBan
{
protected:
    // Ma Phong = Ten Phong //
    string TenPhong;
    bool TrongPhong;
    int GiuongDon;
    long long GiaPhong;
public:
    PhongCoBan();
    PhongCoBan(string, bool);
    PhongCoBan(string, bool, int);
    ~PhongCoBan();
    virtual void NhapThongTinPhong(string, bool);
    virtual void TinhTienPhong();
    virtual const PhongCoBan& operator = (const PhongCoBan&);
    int KiemTraPhongTrong();
    void ChuyenTrangThaiPhong();
    friend ostream& operator << (ostream&, const PhongCoBan&);
    int LayMaPhong();
    string LayTenPhong();
    int LaySoLuongGiuongDon();
    long long LayGiaTien();
    bool KiemTraPhongTheoChiDinh(int,int,int,long long,long long);
};

#endif // PHONGCOBAN_H
