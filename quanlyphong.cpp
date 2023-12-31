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

void QuanLyPhong::NhapThongTinPhong(int s1, int s2, int s3, PhongCoBan* p1, PhongThuong* p2, PhongThuongGia* p3)
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

void QuanLyPhong::ThemPhong(const PhongCoBan &th)
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

void QuanLyPhong::ThemPhong(const PhongThuong &th)
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

void QuanLyPhong::ThemPhong(const PhongThuongGia &th)
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

void QuanLyPhong::XoaPhong(string str, int lp)
{
    if(lp == 1)
    {
        PhongCoBan *p = new PhongCoBan[this->size[0]];
        for(int i = 0; i < this->size[0]; ++i)
        {
            *(p + i) = *(this->pcb + i);
        }
        this->size[0]--;
        delete[] this->pcb;
        this->pcb = new PhongCoBan[this->size[0]];
        int k = 0;
        for(int i = 0; i < this->size[0] + 1; ++i)
        {
            if((p + i)->LayTenPhong() != str)
            {
                *(this->pcb + k) = *(p + i);
                k++;
            }
        }
        delete[] p;
    }
    if(lp == 2)
    {
        PhongThuong *p = new PhongThuong[this->size[1]];
        for(int i = 0; i < this->size[1]; ++i)
        {
            *(p + i) = *(this->pt + i);
        }
        this->size[1]--;
        delete[] this->pt;
        this->pt = new PhongThuong[this->size[1]];
        int k = 0;
        for(int i = 0; i < this->size[1] + 1; ++i)
        {
            if((p + i)->LayTenPhong() != str)
            {
                *(this->pt + k) = *(p + i);
                k++;
            }
        }
        delete[] p;
    }
    if(lp == 3)
    {
        PhongThuongGia *p = new PhongThuongGia[this->size[2]];
        for(int i = 0; i < this->size[2]; ++i)
        {
            *(p + i) = *(this->ptg + i);
        }
        this->size[2]--;
        delete[] this->ptg;
        this->ptg = new PhongThuongGia[this->size[2]];
        int k = 0;
        for(int i = 0; i < this->size[2] + 1; ++i)
        {
            if((p + i)->LayTenPhong() != str)
            {
                *(this->ptg + k) = *(p + i);
                k++;
            }
        }
        delete[] p;
    }
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
        for(int i = 0; i < size[0]; ++i)
        {
            *(this->pcb + i) = *(qlp.pcb + i);
        }
        this->pt = new PhongThuong[size[1]];
        for(int i = 0; i < size[1]; ++i)
        {
            *(this->pt + i) = *(qlp.pt + i);
        }
        this->ptg = new PhongThuongGia[size[2]];
        for(int i = 0; i < size[2]; ++i)
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
}

vector<string> split1(string str, string delimiter)
{
    size_t pos = 0;
    vector<string> tokens;
    while ((pos = str.find(delimiter)) != string::npos)
    {
        string temp_token = str.substr(0, pos);
        tokens.push_back(temp_token);
        str.erase(0, pos + delimiter.length());
    }
    tokens.push_back(str);
    return tokens;
}

