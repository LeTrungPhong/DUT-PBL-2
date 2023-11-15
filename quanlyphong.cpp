#include "quanlyphong.h"
#include <fstream>

QuanLyPhong::QuanLyPhong()
{ }

QuanLyPhong::QuanLyPhong(int s1, int s2, int s3, PhongCoBan* p1, PhongThuong* p2, PhongThuongGia* p3)
{
    size.push_back(s1);
    size.push_back(s2);
    size.push_back(s3);
    this->pcb = new PhongCoBan[size[0]];
    this->pt = new PhongThuong[size[1]];
    this->ptg = new PhongThuongGia[size[2]];
    for(int i = 0; i < size[0]; i++)
    {
        *(this->pcb + i) = *(p1 + i);
    }
    delete[] p1;
    for(int i = 0; i < size[1]; i++)
    {
        *(this->pt + i) = *(p2 + i);
    }
    delete[] p2;
    for(int i = 0; i < size[2]; i++)
    {
        *(this->ptg + i) = *(p3 + i);
    }
    delete[] p3;
}

QuanLyPhong::QuanLyPhong(QuanLyPhong &qlp)
{
    this->size.resize(3);
    this->size[0] = qlp.size[0];
    this->size[1] = qlp.size[1];
    this->size[2] = qlp.size[2];
    this->pcb = new PhongCoBan[size[0]];
    for(int i = 0; i < size[0]; i++)
    {
        *(this->pcb + i) = *(qlp.pcb + i);
    }
    this->pt = new PhongThuong[size[1]];
    for(int i = 0; i < size[1]; i++)
    {
        *(this->pt + i) = *(qlp.pt + i);
    }
    this->ptg = new PhongThuongGia[size[2]];
    for(int i = 0; i < size[2]; i++)
    {
        *(this->ptg + i) = *(qlp.ptg + i);
    }
}

QuanLyPhong::~QuanLyPhong()
{
    delete[] this->pcb;
    delete[] this->pt;
    delete[] this->ptg;
}

bool QuanLyPhong::KiemTraTenPhong(string str)
{
    for(int i = 0; i < this->size[0]; i++)
    {
        if(str == (this->pcb + i)->LayTenPhong())
        {
            return true;
        }
    }
    for(int i = 0; i < this->size[1]; i++)
    {
        if(str == (this->pt + i)->LayTenPhong())
        {
            return true;
        }
    }
    for(int i = 0; i < this->size[2]; i++)
    {
        if(str == (this->ptg + i)->LayTenPhong())
        {
            return true;
        }
    }
    return false;
}

bool QuanLyPhong::KiemTraPhongTrong(string str)
{
    for(int i = 0; i < this->size[0]; i++)
    {
        if(str == (this->pcb + i)->LayTenPhong())
        {
            return (this->pcb + i)->KiemTraPhongTrong();
        }
    }
    for(int i = 0; i < this->size[1]; i++)
    {
        if(str == (this->pt + i)->LayTenPhong())
        {
            return (this->pt + i)->KiemTraPhongTrong();
        }
    }
    for(int i = 0; i < this->size[2]; i++)
    {
        if(str == (this->ptg + i)->LayTenPhong())
        {
            return (this->ptg + i)->KiemTraPhongTrong();
        }
    }
    return false;
}

void QuanLyPhong::ChuyenTrangThaiPhong(string str)
{
    for(int i = 0; i < this->size[0]; i++)
    {
        if(str == (this->pcb + i)->LayTenPhong())
        {
            (this->pcb + i)->ChuyenTrangThaiPhong();
            return;
        }
    }
    for(int i = 0; i < this->size[1]; i++)
    {
        if(str == (this->pt + i)->LayTenPhong())
        {
            (this->pt + i)->ChuyenTrangThaiPhong();
            return;
        }
    }
    for(int i = 0; i < this->size[2]; i++)
    {
        if(str == (this->ptg + i)->LayTenPhong())
        {
            (this->ptg + i)->ChuyenTrangThaiPhong();
            return;
        }
    }
}

bool QuanLyPhong::KiemTraPhongTrong(PhongCoBan &p)
{
    return p.KiemTraPhongTrong();
}

void QuanLyPhong::ChuyenTrangThaiPhong(PhongCoBan &p)
{
    p.ChuyenTrangThaiPhong();
}

bool QuanLyPhong::KiemTraPhongTrong(PhongThuong &p)
{
    return p.KiemTraPhongTrong();
}

