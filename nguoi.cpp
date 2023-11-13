#include "nguoi.h"

Nguoi::Nguoi()
{ }

Nguoi::~Nguoi()
{ }

void Nguoi::NhapThongTin(string CCCD, string Ten, string SDT, int ng, int thg, int nam)
{
    this->CCCD = CCCD;
    this->Ten = Ten;
    this->SDT = SDT;
    this->Birth.Ngay = ng;
    this->Birth.Thang = thg;
    this->Birth.Nam = nam;
    this->Birth.Gio = 0;
}

string Nguoi::LayCCCD()
{
    return this->CCCD;
}

string Nguoi::LayTen()
{
    return this->Ten;
}

string Nguoi::LaySDT()
{
    return this->SDT;
}

long long Nguoi::LayCCCD(int i)
{
    stringstream ss(this->CCCD);
    long long num;
    ss >> num;
    return num;
}

string Nguoi::LayBirth()
{
    string str = to_string(this->Birth.Ngay) + "/" + to_string(this->Birth.Thang) + "/" + to_string(this->Birth.Nam);
    return str;
}
