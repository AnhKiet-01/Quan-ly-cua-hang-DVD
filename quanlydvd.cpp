#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =======================================================
// 1. CẤU TRÚC DỮ LIỆU ĐĨA DVD (LƯU TRONG CÂY BST)
// =======================================================
struct ThongTinDia {
    int maDia;                    // Khóa BST ID
    string tenDia;                // Tên tác phẩm
    string nhaCungCap;            // Nhà cung cấp
    bool laChinhHang;             // Nguồn gốc bản quyền
    string tinhTrangBaoQuan;      // Tình trạng: "Moi", "Tot", "TrayXuoc", "Hong"
    int soLuongTon;               // Số lượng tồn khả dụng
    int dinhMucToiThieu;          // Ngưỡng tồn an toàn
    double giaThueTheoNgay;       // Giá thuê / ngày
    double giaTiemLanCan;         // Giá đối thủ lân cận
    int soLuotThue;               // Lượt khách mượ`	n
    int soLuotBan;                // Lượt mua

    // Đánh giá mức độ ưa chuộng của sản phẩm
    string danhGiaUaChuong() const {
        int diem = soLuotThue + soLuotBan * 2;
        if (diem >= 10) return "Sieu Hot";
        if (diem >= 5)  return "Binh thuong";
        return "E am";
    }

    // Đề xuất tự động nhập/giảm tồn kho
    string deXuatNhapHang() const {
        if (soLuongTon <= dinhMucToiThieu) {
            string xepHang = danhGiaUaChuong();
            if (xepHang == "Sieu Hot") return "CANH BAO: Nhap gap!";
            if (xepHang == "E am")     return "Giam nhap / Xa";
            return "Dat hang tu dong";
        }
        return "Ton kho an toan";
    }
};

// Node của cây BST
struct NutCay {
    ThongTinDia duLieu;
    NutCay* trai;
    NutCay* phai;

    NutCay(ThongTinDia dl) : duLieu(dl), trai(NULL), phai(NULL) {}
};

// =======================================================
// 3. CÂY NHỊ PHÂN TÌM KIẾM (BST) QUẢN LÝ KHO ĐĨA
// =======================================================
class CayNhiPhanKho {
private:
    NutCay* goc;

    // Chèn đệ quy theo maDia
    NutCay* chenDeQuy(NutCay* nut, ThongTinDia dl) {
        if (nut == NULL) return new NutCay(dl);
        if (dl.maDia < nut->duLieu.maDia) {
            nut->trai = chenDeQuy(nut->trai, dl);
        } else if (dl.maDia > nut->duLieu.maDia) {
            nut->phai = chenDeQuy(nut->phai, dl);
        }
        return nut;
    }

    // Duyệt In-Order (LNR: Tăng dần theo mã đĩa)
    void duyetInOrder(NutCay* nut) const {
        if (nut != NULL) {
            duyetInOrder(nut->trai);
            cout << left 
			     << setw(8)  << nut->duLieu.maDia
                 << setw(18) << nut->duLieu.tenDia
                 << setw(8)  << nut->duLieu.soLuongTon
                 << setw(10) << nut->duLieu.dinhMucToiThieu
                 << setw(14) << fixed << setprecision(0) << nut->duLieu.giaThueTheoNgay
                 << setw(14) << nut->duLieu.giaTiemLanCan
                 << setw(14) << nut->duLieu.danhGiaUaChuong()
                 << setw(20) << nut->duLieu.deXuatNhapHang() << "\n";
            duyetInOrder(nut->phai);
        }
    }

    void giaiPhongCay(NutCay* nut) {
        if (nut != NULL) {
            giaiPhongCay(nut->trai);
            giaiPhongCay(nut->phai);
            delete nut;
        }
    }

public:
    CayNhiPhanKho() : goc(NULL) {}
    ~CayNhiPhanKho() { giaiPhongCay(goc); }

    void chen(ThongTinDia dl) {
        goc = chenDeQuy(goc, dl);
    }

    // Tìm kiếm phần tử theo mã đĩa O(log N)
    NutCay* timKiem(int maDia) const {
        NutCay* hienTai = goc;
        while (hienTai != NULL) {
            if (hienTai->duLieu.maDia == maDia) return hienTai;
            if (maDia < hienTai->duLieu.maDia) hienTai = hienTai->trai;
            else hienTai = hienTai->phai;
        }
        return NULL;
    }

    // In danh mục sắp xếp tăng dần theo ID
    void inDanhMucInOrder() const {
        if (goc == NULL) {
            cout << "(Kho hang hien dang rong)\n";
            return;
        }
        cout << "\n" << setfill('-') << setw(106) << "-" << setfill(' ') << "\n";
        cout << left << setw(8)  << "Ma DVD"
             << setw(18) << "| Ten dia |"
             << setw(8)  << "| Ton |"
             << setw(10) << "| Dinh muc |"
             << setw(14) << "| Gia thue/ngay |"
             << setw(14) << "| Gia doi thu |"
             << setw(14) << "| Thi truong |"
             << setw(20) << "| De xuat he thong |" << "\n";
        cout << setfill('-') << setw(106) << "-" << setfill(' ') << "\n";
        duyetInOrder(goc);
        cout << setfill('-') << setw(106) << "-" << setfill(' ') << "\n";
    }

};

