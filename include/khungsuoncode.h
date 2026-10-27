#ifndef KHUNG_SUON_CODE_H
#define KHUNG_SUON_CODE_H

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
    bool ChinhHang;             // Nguồn gốc bản quyền
    string tinhTrang;      // Tình trạng: "Moi", "Tot", "TrayXuoc", "Hong"
    int soLuongTon;               // Số lượng tồn khả dụng
    int dinhMucToiThieu;          // Ngưỡng tồn an toàn
    double giaThueTheoNgay;       // Giá thuê / ngày
    double giaTiemLanCan;         // Giá đối thủ lân cận
    int soLuotThue;               // Lượt khách mượn 
    int soLuotBan;                // Lượt mua
};

// Node của cây BST
struct Node {
    ThongTinDia data;
    Node* left;
    Node* right;

    Node(ThongTinDia dia) : data(dia), left(NULL), right(NULL) {}
};

// =======================================================
// 2. CÂY NHỊ PHÂN TÌM KIẾM (BST) QUẢN LÝ KHO ĐĨA
// =======================================================
class tree {
    public:
    Node* root;

    // Chèn đệ quy theo maDia
    Node* chen(Node* p, ThongTinDia dl);

    // Duyệt In-Order (LNR: Tăng dần theo mã đĩa)
    void duyetInOrder(Node* p);

    // Giải phóng cây 
    void giaiPhongCay(Node* p);

public:
    tree() : root(NULL) {}
    ~tree() { giaiPhongCay(root); }

    void chen(ThongTinDia dl);

    // Tìm kiếm phần tử theo mã đĩa O(log N)
    Node* timKiem(int maDia);

    // In danh mục sắp xếp tăng dần theo ID
    void inDanhMucInOrder();
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
