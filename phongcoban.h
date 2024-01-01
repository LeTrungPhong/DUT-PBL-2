#ifndef PHONGCOBAN_H
#define PHONGCOBAN_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PhongCoBan
{
protected:
    string TenPhong;
    bool TrongPhong;
    int GiuongDon;
    long long GiaPhong;
    static long long GiaTienGDon;
    static long long GiaPhongCoBan;
public:
    PhongCoBan();
    PhongCoBan(long long, long long);
    PhongCoBan(string, bool);
    PhongCoBan(string, bool, int);
    ~PhongCoBan();
    static long long LayGTGDon();
    static long long LayGTPCB();
    virtual void NhapThongTinPhong(string, bool);
    virtual void TinhTienPhong();
    const PhongCoBan& operator = (const PhongCoBan&);
    int KiemTraPhongTrong();
    void ChuyenTrangThaiPhong();
    void ChuyenTrangThaiPhongTrong();
    friend ostream& operator << (ostream&, const PhongCoBan&);
    int LayMaPhong();
    string LayTenPhong();
    int LaySoLuongGiuongDon();
    long long LayGiaTien();
    bool KiemTraPhongTheoChiDinh(int,int,int,long long,long long);
};

#endif // PHONGCOBAN_H
