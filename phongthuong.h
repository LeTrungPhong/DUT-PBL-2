#ifndef PHONGTHUONG_H
#define PHONGTHUONG_H
#include "phongcoban.h"

class PhongThuong : public PhongCoBan
{
protected:
    int GiuongDoi;
public:
    PhongThuong();
    PhongThuong(string, bool, int, int);
    ~PhongThuong();
    void NhapThongTinPhong(string, bool, int, int);
    void TinhTienPhong();
    const PhongThuong& operator = (const PhongThuong&);
    friend ostream& operator << (ostream&, const PhongThuong&);
    int LaySoLuongGiuongDoi();
    bool KiemTraPhongTheoChiDinh(int,int,int,int);
};

#endif // PHONGTHUONG_H
