#ifndef KHUNG_SUON_CODE_H
#define KHUNG_SUON_CODE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct ThongTinDia {
    int maDia;                   
    string tenDia;                
    string nhaCungCap;            
    bool ChinhHang;             
    string tinhTrang;      
    int soLuongTon;               
    int dinhMucToiThieu;        
    double giaThue;      
    double giaCaThitruong;        
    int soLuotThue;               
    int soLuotBan;               
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
    tree() : root(NULL) {}
    ~tree() { GiaiPhongCay(root); }
    Node* getroot() const {return root;}
    void ThemDiaMoi(ThongTinDia dia);
    void DanhSachKhoDia();
    Node* timkiem(int maDia);
    string DanhGiaDoUaChuong(const ThongTinDia dia);
    string DeXuatNhapHang(const ThongTinDia dia);
    string LaChinhHang(const ThongTinDia dia);
    string rutgon(string s, size_t w);
};

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
    PhieuThue* next;

    PhieuThue(int mp, string ten, string sdt, int md, int ngay, double gia)
        : maPhieu(mp), tenKhachHang(ten), soDienThoai(sdt), maDia(md),
          soNgayThue(ngay), soNgayThucTe(0), donGiaNgay(gia),
          tongTien(ngay * gia), daTra(false), next(NULL) {}
};



class HeThongCuaHang {
private:
    PhieuThue* danhSachPhieu;
    int stt;
    double tongDoanhThu;

public:
    HeThongCuaHang() : danhSachPhieu(NULL), stt(1), tongDoanhThu(0) {}
    tree khoDia;
    bool choThue(int maDia, string tenKhach, string sdt, int soNgay);
    bool nhanTra(int maPhieu, int soNgayThucTe, string tinhTrangKhiTra); 
    void inDanhSachPhieuThue();
    void inThongKe();
    void themphieumau(int mp, string ten, string sdt, int md, int songay, int ngaythuc, double gia, double tong, bool datra);
};
#endif