// =======================================================
// 4. QUẢN LÝ GIAO DỊCH THUÊ/TRẢ VÀ QUẦY THU NGÂN
// =======================================================
struct PhieuThue {
    int maPhieu;
    string tenKhachHang;
    string soDienThoai;
    int maDia;
    int soNgayThue;
    int soNgayThucTe;
    double donGiaNgay;
    double tongTien;
    bool daTra;
    PhieuThue* tiepTheo;
};

class HeThongCuaHang {
private:
    CayNhiPhanKho khoDia;
    PhieuThue* danhSachPhieu;
    int maPhieuTuTang;
    double tongDoanhThu;

public:
    HeThongCuaHang() : danhSachPhieu(NULL), maPhieuTuTang(1), tongDoanhThu(0) {}

    // Nhập đĩa vào kho (BST Insert)
    bool themDiaMoi(ThongTinDia dia) {
        if (khoDia.timKiem(dia.maDia) != NULL) {
            cout << "[Loi]: Ma DVD " << dia.maDia << " da ton tai trong cay BST!\n";
            return false;
        }
        khoDia.chen(dia);
        cout << "=> Da them thanh cong DVD [" << dia.maDia << "] " << dia.tenDia << " vao cay kho hang!\n";
        return true;
    }

    void xemDanhMucKho() const {
        khoDia.inDanhMucInOrder();
    }


    // Nghiệp vụ cho thuê đĩa
    bool choThue(int maDia, string tenKhach, string sdt, int soNgay) {
        NutCay* nutDia = khoDia.timKiem(maDia);
        if (nutDia == NULL) {
            cout << "[Loi]: Khong tim thay ma DVD " << maDia << " trong cay kho hang!\n";
            return false;
        }

        if (nutDia->duLieu.soLuongTon <= 0) {
            cout << "[Kho bao]: DVD '" << nutDia->duLieu.tenDia << "' da het hang ton kha dung!\n";
            return false;
        }

        // Trừ số lượng tồn và tăng lượt thuê
        nutDia->duLieu.soLuongTon--;
        nutDia->duLieu.soLuotThue++;

        double tienThue = soNgay * nutDia->duLieu.giaThueTheoNgay;
        tongDoanhThu += tienThue;

        // Lưu thông tin phiếu mượn
        PhieuThue* p = new PhieuThue;
        p->maPhieu = maPhieuTuTang++;
        p->tenKhachHang = tenKhach;
        p->soDienThoai = sdt;
        p->maDia = maDia;
        p->soNgayThue = soNgay;
        p->soNgayThucTe = 0;
        p->donGiaNgay = nutDia->duLieu.giaThueTheoNgay;
        p->tongTien = tienThue;
        p->daTra = false;

        // Chèn vào đầu DSLK
        p->tiepTheo = danhSachPhieu;
        danhSachPhieu = p;

        cout << "=> [Thu ngan]: Tao phieu #" << p->maPhieu << " cho KH: " << tenKhach 
             << " - Thue dia: '" << nutDia->duLieu.tenDia << "' (" << soNgay << " ngay) - Thu: " 
             << fixed << setprecision(0) << tienThue << " đ\n";
        return true;
    }

    // Nghiệp vụ nhận trả đĩa
    bool nhanTra(int maPhieu, int soNgayThucTe, string tinhTrangKhiTra) {
        PhieuThue* p = danhSachPhieu;
        while (p != NULL && p->maPhieu != maPhieu) {
            p = p->tiepTheo;
        }

        if (p == NULL) {
            cout << "[Loi]: Khong tim thay ma phieu #" << maPhieu << "!\n";
            return false;
        }

        if (p->daTra) {
            cout << "[Thong bao]: Phieu #" << maPhieu << " nay da hoan tat tra truoc do roi!\n";
            return false;
        }

        p->daTra = true;
        p->soNgayThucTe = soNgayThucTe;

        // Hoàn trả đĩa về kho BST
        NutCay* nutDia = khoDia.timKiem(p->maDia);
        if (nutDia != NULL) {
            nutDia->duLieu.soLuongTon++;
            nutDia->duLieu.tinhTrangBaoQuan = tinhTrangKhiTra;
        }

        // Tính tiền quá hạn: ngày trễ * (đơn giá * 1.5)
        if (soNgayThucTe > p->soNgayThue) {
            int ngayTre = soNgayThucTe - p->soNgayThue;
            double tienPhat = ngayTre * (p->donGiaNgay * 1.5);
            p->tongTien += tienPhat;
            tongDoanhThu += tienPhat;
            cout << "=> [Canh bao trê han]: Tre " << ngayTre << " ngay! Phụ thu phi phat: " 
                 << fixed << setprecision(0) << tienPhat << " đ\n";
        }

        cout << "=> [Hoan tat]: Da nhan lai dia DVD tu phieu #" << maPhieu 
             << " (Chat luong khi tra: " << tinhTrangKhiTra << ")\n";
        return true;
    }

