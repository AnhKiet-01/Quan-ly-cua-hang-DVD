#ifndef NGHIEPVUTHUNGAN_H
#ifndef NGHIEPVUTHUNGAN_H
#define NGHIEPVUTHUNGAN_H

#include "KhoDiaBST.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Cấu trúc phiếu thuê đĩa (Dùng Danh sách liên kết đơn)
struct PhieuThue {
    int maPhieu;           // Mã phiếu thuê tự tăng (1, 2, 3...)
    string tenKhachHang;   // Tên khách hàng thuê
    string soDienThoai;    // Số điện thoại liên hệ
    int maDia;             // Mã DVD thuê
    int soNgayThue;        // Hạn thuê (Số ngày đăng ký)
    int soNgayThucTe;      // Ngày trả đĩa thực tế
    double donGiaNgay;     // Giá thuê / ngày
    double tongTien;       // Tổng thu (Tiền thuê + phạt quá hạn)
    bool daTra;            // Trạng thái: true (Đã trả), false (Đang mượn)
    
    PhieuThue* tiepTheo;   // Con trỏ liên kết phiếu tiếp theo

    // Constructor khởi tạo mặc định
    PhieuThue() {
        maPhieu = 0;
        tenKhachHang = "";
        soDienThoai = "";
        maDia = 0;
        soNgayThue = 0;
        soNgayThucTe = 0;
        donGiaNgay = 0.0;
        tongTien = 0.0;
        daTra = false;
        tiepTheo = NULL;
    }
};

// Lớp quản lý nghiệp vụ thuê/trả đĩa cho Quầy thu ngân
class QuanLyThuNgan {
private:
    PhieuThue* danhSachPhieu;  // Con trỏ đầu danh sách liên kết
    int maPhieuTuTang;         // Bộ đếm tự tăng mã phiếu
    double tongDoanhThu;       // Tổng doanh thu quầy thu ngân

public:
    QuanLyThuNgan();
    ~QuanLyThuNgan();

    // Nghiệp vụ cho thuê đĩa (Kiểm tra kho BST & tạo phiếu)
    bool choThue(tree& khoDia, int maDia, string tenKhach, string sdt, int soNgay);

    // Nghiệp vụ nhận trả đĩa (Trả về kho & tính phạt quá hạn)
    bool nhanTra(tree& khoDia, int maPhieu, int soNgayThucTe, string tinhTrangKhiTra);

    // Xem danh sách phiếu thuê (Hiển thị đủ 7 trường mục tiêu)
    void inDanhSachPhieuThue();

    // Lấy tổng doanh thu thu ngân
    double getTongDoanhThu() const { 
        return tongDoanhThu; 
    }
};

#endif