void QuanLyPhong::ChuyenTrangThaiPhong(PhongThuong &p)
{
    p.ChuyenTrangThaiPhong();
}

bool QuanLyPhong::KiemTraPhongTrong(PhongThuongGia &p)
{
    return p.KiemTraPhongTrong();
}

void QuanLyPhong::ChuyenTrangThaiPhong(PhongThuongGia &p)
{
    p.ChuyenTrangThaiPhong();
}

void QuanLyPhong::HienThiPhong()
{
    for(int i = 0; i < this->size[0]; i++)
    {
        cout << *(this->pcb + i);
    }
    for(int i = 0; i < this->size[1]; i++)
    {
        cout << *(this->pt + i);
    }
    for(int i = 0; i < this->size[2]; i++)
    {
        cout << *(this->ptg + i);
    }
}

void QuanLyPhong::ThemPhongCoBan(const PhongCoBan &th)
{
    PhongCoBan *p = new PhongCoBan[this->size[0]];
    for(int i = 0; i < this->size[0]; i++)
    {
        *(p + i) = *(this->pcb + i);
    }
    delete[] this->pcb;
    this->size[0]++;
    this->pcb = new PhongCoBan[this->size[0]];
    for(int i = 0; i < this->size[0] - 1; i++)
    {
        *(this->pcb + i) = *(p + i);
    }
    *(this->pcb + (this->size[0] - 1)) = th;
    delete[] p;
}

void QuanLyPhong::ThemPhongThuong(const PhongThuong &th)
{
    PhongThuong *p = new PhongThuong[this->size[1]];
    for(int i = 0; i < this->size[1]; i++)
    {
        *(p + i) = *(this->pt + i);
    }
    delete[] this->pt;
    this->size[1]++;
    this->pt = new PhongThuong[this->size[1]];
    for(int i = 0; i < this->size[1] - 1; i++)
    {
        *(this->pt + i) = *(p + i);
    }
    *(this->pt + (this->size[1] - 1)) = th;
    delete[] p;
}

void QuanLyPhong::ThemPhongThuongGia(const PhongThuongGia &th)
{
    PhongThuongGia *p = new PhongThuongGia[this->size[2]];
    for(int i = 0; i < this->size[2]; i++)
    {
        *(p + i) = *(this->ptg + i);
    }
    delete[] this->ptg;
    this->size[2]++;
    this->ptg = new PhongThuongGia[this->size[2]];
    for(int i = 0; i < this->size[2] - 1; i++)
    {
        *(this->ptg + i) = *(p + i);
    }
    *(this->ptg + (this->size[2] - 1)) = th;
    delete[] p;
}

const QuanLyPhong& QuanLyPhong::operator = (const QuanLyPhong& qlp)
{
    if(this != &qlp)
    {
        this->size.resize(3);
        this->size[0] = qlp.size[0];
        this->size[1] = qlp.size[1];
        this->size[2] = qlp.size[2];
        this->pcb = new PhongCoBan[size[0]];
        for(int i = 0; i < size[0]; i++)
        {
            *(this->pcb + i) = *(qlp.pcb + i);
        }
        this->pt = new PhongThuong[size[1]];
        for(int i = 0; i < size[1]; i++)
        {
            *(this->pt + i) = *(qlp.pt + i);
        }
        this->ptg = new PhongThuongGia[size[2]];
        for(int i = 0; i < size[2]; i++)
        {
            *(this->ptg + i) = *(qlp.ptg + i);
        }
    }
    return *this;
}

vector<string> QuanLyPhong::LayTenCacPhong(int a, int b, int d, int e, long long f, long long g)
{
    vector<string> v;
    // a giường đơn // 0: mặc định / 1:1 / 2:2
    // b giường đôi // 0: mặc định / 1:1 / 2:2
    // c tầng       // 0: mặc định / 1:1 / 2:2 ....
    // d loại phòng // 0: mặc định / 1: phòng cơ bản / 2: phòng thường / 3: phòng thương gia
    // e tình trạng // 0: mặc định / 1: trống / 2: không trống

    if(d == 0 || d == 1)
    {
        for(int i = 0; i < this->size[0]; i++)
        {
            if(!((pcb + i)->KiemTraPhongTheoChiDinh(a,b,e,f,g)))
            {
                continue;
            }
            v.push_back((pcb + i)->LayTenPhong());
        }
    }
    if(d == 0 || d == 2)
    {
        for(int i = 0; i < this->size[1]; i++)
        {
            if(!((pt + i)->KiemTraPhongTheoChiDinh(a,b,e,f,g)))
            {
                continue;
            }
            v.push_back((pt + i)->LayTenPhong());
        }
    }
    if(d == 0 || d == 3)
    {
        for(int i = 0; i < this->size[2]; i++)
        {
            if(!((ptg + i)->KiemTraPhongTheoChiDinh(a,b,e,f,g)))
            {
                continue;
            }
            v.push_back((ptg + i)->LayTenPhong());
        }
    }
    return v;
}

