#ifndef PHONGTHUONGGIA_H
#define PHONGTHUONGGIA_H
#include "phongthuong.h"

class PhongThuongGia : public PhongThuong
{
private:
    static long long DichVuThuongGia;
    static long long GiaPhongThuongGia;
public:
    PhongThuongGia();
    PhongThuongGia(long long, long long);
    PhongThuongGia(string, bool, int, int);
    ~PhongThuongGia();
    static long long LayDVTG();
    static long long LayGTPTG();
    void NhapThongTinPhong(string, bool, int, int);
    void TinhTienPhong();
    const PhongThuongGia& operator = (const PhongThuongGia&);
    friend ostream& operator << (ostream&, const PhongThuongGia&);
};

#endif // PHONGTHUONGGIA_H
