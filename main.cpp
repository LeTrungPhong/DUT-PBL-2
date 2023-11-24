#include "mainwindow.h"
#include <bits/stdc++.h>
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <string>
#include <QtCore>
#include <QFileDevice>

using namespace std;

void FilePhong(QuanLyPhong&);
void FileKhachHangCu(HashTable&);
void FileKhachHangMoi(QuanLyKhachHang&, HashTable&);
vector<string> split(string, string);

int main(int argc, char *argv[])
{
    HashTable htb;
    FileKhachHangCu(htb);

    QuanLyKhachHang qlkh;
    FileKhachHangMoi(qlkh,htb);

    QuanLyPhong qlp;
    FilePhong(qlp);

    QApplication a(argc, argv);
    MainWindow w;
    w.NhapThongTin(qlkh,qlp);
    w.show();

    return a.exec();
}

void FilePhong(QuanLyPhong &qlp)
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
    int so_phong1 = stoi(line);
    PhongCoBan *p1 = new PhongCoBan[so_phong1];
    for (int i = 0; i < so_phong1; i++)
    {
        getline(file, line);
        if (line.empty())
        {
            continue;
        }
        vector<string> tokens = split(line, " ");
        (p1 + (i))->NhapThongTinPhong(tokens[0],stoi(tokens[1]));
    }
    getline(file, line);
    if (line != "PT")
    {
        cout << "Error: File data is not in the correct format 2" << endl;
        return;
    }
    line = "";
    getline(file, line);
    int so_phong2 = stoi(line);
    PhongThuong *p2 = new PhongThuong[so_phong2];
    for (int i = 0; i < so_phong2; i++)
    {
        getline(file, line);
        if (line.empty())
        {
            continue;
        }
        vector<string> tokens = split(line, " ");
        (p2 + (i))->NhapThongTinPhong(tokens[0],stoi(tokens[1]),stoi(tokens[2]),stoi(tokens[3]));
    }
    getline(file, line);
    if (line != "PTG")
    {
        cout << "Error: File data is not in the correct format 3" << endl;
        return;
    }
    line = "";
    getline(file, line);
    int so_phong3 = stoi(line);
    PhongThuongGia *p3 = new PhongThuongGia[so_phong3];
    for (int i = 0; i < so_phong3; i++)
    {
        getline(file, line);
        if (line.empty())
        {
            continue;
        }
        vector<string> tokens = split(line, " ");
        (p3 + (i))->NhapThongTinPhong(tokens[0],stoi(tokens[1]),stoi(tokens[2]),stoi(tokens[3]));
    }
    qlp.NhapThongTinPhong(so_phong1,so_phong2,so_phong3,p1,p2,p3);
    file.close();
}

void FileKhachHangCu(HashTable &htb)
{
    ifstream file;
    file.open("D:\\HK3\\PBL-Project-3\\Khach_Hang_Cu.txt");
    if (!file.is_open()) {
        cout << "Error opening data file !!!" << endl;
        return;
    }
    string line;
    getline(file, line);
    long long size = stoi(line);
    getline(file, line);
    int sl = stoi(line);
    KhachHang *k = new KhachHang[sl];
    // 0 : CCCD
    // 1 : SDT
    // 2 : mp
    // 3 : ngay thang nam sinh
    // 4 : ngay thang nam den
    // 5 : ngay thang nam di
    // 6 7 8 9 : dich vu
    // 10 : gia tien
    // 11 : Ten
    for(int i = 0; i < sl; i++)
    {
        getline(file, line);
        vector<string> token = split(line,"|");
        vector<int> dv;
        dv.push_back(stoi(token[6]));
        dv.push_back(stoi(token[7]));
        dv.push_back(stoi(token[8]));
        dv.push_back(stoi(token[9]));
        vector<string> ns = split(token[3],"/");
        vector<string> nden = split(token[4],"/");
        vector<string> ndi = split(token[5],"/");
        (k + i)->NhapThongTin(token[0],token[11],token[1],stoi(ns[0]),stoi(ns[1]),stoi(ns[2]));
        (k + i)->NhapThongTinKhac(token[2],dv,stoi(nden[0]),stoi(nden[1]),stoi(nden[2]),stoi(nden[3]),stoi(ndi[0]),stoi(ndi[1]),stoi(ndi[2]),stoi(ndi[3]),stoi(token[10]));;
    }
    htb.NhapDuLieu(size,0,k,sl);
    file.close();
}

void FileKhachHangMoi(QuanLyKhachHang &qlkh, HashTable &htb)
{
    ifstream file;
    file.open("D:\\HK3\\PBL-Project-3\\Khach_Hang_Moi.txt");
    if (!file.is_open()) {
        cout << "Error opening data file !!!" << endl;
        return;
    }
    string line;
    getline(file, line);
    int size = stoi(line);
    KhachHang *k = new KhachHang[size];
    for(int i = 0; i < size; i++)
    {
        // 0 : CCCD
        // 1 : SDT
        // 2 : mp
        // 3 : ngay thang nam sinh
        // 4 : ngay thang nam den
        // 6 : ngay thang nam di
        // 6 7 8 9 : dich vu
        // 10 : Ten
        getline(file, line);
        vector<string> token = split(line,"|");
        vector<int> dv;
        dv.push_back(stoi(token[6]));
        dv.push_back(stoi(token[7]));
        dv.push_back(stoi(token[8]));
        dv.push_back(stoi(token[9]));
        vector<string> ns = split(token[3],"/");
        vector<string> nden = split(token[4],"/");
        vector<string> ndi = split(token[5],"/");
        (k + i)->NhapThongTin(token[0],token[10],token[1],stoi(ns[0]),stoi(ns[1]),stoi(ns[2]));
        (k + i)->NhapThongTinKhac(token[2],dv,stoi(nden[0]),stoi(nden[1]),stoi(nden[2]),stoi(nden[3]),stoi(ndi[0]),stoi(ndi[1]),stoi(ndi[2]),stoi(ndi[3]));;
    }
    qlkh.NhapDuLieu(k,htb,size);
    file.close();
}

vector<string> split(string str, string delimiter)
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
