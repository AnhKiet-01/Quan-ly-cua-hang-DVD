#include <iostream>
#include <string>
#include <iomanip>
#include "../include/khungsuoncode.h"

using namespace std;
int main() {
    HeThongCuaHang heThong;
    ThongTinDia DanhSach[] = {
        {50, "Inception", "Sony", true, "Moi", 5, 2, 15000, 13000, 12, 4},
        {30, "Avatar 2", "Fox", true, "Tot", 1, 3, 20000, 14000, 15, 6},
        {70, "Titanic", "Paramount", true, "Tot", 4, 2, 10000, 8500, 4, 1},
        {20, "Dia Cu 1990", "Dai Nam", false, "TrayXuoc", 1, 2, 5000, 3500, 0, 0},
        {40, "Interstellar", "Warner", true, "Moi", 8, 3, 18000, 13500, 8, 2},
        {10, "The Dark Knight", "Warner", true, "Moi", 12, 3, 20000, 18000, 80, 45},
        {15, "Avengers Endgame", "Marvel", true, "Tot", 2, 5, 25000, 20000, 95, 60},
        {25, "Spider Man No Way Home", "Sony", true, "Moi", 3, 4, 22000, 19000, 70, 30},
        {35, "Oppenheimer", "Universal", true, "Moi", 10, 3, 25000, 22000, 55, 25},
        {45, "Barbie", "Warner", true, "Tot", 6, 3, 18000, 15000, 40, 15},
        {55, "Spirited Away", "Ghibli", true, "Tot", 4, 2, 15000, 12000, 35, 10},
        {60, "Your Name", "Toho", true, "Moi", 7, 2, 16000, 14000, 50, 20},
        {65, "Parasite", "CJ Ent", true, "Tot", 3, 2, 15000, 13000, 28, 8},
        {75, "John Wick 4", "Lionsgate", true, "Moi", 2, 4, 20000, 18000, 65, 30},
        {80, "The Matrix", "Warner", true, "Tot", 5, 2, 12000, 10000, 18, 5},
        {85, "Forrest Gump", "Paramount", true, "Tot", 6, 2, 12000, 9500, 15, 3},
        {90, "The Godfather", "Paramount", true, "Tot", 4, 2, 14000, 11000, 22, 6},
        {95, "Pulp Fiction", "Miramax", true, "TrayXuoc", 2, 2, 10000, 8000, 10, 2},
        {12, "Hai Tet 2005", "Dong Do", false, "Hong", 1, 2, 3000, 2000, 1, 0},
        {18, "Nhac Vang Chon Loc", "Lang Van", false, "TrayXuoc", 5, 3, 4000, 3000, 3, 1},
        {22, "Ca Nhac Xuan 2010", "Rang Dong", false, "Tot", 8, 3, 5000, 4000, 2, 0},
        {38, "Fast and Furious 10", "Universal", true, "Tot", 9, 4, 18000, 16000, 42, 12},
        {48, "Dune Part 2", "Warner", true, "Moi", 1, 5, 25000, 22000, 85, 40},
        {62, "Coco", "Disney", true, "Moi", 8, 3, 18000, 15000, 45, 18},
        {88, "Toy Story 4", "Pixar", true, "Tot", 3, 3, 15000, 12000, 20, 5}
	};
	for(const auto& dia : DanhSach){
		heThong.khoDia.ThemDiaMoi(dia);
	}
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
                heThong.khoDia.DanhSachKhoDia(); 
                break;
            case 2: {
                ThongTinDia d;
                cout << "\n--- NHAP THONG TIN DVD MOI ---\n";
                cout << "\n-Nhap Ma DVD: "; cin >> d.maDia;
                cin.ignore();
                cout << "-Nhap Ten dia: "; getline(cin, d.tenDia);
                cout << "-Nhap Nha cung cap: "; getline(cin, d.nhaCungCap);
                cout << "-Nhap xuat su (1: Chinh hang | 0: Khong): "; cin >> d.ChinhHang;
                cout << "-Nhap tinh trang dia (Moi/Tot/TrayXuoc/Hong): "; cin >> d.tinhTrang;
                cout << "-Nhap So luong ton: "; cin >> d.soLuongTon;
                cout << "-Nhap Dinh muc toi thieu: "; cin >> d.dinhMucToiThieu;
                cout << "-Nhap Gia thue/ngay (d): "; cin >> d.giaThue;
                cout << "-Nhap Gia doi thu lan can (d): "; cin >> d.giaCaThitruong;
                d.soLuotThue = 0;
                d.soLuotBan = 0;
                heThong.khoDia.ThemDiaMoi(d); 
                cout << "=> Da them dia vao kho thanh cong!\n";
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

    return 0;
}