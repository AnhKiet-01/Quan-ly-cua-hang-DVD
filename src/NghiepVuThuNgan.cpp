
// 1. CHỨC NĂNG CHO THUÊ ĐĨA
bool QuanLyThuNgan::choThue(tree& khoDia, int maDia, string tenKhach, string sdt, int soNgay) {
    PhieuThue* phieuMoi = new PhieuThue();
    phieuMoi->maPhieu = ++maPhieuTuTang;
    phieuMoi->tenKhachHang = tenKhach;
    phieuMoi->soDienThoai = sdt;
    phieuMoi->maDia = maDia;
    phieuMoi->soNgayThue = soNgay;
    phieuMoi->soNgayThucTe = 0;
    phieuMoi->tongTien = 0.0;
    phieuMoi->daTra = false;

    phieuMoi->tiepTheo = danhSachPhieu;
    danhSachPhieu = phieuMoi;

    cout << "\n[SUCCESS] Cho thue dia thanh cong! Ma phieu: " << phieuMoi->maPhieu << endl;
    return true;
}

// 2. CHỨC NĂNG NHẬN TRẢ ĐĨA & TÍNH PHẠT TRỄ HẠN
bool QuanLyThuNgan::nhanTra(tree& khoDia, int maPhieu, int soNgayThucTe, string tinhTrangKhiTra) {
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

// 3. CHỨC NĂNG IN DANH SÁCH KHÁCH HÀNG THUÊ ĐĨA
void QuanLyThuNgan::inDanhSachPhieuThue() {
    cout << "\n========================================= DANH SACH KHAC HANG THUE DIA =========================================\n";
    if (danhSachPhieu == NULL) {
        cout << "Chua co phieu thue nao trong he thong!\n";
        cout << "============================================================================================================\n";
        return;
    }

    PhieuThue* temp = danhSachPhieu;
    while (temp != NULL) {
        cout << "Ma phieu: " << temp->maPhieu
             << " | Ten KH: " << temp->tenKhachHang
             << " | SDT: " << temp->soDienThoai
             << " | Ma DVD: " << temp->maDia
             << " | Han thue: " << temp->soNgayThue << " ngay"
             << " | Ngay tra TT: " << temp->soNgayThucTe << " ngay"
             << " | Tong thu: " << fixed << setprecision(0) << temp->tongTien << " VND"
             << " | Trang thai: " << (temp->daTra ? "Da tra dia" : "Chua tra dia")
             << endl;
        temp = temp->tiepTheo;
    }
    cout << "============================================================================================================\n";
}