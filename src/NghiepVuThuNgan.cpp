#include "../include/khungsuongcode.h"

// 1. CHỨC NĂNG CHO THUÊ ĐĨA
bool HeThongCuaHang::choThue(int maDia, string tenKhach, string sdt, int soNgay) {
   Node* diaTimDuoc = khoDia.timkiem(maDia);
    if (diaTimDuoc == NULL) {
        cout << "\n[ERROR] Khong tim thay ma dia " << maDia << " trong kho!" << endl;
        return false;
    }

    if (diaTimDuoc->data.soLuongTon <= 0) {
        cout << "\n[WARNING] Dia " << diaTimDuoc->data.tenDia << " (Ma: " << maDia << ") da het hang trong kho!" << endl;
        return false;
    }

    double donGia = diaTimDuoc->data.giaThue;

    PhieuThue* phieuMoi = new PhieuThue(maPhieuTuTang++, tenKhach, sdt, maDia, soNgay, donGia);

    phieuMoi->tiepTheo = danhSachPhieu;
    danhSachPhieu = phieuMoi;

    diaTimDuoc->data.soLuongTon--;
    diaTimDuoc->data.soLuotThue++;

    cout << "\n================ CHO THUE DIA THANH CONG ================" << endl;
    cout << "Ma phieu    : " << phieuMoi->maPhieu << endl;
    cout << "Khach hang  : " << phieuMoi->tenKhachHang << " (" << phieuMoi->soDienThoai << ")" << endl;
    cout << "Ten dia thue: " << diaTimDuoc->data.tenDia << " (Ma: " << maDia << ")" << endl;
    cout << "Han thue    : " << soNgay << " ngay" << endl;
    cout << "Tien dat coc: " << fixed << setprecision(0) << phieuMoi->tongTien << " VND" << endl;
    cout << "==========================================================" << endl;

    return true;
}

// 2. CHỨC NĂNG NHẬN TRẢ ĐĨA & TÍNH PHẠT TRỄ HẠN
bool HeThongCuaHang::nhanTra(int maPhieu, int soNgayThucTe, string tinhTrangKhiTra) {
    PhieuThue* temp = danhSachPhieu;

    while (temp != NULL) {
        if (temp->maPhieu == maPhieu) {
            if (temp->daTra) {
                cout << "\n[WARNING] Phieu ma " << maPhieu << " da duoc tra truoc do!" << endl;
                return false;
            }

            temp->soNgayThucTe = soNgayThucTe;

            double tienGoc = temp->soNgayThue * temp->donGiaNgay;
            double tienPhat = 0.0;

            if (soNgayThucTe > temp->soNgayThue) {
                int soNgayTre = soNgayThucTe - temp->soNgayThue;
                tienPhat = soNgayTre * (temp->donGiaNgay * 1.5);
            }

            temp->tongTien = tienGoc + tienPhat;
            temp->daTra = true;
            tongDoanhThu += temp->tongTien;

    
            Node* diaTimDuoc = khoDia.timkiem(temp->maDia);
            if (diaTimDuoc != NULL) {
                diaTimDuoc->data.soLuongTon++;
                if (!tinhTrangKhiTra.empty()) {
                    diaTimDuoc->data.tinhTrang = tinhTrangKhiTra;
                }
            }

            cout << "\n================ HOAN TAT TRA DIA ================" << endl;
            cout << "Ma phieu: " << temp->maPhieu << " | Khach hang: " << temp->tenKhachHang << endl;
            cout << "Han thue: " << temp->soNgayThue << " ngay | Thuc te: " << soNgayThucTe << " ngay" << endl;
            cout << "Tien goc: " << fixed << setprecision(0) << tienGoc << " VND" << endl;
            if (tienPhat > 0) {
                cout << "Phat tre han (" << (soNgayThucTe - temp->soNgayThue) << " ngay x 150%): " << tienPhat << " VND" << endl;
            } else {
                cout << "Tinh trang: Tra dung han" << endl;
            }
            cout << "TONG THU: " << temp->tongTien << " VND" << endl;
            cout << "==================================================" << endl;

            return true;
        }
        temp = temp->tiepTheo;
    }

    cout << "\n[ERROR] Khong tim thay ma phieu: " << maPhieu << endl;
    return false;
}


