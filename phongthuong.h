#ifndef PHONGTHUONG_H
#define PHONGTHUONG_H
#include "phongcoban.h"

class PhongThuong : public PhongCoBan
{
protected:
    int GiuongDoi;
    static long long GiaTienGDoi;
    static long long GiaPhongThuong;
public:
    PhongThuong();
    PhongThuong(long long, long long);
    PhongThuong(string, bool, int, int);
    ~PhongThuong();
    static long long LayGTGDoi();
    static long long LayGTPT();
    void NhapThongTinPhong(string, bool, int, int);
    void TinhTienPhong();
    const PhongThuong& operator = (const PhongThuong&);
    friend ostream& operator << (ostream&, const PhongThuong&);
    int LaySoLuongGiuongDoi();
    bool KiemTraPhongTheoChiDinh(int,int,int,long long,long long);
    void DatLaiSoGiuongDon(int);
    void DatLaiSoGiuongDoi(int);
};

#endif // PHONGTHUONG_H
