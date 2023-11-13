#ifndef PHONGTHUONGGIA_H
#define PHONGTHUONGGIA_H
#include "phongthuong.h"

class PhongThuongGia : public PhongThuong
{
private:
         //
public:
    PhongThuongGia();
    PhongThuongGia(string, bool, int, int);
    ~PhongThuongGia();
    void NhapThongTinPhong(string, bool, int, int);
    void TinhTienPhong();
    const PhongThuongGia& operator = (const PhongThuongGia&);
    friend ostream& operator << (ostream&, const PhongThuongGia&);
};

#endif // PHONGTHUONGGIA_H
