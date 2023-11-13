#ifndef NGUOI_H
#define NGUOI_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Date
{
    int Ngay;
    int Thang;
    int Nam;
    int Gio;
};

class Nguoi
{
protected:
    string CCCD;
    string Ten;
    string SDT;
    Date Birth;
public:
    Nguoi();
    ~Nguoi();
    void NhapThongTin(string, string, string, int, int, int);
    string LayCCCD();
    string LayTen();
    string LaySDT();
    long long LayCCCD(int);
    string LayBirth();
};

#endif // NGUOI_H
