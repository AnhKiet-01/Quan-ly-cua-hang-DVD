#include <iostream>
#include <string>
#include <iomanip>
#include "../include/khungsuoncode.h"

using namespace std;
int main() {
    HeThongCuaHang heThong;

    int luaChon;
    do {
        cout << "\n=============== HE THONG QUAN LY KHO DIA DVD ===============\n";
        cout << "1. Xem danh muc kho hang \n";
        cout << "2. Nhap kho dia DVD moi \n";
        cout << "3. Quay thu ngan: Cho thue dia\n";
        cout << "4. Quay thu ngan: Nhan tra dia\n";
        cout << "5. Xem so theo doi phieu thue khach hang\n";
        cout << "6. Xem thong ke tong quan doanh thu\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "Chon chuc nang: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                heThong.xemDanhMucKho();
                break;
            case 2: {
                ThongTinDia d;
                cout << "\n--- NHAP THONG TIN DVD MOI ---\n";
                cout << "\n-Nhap Ma DVD: "; cin >> d.maDia;
                cin.ignore();
                cout << "\n-Nhap Ten dia: "; getline(cin, d.tenDia);
                cout << "\n-Nhap Nha cung cap: "; getline(cin, d.nhaCungCap);
                cout << "\n-Nhap xuat su(co phai chinh hang khong)"; cin >> d.ChinhHang;
                cout << "\n-Nhap tinh trang dia: "; cin>> d.tinhTrang;
                cout << "\n-Nhap So luong ton: "; cin >> d.soLuongTon;
                cout << "\n-Nhap Dinh muc toi thieu: "; cin >> d.dinhMucToiThieu;
                cout << "\n-Nhap Gia thue/ngay (d): "; cin >> d.giaThue;
                cout << "\n-Nhap Gia doi thu lan can (d): "; cin >> d.giaCaThitruong;
                d.soLuotThue = 0;
                d.soLuotBan = 0;
                heThong.themDiaMoi(d);
                break;
            }
            case 3: {
                int maDia, soNgay;
                string tenKhach, sdt;
                cout << "\n--- TAO PHIEU CHO THUE DIA ---\n";
                cout << "Nhap Ma DVD can thue: "; cin >> maDia;
                cin.ignore();
                cout << "Nhap Ten khach hang: "; getline(cin, tenKhach);
                cout << "Nhap So dien thoai: "; getline(cin, sdt);
                cout << "Nhap So ngay thue: "; cin >> soNgay;
                heThong.choThue(maDia, tenKhach, sdt, soNgay);
                break;
            }
            case 4: {
                int maPhieu, songaythucte, chonTinhTrang;
                string tinhTrang = "Tot";
                cout << "\n--- NHAN TRA DIA ---\n";
                cout << "Nhap Ma phieu thue: "; cin >> maPhieu;
                cout << "Nhap So ngay thuc te da muon: "; cin >> songaythucte;
                cout << "Chon chat luong khi tra (1. Tot | 2. TrayXuoc | 3. Hong): ";
                cin >> chonTinhTrang;
                if (chonTinhTrang == 2) tinhTrang = "TrayXuoc";
                else if (chonTinhTrang == 3) tinhTrang = "Hong";
                heThong.nhanTra(maPhieu, songaythucte, tinhTrang);
                break;
            }
            case 5:
                heThong.inDanhSachPhieuThue();
                break;
            case 6:
                heThong.inThongKe();
                break;
            case 0:
                cout << "Da thoat chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!\n";
        }
    } while (luaChon != 0);

}
