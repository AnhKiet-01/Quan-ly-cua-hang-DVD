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
    Node* ThemDiaMoi(Node* p, ThongTinDia dia){
        if(p == NULL) return new Node(dia);
        if(dia.maDia < p->data.maDia) p->left = ThemDiaMoi(p->left, dia);
        else if(dia.maDia > p->data.maDia) p->right = ThemDiaMoi(p->right, dia);
        else{
            cout << "\n Ma dia da ton tai. khong the the dia moi.\n";
        }
        return p;
    };
    void DanhSachKhoDia(Node* p){
    	if(p!=NULL){
    		
    		DanhSachKhoDia(p->left);
    		
    		cout << left
    		     << "|" << setw(7) << p->data.maDia
    		     << "|" << setw(16) << rutgon(p->data.tenDia,16)
    		     << "|" << setw(14) << rutgon(p->data.nhaCungCap,14)
    		     << "|" << setw(10) << p->data.tinhTrang
    		     << "|" << setw(20) << LaChinhHang(p->data)
    		     << "|" << setw(5) << p->data.soLuongTon
    		     << "|" << setw(7) << p->data.dinhMucToiThieu
    		     << "|" << setw(8) << p->data.giaThue
    		     << "|" << setw(10) << p->data.giaCaThitruong
    		     << "|" << setw(7) << p->data.soLuotThue
    		     << "|" << setw(6) << p->data.soLuotBan
    		     << "|" << setw(12) << DanhGiaDoUaChuong(p->data)
    		     << "|" << setw(18) << DeXuatNhapHang(p->data) << "|\n";
    		     
    		DanhSachKhoDia(p->right);
 	    }
	};
    Node* timkiem(Node* p, int maDia);
    void GiaiPhongCay(Node* p){
    	if(p!=NULL){
    		GiaiPhongCay(p->left);
    		GiaiPhongCay(p->right);
    		delete p;
		}
	};

public:
	Node* root;
    tree() : root(NULL) {}
    ~tree() { GiaiPhongCay(root); }
    void ThemDiaMoi(ThongTinDia dia);
    void DanhSachKhoDia();
    Node* timkiem(int maDia);
    string DanhGiaDoUaChuong(const ThongTinDia dia);
    string DeXuatNhapHang(const ThongTinDia dia);
    string LaChinhHang(const ThongTinDia dia);
    string rutgon(string s, size_t w) {
        if (s.length() > w) {
            return s.substr(0, w - 3) + "..."; 
        }
        return s;
    }
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
    tree khoDia;
    PhieuThue* danhSachPhieu;
    int maPhieuTuTang;
    double tongDoanhThu;

public:
    HeThongCuaHang() : danhSachPhieu(NULL), maPhieuTuTang(1), tongDoanhThu(0) {}
    bool themDiaMoi(ThongTinDia dia);
    void xemDanhMucKho();
    bool choThue(int maDia, string tenKhach, string sdt, int soNgay);
    bool nhanTra(int maPhieu, int soNgayThucTe, string tinhTrangKhiTra); 
    void inDanhSachPhieuThue();
    void inThongKe();
};
#endif
