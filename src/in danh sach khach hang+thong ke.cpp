#include "../include/khungsuoncode.h"


//  IN DANH SACH PHIEU THUE (case 5)

void HeThongCuaHang::inDanhSachPhieuThue() {
    if (danhSachPhieu == NULL) {
        cout << "\nChua co phieu thue nao.\n";
        return;
    }

    cout << "\n-DANH SACH KHACH THUE-\n";
    cout << left << setw(5)  << "STT"
         << setw(8)  << "Ma PT"
         << setw(20) << "Khach hang"
         << setw(13) << "SDT"
         << setw(8)  << "Ma DVD"
         << setw(10) << "Ngay thue"
         << setw(10) << "Thuc te"
         << setw(14) << "Tien quy dinh"
         << setw(12) << "Phi tre"
         << setw(16) << "Tien phai tra"
         << "Trang thai\n";
    cout << string(120, '-') << "\n";

    int stt = 1;
    for (PhieuThue* p = danhSachPhieu; p != NULL; p = p->tiepTheo) {
        double tienQuyDinh = p->soNgayThue * p->donGiaNgay;

        double phiTre = 0;
        if (p->daTra && p->soNgayThucTe > p->soNgayThue)
            phiTre = (p->soNgayThucTe - p->soNgayThue) * p->donGiaNgay * 1.5;

        double tienPhaiTra = tienQuyDinh + phiTre;

        cout << left << setw(5)  << stt++
             << setw(8)  << p->maPhieu
             << setw(20) << p->tenKhachHang
             << setw(13) << p->soDienThoai
             << setw(8)  << p->maDia
             << setw(10) << p->soNgayThue;

        if (p->daTra) cout << setw(10) << p->soNgayThucTe;
        else          cout << setw(10) << "-";

        cout << setw(14) << (long long)tienQuyDinh
             << setw(12) << (long long)phiTre
             << setw(16) << (long long)tienPhaiTra
             << (p->daTra ? "Da tra" : "Dang muon (tam tinh)") << "\n";
    }
}

//  THONG KE TONG QUAN (case 6)


void HeThongCuaHang::inThongKe() {
    int tongPhieu = 0, dangMuon = 0, daTraXong = 0, traTreHan = 0;

    for (PhieuThue* p = danhSachPhieu; p != NULL; p = p->tiepTheo) {
        tongPhieu++;
        if (p->daTra) {
            daTraXong++;
            if (p->soNgayThucTe > p->soNgayThue) traTreHan++;
        } else {
            dangMuon++;
        }
    }

    cout << "\nTHONG KE TONG QUAN \n";
    cout << left << setw(28) << "Tong so phieu thue:"  << tongPhieu << "\n";
    cout << left << setw(28) << "Phieu dang muon:"     << dangMuon << "\n";
    cout << left << setw(28) << "Phieu da tra:"        << daTraXong << "\n";
    cout << left << setw(28) << "Phieu tra tre han:"   << traTreHan << "\n";
    cout << left << setw(28) << "Tong doanh thu:"
         << fixed << setprecision(0) << tongDoanhThu << " d\n";
}
