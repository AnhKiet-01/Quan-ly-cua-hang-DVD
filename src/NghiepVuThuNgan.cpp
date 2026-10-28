#include <iostream>
#include <string>
#include <iomanip>
#include "../include/khungsuoncode.h"

using namespace std;

// 1. CHỨC NĂNG CHO THUÊ ĐĨA
bool HeThongCuaHang::choThue(int maDia, string tenKhach, string sdt, int soNgay) {
    // 1.1 Kiểm tra đĩa có tồn tại trong kho cây BST không
    Node* pDia = khoDia.timkiem(maDia);
    if (pDia == NULL) {
        cout << "\n[ERROR] Khong tim thay ma dia " << maDia << " trong he thong kho!\n";
        return false;
    }

    // 1.2 Kiểm tra số lượng tồn kho
    if (pDia->data.soLuongTon <= 0) {
        cout << "\n[ERROR] Dia \"" << pDia->data.tenDia << "\" da het hang trong kho (Ton = 0)!\n";
        return false;
    }

    // 1.3 Cập nhật thông tin kho đĩa trên cây BST
    pDia->data.soLuongTon--;
    pDia->data.soLuotThue++;

    // 1.4 Khởi tạo Node phiếu thuê thông qua constructor chuẩn
    int maPhieuMoi = maPhieuTuTang++;
    PhieuThue* phieuMoi = new PhieuThue(maPhieuMoi, tenKhach, sdt, maDia, soNgay, pDia->data.giaThue);

    // 1.5 Chèn vào đầu danh sách liên kết đơn phiếu thuê
    phieuMoi->next = danhSachPhieu;
    danhSachPhieu = phieuMoi;

    cout << "\n[SUCCESS] Cho thue dia thanh cong!\n";
    cout << " + Ma phieu: " << phieuMoi->maPhieu << endl;
    cout << " + Ten dia: " << pDia->data.tenDia << endl;
    cout << " + Don gia ngay: " << fixed << setprecision(0) << phieuMoi->donGiaNgay << " VND\n";
    cout << " + So ngay thue: " << phieuMoi->soNgayThue << " ngay\n";
    cout << " + Tam tinh: " << phieuMoi->tongTien << " VND\n";
    cout << " + So luong con lai trong kho: " << pDia->data.soLuongTon << endl;

    return true;
}

// 2. CHỨC NĂNG NHẬN TRẢ ĐĨA & TÍNH PHẠT TRỄ HẠN
bool HeThongCuaHang::nhanTra(int maPhieu, int soNgayThucTe, string tinhTrangKhiTra) {
    PhieuThue* temp = danhSachPhieu;

    while (temp != NULL) {
        if (temp->maPhieu == maPhieu) {
            if (temp->daTra) {
                cout << "\n[WARNING] Phieu ma " << maPhieu << " da duoc tra truoc do!\n";
                return false;
            }

            temp->soNgayThucTe = soNgayThucTe;

            // Tính tiền gốc và tiền phạt trễ hạn
            double tienGoc = temp->soNgayThue * temp->donGiaNgay;
            double tienPhat = 0.0;

            if (soNgayThucTe > temp->soNgayThue) {
                int soNgayTre = soNgayThucTe - temp->soNgayThue;
                // Phạt 150% đơn giá ngày cho mỗi ngày trễ hạn
                tienPhat = soNgayTre * (temp->donGiaNgay * 1.5);
            }

            temp->tongTien = tienGoc + tienPhat;
            temp->daTra = true;
            tongDoanhThu += temp->tongTien;

            // Cập nhật lại số lượng tồn kho trên cây BST
            Node* pDia = khoDia.timkiem(temp->maDia);
            if (pDia != NULL) {
                pDia->data.soLuongTon++;
                // Cập nhật tình trạng đĩa sau khi trả nếu có trầy xước/hỏng
                if (!tinhTrangKhiTra.empty()) {
                    pDia->data.tinhTrang = tinhTrangKhiTra;
                }
            }

            cout << "\n================ HOAN TAT TRA DIA ================\n";
            cout << "Ma phieu: " << temp->maPhieu << " | Khach hang: " << temp->tenKhachHang << endl;
            if (pDia != NULL) {
                cout << "Ten dia: " << pDia->data.tenDia << " | Tinh trang luc tra: " << pDia->data.tinhTrang << endl;
            }
            cout << "Han thue: " << temp->soNgayThue << " ngay | Thuc te: " << soNgayThucTe << " ngay\n";
            cout << "Tien goc: " << fixed << setprecision(0) << tienGoc << " VND\n";
            if (tienPhat > 0) {
                cout << "Phat tre han (" << (soNgayThucTe - temp->soNgayThue) << " ngay x 150%): " << tienPhat << " VND\n";
            } else {
                cout << "Tinh trang: Tra dung han\n";
            }
            cout << "TONG THU: " << temp->tongTien << " VND\n";
            cout << "==================================================\n";

            return true;
        }
        temp = temp->next;
    }

    cout << "\n[ERROR] Khong tim thay ma phieu: " << maPhieu << endl;
    return false;
}