void QuanLyPhong::LayDuLieuTuFilePhong()
{
    ifstream file;
    file.open("D:\\HK3\\PBL-Project-3\\FilePhong.txt");
    if (!file.is_open())
    {
        cout << "Error opening data file 0" << endl;
        return;
    }
    string line;
    getline(file, line);
    if (line != "PCB")
    {
        cout << "Error: File data is not in the correct format 1" << endl;
        return;
    }
    line = "";
    getline(file, line);
    if (line != "GiaTienPhongCoBan")
    {
        cout << "Error: File data is not in the correct format 1" << endl;
        return;
    }
    line = "";
    getline(file, line);
    long long gtpcb = stoi(line);
    line = "";
    getline(file, line);
    if (line != "GiaTienGiuongDon")
    {
        cout << "Error: File data is not in the correct format 1" << endl;
        return;
    }
    line = "";
    getline(file, line);
    long long gtgdon = stoi(line);
    PhongCoBan tempcb(gtgdon,gtpcb);
    line = "";
    getline(file, line);
    this->size.push_back(stoi(line));
    this->pcb = new PhongCoBan[this->size[0]];
    for (int i = 0; i < this->size[0]; i++)
    {
        getline(file, line);
        if (line.empty())
        {
            continue;
        }
        vector<string> tokens = split1(line, " ");
        (this->pcb + i)->NhapThongTinPhong(tokens[0],stoi(tokens[1]));
    }
    getline(file, line);
    if (line != "PT")
    {
        cout << "Error: File data is not in the correct format 2" << endl;
        return;
    }
    line = "";
    getline(file, line);
    if (line != "GiaTienPhongThuong")
    {
        cout << "Error: File data is not in the correct format 1" << endl;
        return;
    }
    line = "";
    getline(file, line);
    long long gtpt = stoi(line);
    line = "";
    getline(file, line);
    if (line != "GiaTienGiuongDoi")
    {
        cout << "Error: File data is not in the correct format 1" << endl;
        return;
    }
    line = "";
    getline(file, line);
    long long gtgdoi = stoi(line);
    PhongThuong tempt(gtgdoi,gtpt);
    line = "";
    getline(file, line);
    this->size.push_back(stoi(line));
    this->pt = new PhongThuong[this->size[1]];
    for (int i = 0; i < this->size[1]; i++)
    {
        getline(file, line);
        if (line.empty())
        {
            continue;
        }
        vector<string> tokens = split1(line, " ");
        (this->pt + i)->NhapThongTinPhong(tokens[0],stoi(tokens[1]),stoi(tokens[2]),stoi(tokens[3]));
    }
    getline(file, line);
    if (line != "PTG")
    {
        cout << "Error: File data is not in the correct format 3" << endl;
        return;
    }
    line = "";
    getline(file, line);
    if (line != "GiaTienPhongThuongGia")
    {
        cout << "Error: File data is not in the correct format 1" << endl;
        return;
    }
    line = "";
    getline(file, line);
    long long gtptg = stoi(line);
    line = "";
    getline(file, line);
    if (line != "DichVuThuongGia")
    {
        cout << "Error: File data is not in the correct format 1" << endl;
        return;
    }
    line = "";
    getline(file, line);
    long long dvtg = stoi(line);
    PhongThuongGia temptg(dvtg,gtptg);
    line = "";
    getline(file, line);
    this->size.push_back(stoi(line));
    this->ptg = new PhongThuongGia[this->size[2]];
    for (int i = 0; i < this->size[2]; i++)
    {
        getline(file, line);
        if (line.empty())
        {
            continue;
        }
        vector<string> tokens = split1(line, " ");
        (this->ptg + i)->NhapThongTinPhong(tokens[0],stoi(tokens[1]),stoi(tokens[2]),stoi(tokens[3]));
    }
    file.close();
}

void QuanLyPhong::LuuPhongVaoFile()
{
    ofstream outfile("D:\\HK3\\PBL-Project-3\\FilePhong.txt");
    outfile << "PCB" << endl;
    outfile << "GiaTienPhongCoBan" << endl;
    outfile << PhongCoBan::LayGTPCB() << endl;
    outfile << "GiaTienGiuongDon" << endl;
    outfile << PhongCoBan::LayGTGDon() << endl;
    outfile << this->size[0] << endl;
    for(int i = 0; i < this->size[0]; ++i)
    {
        outfile << (this->pcb + i)->LayTenPhong() << " " << (this->pcb + i)->KiemTraPhongTrong() << endl;
    }
    outfile << "PT" << endl;
    outfile << "GiaTienPhongThuong" << endl;
    outfile << PhongThuong::LayGTPT() << endl;
    outfile << "GiaTienGiuongDoi" << endl;
    outfile << PhongThuong::LayGTGDoi() << endl;
    outfile << this->size[1] << endl;
    for(int i = 0; i < this->size[1]; ++i)
    {
        outfile << (this->pt + i)->LayTenPhong() << " " << (this->pt + i)->KiemTraPhongTrong() << " " << (this->pt + i)->LaySoLuongGiuongDon() << " " << (this->pt + i)->LaySoLuongGiuongDoi() << endl;
    }
    outfile << "PTG" << endl;
    outfile << "GiaTienPhongThuongGia" << endl;
    outfile << PhongThuongGia::LayGTPTG() << endl;
    outfile << "DichVuThuongGia" << endl;
    outfile << PhongThuongGia::LayDVTG() << endl;
    outfile << this->size[2] << endl;
    for(int i = 0; i < this->size[2]; ++i)
    {
        outfile << (this->ptg + i)->LayTenPhong() << " " << (this->ptg + i)->KiemTraPhongTrong() << " " << (this->ptg + i)->LaySoLuongGiuongDon() << " " << (this->ptg + i)->LaySoLuongGiuongDoi() << endl;
    }
    outfile.close();
}