    // Xem danh sách phiếu thuê
    void inDanhSachPhieuThue() const {
        cout << "\n" << setfill('-') << setw(88) << "-" << setfill(' ') << "\n";
        cout << left << setw(10) << "Ma phieu"
             << setw(18) << "Khach hang"
             << setw(14) << "SDT"
             << setw(8)  << "Ma DVD"
             << setw(12) << "Han thue"
             << setw(12) << "Thuc te"
             << setw(14) << "Tong tien"
             << setw(12) << "Trang thai" << "\n";
        cout << setfill('-') << setw(88) << "-" << setfill(' ') << "\n";

        PhieuThue* p = danhSachPhieu;
        while (p != NULL) {
            cout << left
			     << setw(10) << ("#" + to_string(p->maPhieu))
                 << setw(18) << p->tenKhachHang
                 << setw(14) << p->soDienThoai
                 << setw(8)  << p->maDia
                 << setw(12) << (to_string(p->soNgayThue) + " ngay")
                 << setw(12) << (p->daTra ? to_string(p->soNgayThucTe) + " ngay" : "-")
                 << setw(14) << (to_string((long)p->tongTien) + " d")
                 << setw(12) << (p->daTra ? "Da tra" : "Dang muon") << "\n";
            p = p->tiepTheo;
        }
        cout << setfill('-') << setw(88) << "-" << setfill(' ') << "\n";
    }

    // Bảng thống kê tổng quan
    void inThongKe() const {
        int soDiaDangMuon = 0;
        PhieuThue* p = danhSachPhieu;
        while (p != NULL) {
            if (!p->daTra) soDiaDangMuon++;
            p = p->tiepTheo;
        }

        cout << "\n================= THONG KE TOAN BO HE THONG =================\n";
        cout << "- Tong doanh thu thu ngan ghi nhan : " << fixed << setprecision(0) << tongDoanhThu << " d\n";
        cout << "- So luong don thue dang con no dia: " << soDiaDangMuon << "\n";
        cout << "============================================================\n";
    }
};

// =======================================================
// 5. HÀM MAIN: MENU ĐIỀU KHIỂN TƯƠNG TÁC
// =======================================================
int main() {
    HeThongCuaHang heThong;

    // Nạp sẵn 5 mẫu đĩa ban đầu y hệt trên web
    heThong.themDiaMoi({50, "Inception", "Sony", true, "Moi", 5, 2, 15000, 13000, 12, 4});
    heThong.themDiaMoi({30, "Avatar 2", "Fox", true, "Tot", 1, 3, 20000, 14000, 15, 6});
    heThong.themDiaMoi({70, "Titanic", "Paramount", true, "Tot", 4, 2, 10000, 8500, 4, 1});
    heThong.themDiaMoi({20, "Dia Cu 1990", "Dai Nam", false, "TrayXuoc", 1, 2, 5000, 3500, 0, 0});
    heThong.themDiaMoi({40, "Interstellar", "Warner", true, "Moi", 8, 3, 18000, 13500, 8, 2});

    int luaChon;
    do {
        cout << "\n=============== HE THONG QUAN LY KHO DIA DVD (BST & QUEUE) ===============\n";
        cout << "1. Xem danh muc kho hang (Duyet BST In-Order: Tang dan theo ID)\n";
        cout << "2. Nhap kho dia DVD moi (BST Insert)\n";
        cout << "3. Quay thu ngan: Cho thue dia\n";
        cout << "4. Quay thu ngan: Nhan tra dia (Tinh phat tre han & cap nhat kho)\n";
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
                cout << "Nhap Ma DVD (Khoa BST ID): "; cin >> d.maDia;
                cin.ignore();
                cout << "Nhap Ten dia: "; getline(cin, d.tenDia);
                cout << "Nhap Nha cung cap: "; getline(cin, d.nhaCungCap);
                d.laChinhHang = true;
                d.tinhTrangBaoQuan = "Moi";
                cout << "Nhap So luong ton: "; cin >> d.soLuongTon;
                cout << "Nhap Dinh muc toi thieu: "; cin >> d.dinhMucToiThieu;
                cout << "Nhap Gia thue/ngay (d): "; cin >> d.giaThueTheoNgay;
                cout << "Nhap Gia doi thu lan can (d): "; cin >> d.giaTiemLanCan;
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

    return 0;
}