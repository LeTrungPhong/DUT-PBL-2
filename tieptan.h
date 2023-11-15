#ifndef TIEPTAN_H
#define TIEPTAN_H
#include "nguoi.h"
#include "quanlykhachhang.h"
#include "quanlyphong.h"

class TiepTan : public Nguoi
{
private:
    string TaiKhoan;
    string MatKhau;
    QuanLyKhachHang qlkh;
    QuanLyPhong qlp;
public:
    TiepTan();
    TiepTan(string, string, string, int, int, int, string, string, QuanLyKhachHang, QuanLyPhong);
    ~TiepTan();

    void NhapTaiKhoanMatKhau(string, string);
    void NhapThongTinChucNang(const QuanLyKhachHang&, const QuanLyPhong&);

    bool KiemTraTaiKhoanMatKhau(string, string);
    bool KiemTraTenPhong(string);
    bool KiemTraPhongTrong(string);
    bool KiemTraPhongBaoTri(string);

    void KhachHangDatPhong(KhachHang&);
    void HienThiPhong();

    void LuuThongTinKhachHang(KhachHang&, string);
    void NhapKhachHangVaoHashTable(string);
    void HienThiThongTinKhachHang();
    void HienThiTable();

    void ThemPhongCoBan(PhongCoBan);
    void ThemPhongThuong(PhongThuong);
    void ThemPhongThuongGia(PhongThuongGia);

    KhachHang& KhachHangTheoPhong(string);

    const TiepTan& operator = (const TiepTan&); // khong = qlkh, qlp

    vector<string> LayTenCacPhong(int,int,int,int, long long, long long);
    vector<string> LayTenCacPhong2(KhachHang&, long long, long long);

    int XacDinhLoaiPhong(string);
    PhongCoBan& LayThongTinPhongCoBan(string);
    PhongThuong& LayThongTinPhongThuong(string);
    PhongThuongGia& LayThongTinPhongThuongGia(string);

    int XacDinhKhachHangThue(string);

    void ChuyenTrangThaiPhong(string);

    void TangDichVu(int,string);

    void LuuPhongVaoFile();
    void LuuKhachHangCuVaoFile();
    void LuuKhachHangMoiVaoFile();
};

#endif // TIEPTAN_H
