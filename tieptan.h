#ifndef TIEPTAN_H
#define TIEPTAN_H
#include "nguoi.h"
#include "quanlykhachhang.h"
#include "quanlyphong.h"

class TiepTan : public Nguoi
{
private:
    QuanLyKhachHang qlkh;
    QuanLyPhong qlp;
public:
    TiepTan();
    TiepTan(string, string, string, int, int, int, string, string, QuanLyKhachHang, QuanLyPhong);
    ~TiepTan();
    void NhapThongTinChucNang(const QuanLyKhachHang&, const QuanLyPhong&);
    bool KiemTraTenPhong(string);
    bool KiemTraPhongTrong(string);
    bool KiemTraPhongBaoTri(string);
    bool KiemTraKhachHangDatPhong(string);
    bool KiemTraPhongDuocDatChua(string, int, int, int, int, int, int, int, int);
    bool KiemTraSDT(string, string);
    bool KiemTraKhachHangCu(KhachHang&);
    bool KiemTraThongTin(KhachHang&);
    void CapNhatTrangThaiPhong();
    void CapNhatDuLieuKhachHang();
    void KhachHangDatPhong(KhachHang&);
    void HienThiPhong();
    void LuuThongTinKhachHang(KhachHang&, string);
    void NhapKhachHangVaoHashTable(string,int);
    void NhapHoaDonVaoHashTable(HoaDon,int);
    void HienThiThongTinKhachHang();
    void HienThiTable();
    void LayKhachHanghtb(string);
    KhachHang& KhachHangTheoPhong(string);
    KhachHang& KhachHangTheoPhongTime(string);
    KhachHang& KhachHangCuTheoCCCD(string);
    HoaDon& HoaDonTheoCCCDMaHD(string, string);
    const TiepTan& operator = (const TiepTan&); // khong = qlkh, qlp
    vector<string> LayTenCacPhong(int,int,int,int, long long, long long);
    vector<KhachHang> LayDanhSachKhachHangMoi();
    vector<KhachHang> LayDanhSachKhachHangCu();
    vector<HoaDon> LayDSHDTheoTTDSC(string, string, string);
    vector<HoaDon> LayDSHDTheoTTDSM(string, string, string);
    vector<HoaDon> LayDSHD();
    vector<HoaDon> LayDSHDM();
    int XacDinhLoaiPhong(string);
    PhongCoBan& LayThongTinPhongCoBan(string);
    PhongThuong& LayThongTinPhongThuong(string);
    PhongThuongGia& LayThongTinPhongThuongGia(string);
    int XacDinhKhachHangThue(string);
    void ChuyenTrangThaiPhong(string);
    void TangDichVu(int,string);
    void LayDuLieuTuFilePhong();
    void LayDuLieuTuFileKhachHangCu();
    void LayDuLieuTuFileHoaDon();
    void LayDuLieuTuFileKhachHangMoi();
    void LuuPhongVaoFile();
    void LuuKhachHangCuVaoFile();
    void LuuKhachHangMoiVaoFile();
    void LuuHoaDonVaoFile();
};

#endif // TIEPTAN_H
