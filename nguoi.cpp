#include "nguoi.h"

Nguoi::Nguoi()
{
    this->Ten = "0";
}

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

bool Nguoi::operator == (const Nguoi& n)
{
    bool check = true;
    if(this->CCCD != n.CCCD) check = false;
    if(this->Ten != n.Ten) check = false;
    if(this->Birth.Ngay != n.Birth.Ngay) check = false;
    if(this->Birth.Thang != n.Birth.Thang) check = false;
    if(this->Birth.Nam != n.Birth.Nam) check = false;
    return check;
}
