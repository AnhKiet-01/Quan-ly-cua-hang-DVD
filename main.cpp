#include <iostream>
#include <string>
#include <iomanip>
#include "../include/khungsuoncode.h"

using namespace std;
struct MauPhieu {
    int mp;
    string ten;
    string sdt;
    int md;
    int soNgay;
    int ngayThuc;
    double gia;
    double tong;
    bool daTra;
};
void khoitaoPhieuThue(HeThongCuaHang& heThong) {
	MauPhieu DanhSachPhieu[] = {
	    {1, "Nguyen Van An", "0901234567", 10, 3, 3, 20000, 60000, true},
        {2, "Tran Thi Mai", "0912345678", 15, 2, 2, 25000, 50000, true},
        {3, "Le Hoang Nam", "0987654321", 25, 4, 6, 22000, 132000, true},
        {4, "Pham Minh Tuan", "0933445566", 35, 2, 0, 25000, 50000, false},
        {5, "Dang Thu Thao", "0977889900", 45, 3, 3, 18000, 54000, true},
        {6, "Vo Quoc Bao", "0944556677", 55, 5, 7, 15000, 105000, true},
        {7, "Doan Ngoc Hai", "0966112233", 60, 1, 0, 16000, 16000, false},
        {8, "Bui Duc Thang", "0922334455", 65, 3, 3, 15000, 45000, true},
        {9, "Hoang Yen Nhi", "0909998877", 75, 2, 5, 20000, 100000, true},
        {10, "Truong Gia Huy", "0918273645", 80, 4, 0, 12000, 48000, false},
        {11, "Nguyen Thanh Son", "0938475610", 85, 2, 2, 12000, 24000, true},
        {12, "Vu Bich Phuong", "0981928374", 90, 3, 3, 14000, 42000, true},
        {13, "Dinh Trong Tri", "0948572619", 95, 1, 3, 10000, 30000, true},
        {14, "Lam My Duyen", "0976543210", 12, 2, 0, 3000, 6000, false},
        {15, "Phan Tan Phat", "0965432109", 18, 4, 4, 4000, 16000, true},
        {16, "Nguyen Kim Ngan", "0911223344", 22, 3, 0, 5000, 15000, false},
        {17, "Ta Quang Buu", "0933112244", 38, 2, 2, 18000, 36000, true},
        {18, "Chau Kien Phong", "0922446688", 48, 3, 5, 25000, 125000, true},
        {19, "Ly Lan Anh", "0988776655", 62, 4, 4, 18000, 72000, true},
        {20, "Huynh Tan Sang", "0908123456", 88, 2, 0, 15000, 30000, false}
	};
	int n = sizeof(DanhSachPhieu) / sizeof(DanhSachPhieu[0]);
    for (int i = 0; i < n; i++) {
        heThong.themphieumau(
            DanhSachPhieu[i].mp, DanhSachPhieu[i].ten, DanhSachPhieu[i].sdt, DanhSachPhieu[i].md,
            DanhSachPhieu[i].soNgay, DanhSachPhieu[i].ngayThuc, DanhSachPhieu[i].gia, DanhSachPhieu[i].tong, DanhSachPhieu[i].daTra
        );
    }
}
int main() {
    HeThongCuaHang heThong;
    khoitaoPhieuThue(heThong);
    ThongTinDia DanhSachDia[] = {
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
	for(const auto& dia : DanhSachDia){
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