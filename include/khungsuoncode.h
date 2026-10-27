#ifndef KHUNG_SUON_CODE_H
#define KHUNG_SUON_CODE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct ThongTinDia {
    int maDia;                    // Khóa BST ID
    string tenDia;                // Tên tác phẩm
    string nhaCungCap;            // Nhà cung cấp
    bool ChinhHang;             // Nguồn gốc bản quyền
    string tinhTrang;      // Tình trạng: "Moi", "Tot", "TrayXuoc", "Hong"
    int soLuongTon;               // Số lượng tồn khả dụng
    int dinhMucToiThieu;          // Ngưỡng tồn an toàn
    double giaThue;       // Giá thuê / ngày
    double giaCaThitruong;         // Giá đối thủ lân cận
    int soLuotThue;               // Lượt khách mượn 
    int soLuotBan;                // Lượt mua
};

 struct Node {
    ThongTinDia data;
    Node* left;
    Node* right;

    Node (ThongTinDia dia) : data(dia), left(NULL), right(NULL) {}
};


class tree {
private:
    Node* root;
    Node* ThemDiaMoi(Node* p, ThongTinDia dia);
    void DanhSachKhoDia(Node* p);
    Node* timkiem(Node* p, int maDia);
    void GiaiPhongCay(Node* p);

public:
	Node* root;
    tree() : root(NULL) {}
    ~tree() { GiaiPhongCay(root); }
    void ThemDiaMoi(ThongTinDia dia);
    void DanhSachKhoDia();
    Node* timkiem(int maDia);
    Node* getRoot() const { return root; }
    string DanhGiaDoUaChuong(const ThongTinDia dia);
    string DeXuatNhapHang(const ThongTinDia dia);
    bool LaChinhHang(const ThongTinDia dia);
};
// =======================================================
// 3. QUẢN LÝ GIAO DỊCH THUÊ/TRẢ VÀ QUẦY THU NGÂN
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

    PhieuThue(int mp, string ten, string sdt, int md, int ngay, double gia)
        : maPhieu(mp), tenKhachHang(ten), soDienThoai(sdt), maDia(md),
          soNgayThue(ngay), soNgayThucTe(0), donGiaNgay(gia),
          tongTien(ngay * gia), daTra(false), tiepTheo(NULL) {}
};

class HeThongCuaHang {
private:
    tree khoDia;
    PhieuThue* danhSachPhieu;
    int maPhieuTuTang;
    double tongDoanhThu;

public:
    HeThongCuaHang() : danhSachPhieu(NULL), maPhieuTuTang(1), tongDoanhThu(0) {}

    // Nhập đĩa vào kho (BST Insert) - SV1 làm
    bool themDiaMoi(ThongTinDia dia);

    // Xem danh mục - SV1 làm
    void xemDanhMucKho();

    // Nghiệp vụ cho thuê đĩa - SV2 làm
    bool choThue(int maDia, string tenKhach, string sdt, int soNgay);

    // Nghiệp vụ nhận trả đĩa - SV2 làm
    bool nhanTra(int maPhieu, int soNgayThucTe, string tinhTrangKhiTra); 

    // Xem danh sách phiếu thuê - SV3 làm
    void inDanhSachPhieuThue();

    // Bảng thống kê tổng quan - SV3 làm
    void inThongKe();
};

#endif