vector<string> QuanLyPhong::LayTenCacPhong2(KhachHang &k, long long min, long long max)
{
    vector<string> temp;
    for(int i = 0; i < this->size[0]; ++i)
    {
        k.TinhTienPhong((this->pcb + i)->LayGiaTien());
        if(k.LayTienPhong() >= min && k.LayTienPhong() <= max)
        {
            temp.push_back((this->pcb + i)->LayTenPhong());
        }
    }
    for(int i = 0; i < this->size[1]; ++i)
    {
        k.TinhTienPhong((this->pt + i)->LayGiaTien());
        if(k.LayTienPhong() >= min && k.LayTienPhong() <= max)
        {
            temp.push_back((this->pt + i)->LayTenPhong());
        }
    }
    for(int i = 0; i < this->size[2]; ++i)
    {
        k.TinhTienPhong((this->ptg + i)->LayGiaTien());
        if(k.LayTienPhong() >= min && k.LayTienPhong() <= max)
        {
            temp.push_back((this->ptg + i)->LayTenPhong());
        }
    }
    return temp;
}

int QuanLyPhong::XacDinhLoaiPhong(string str)
{
    for(int i = 0; i < this->size[0]; i++)
    {
        if(str == (this->pcb + i)->LayTenPhong())
        {
            return 1;
        }
    }
    for(int i = 0; i < this->size[1]; i++)
    {
        if(str == (this->pt + i)->LayTenPhong())
        {
            return 2;
        }
    }
    for(int i = 0; i < this->size[2]; i++)
    {
        if(str == (this->ptg + i)->LayTenPhong())
        {
            return 3;
        }
    }
    return 0;
}

PhongCoBan& QuanLyPhong::LayThongTinPhongCoBan(string str)
{
    for(int i = 0; i < this->size[0]; i++)
    {
        if(str == (this->pcb + i)->LayTenPhong())
        {
            return *(this->pcb + i);
        }
    }
    PhongCoBan p;
    return p;
}

PhongThuong& QuanLyPhong::LayThongTinPhongThuong(string str)
{
    for(int i = 0; i < this->size[1]; i++)
    {
        if(str == (this->pt + i)->LayTenPhong())
        {
            return *(this->pt + i);
        }
    }
    PhongThuong p;
    return p;
}

PhongThuongGia& QuanLyPhong::LayThongTinPhongThuongGia(string str)
{
    for(int i = 0; i < this->size[2]; i++)
    {
        if(str == (this->ptg + i)->LayTenPhong())
        {
            return *(this->ptg + i);
        }
    }
    PhongThuongGia p;
    return p;
}

void QuanLyPhong::LuuPhongVaoFile()
{
    ofstream outfile("D:\\HK3\\PBL-Project-3\\FilePhong.txt");
    outfile << "PCB" << endl;
    outfile << this->size[0] << endl;
    for(int i = 0; i < this->size[0]; ++i)
    {
        outfile << (this->pcb + i)->LayTenPhong() << " " << (this->pcb + i)->KiemTraPhongTrong() << endl;
    }
    outfile << "PT" << endl;
    outfile << this->size[1] << endl;
    for(int i = 0; i < this->size[1]; ++i)
    {
        outfile << (this->pt + i)->LayTenPhong() << " " << (this->pt + i)->KiemTraPhongTrong() << " " << (this->pt + i)->LaySoLuongGiuongDon() << " " << (this->pt + i)->LaySoLuongGiuongDoi() << endl;
    }
    outfile << "PTG" << endl;
    outfile << this->size[2] << endl;
    for(int i = 0; i < this->size[2]; ++i)
    {
        outfile << (this->ptg + i)->LayTenPhong() << " " << (this->ptg + i)->KiemTraPhongTrong() << " " << (this->ptg + i)->LaySoLuongGiuongDon() << " " << (this->ptg + i)->LaySoLuongGiuongDoi() << endl;
    }
    outfile.close();
}
