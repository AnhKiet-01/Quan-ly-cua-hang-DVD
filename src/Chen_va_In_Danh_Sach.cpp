#include <iostream>
#include <string>
#include <iomanip>
#include "../include/khungsuoncode.h"

using namespace std;

string tree::rutgon(string s, size_t w) {
    if (s.length() > w) {
        return s.substr(0, w - 3) + "...";
    }
    return s;
}
Node* tree::ThemDiaMoi(Node* p, ThongTinDia dia) {
    if (p == NULL) return new Node(dia);
    if (dia.maDia < p->data.maDia) {
        p->left = ThemDiaMoi(p->left, dia);
    } else if (dia.maDia > p->data.maDia) {
        p->right = ThemDiaMoi(p->right, dia);
    } else {
        cout << "\nMa dia " << dia.maDia << " da ton tai. Khong the them!\n";
    }
    return p;
}
void tree::ThemDiaMoi(ThongTinDia dia) {
    root = ThemDiaMoi(root, dia);
}

Node* tree::timkiem(Node* p, int maDia) {
    if (p == NULL || p->data.maDia == maDia) return p;
    if (maDia < p->data.maDia) return timkiem(p->left, maDia);
    return timkiem(p->right, maDia);
}

Node* tree::timkiem(int maDia) {
    return timkiem(root, maDia);
}


string tree::DanhGiaDoUaChuong(const ThongTinDia dia) {
    int diem = dia.soLuotThue + dia.soLuotBan * 2;
    if (diem >= 100) return "Sieu Hot";
    if (diem >= 30)  return "Binh Thuong";
    return "E Am";
}


string tree::DeXuatNhapHang(const ThongTinDia dia) {
    if (dia.soLuongTon <= dia.dinhMucToiThieu) {
        string xephang = DanhGiaDoUaChuong(dia);
        if (xephang == "Sieu Hot") return "nhap hang gap";
        if (xephang == "E Am")     return "Xa Kho";
        return "Nhap It";
    }
    return "Ton Kho An Toan";
}

string tree::LaChinhHang(const ThongTinDia dia) {
    if (!dia.ChinhHang) return "Khong la Chinh Hang";
    return "La chinh Hang";
}

void tree::DanhSachKhoDia(Node* p) {
    if (p != NULL) {
        DanhSachKhoDia(p->left);

        cout << left
             << "|" << setw(7)  << p->data.maDia
             << "|" << setw(16) << rutgon(p->data.tenDia, 16)
             << "|" << setw(14) << rutgon(p->data.nhaCungCap, 14)
             << "|" << setw(10) << p->data.tinhTrang
             << "|" << setw(20) << LaChinhHang(p->data)
             << "|" << setw(5)  << p->data.soLuongTon
             << "|" << setw(7)  << p->data.dinhMucToiThieu
             << "|" << setw(8)  << fixed << setprecision(0) << p->data.giaThue
             << "|" << setw(10) << fixed << setprecision(0) << p->data.giaCaThitruong
             << "|" << setw(7)  << p->data.soLuotThue
             << "|" << setw(6)  << p->data.soLuotBan
             << "|" << setw(12) << DanhGiaDoUaChuong(p->data)
             << "|" << setw(18) << DeXuatNhapHang(p->data) << "|\n";

        DanhSachKhoDia(p->right);
    }
}

void tree::DanhSachKhoDia() {
    if (root == NULL) {
        cout << "\nHien tai danh sach kho dang trong!\n";
        return;
    }

    cout <<"+"<< setfill('-') << setw(152) << "-" << setfill(' ')<<"+" << "\n";
    cout << left
         << "|" << setw(7)  << "maDia"
         << "|" << setw(16) << "TenDia"
         << "|" << setw(14) << "Nha cung cap"
         << "|" << setw(10) << "Tinh trang"
         << "|" << setw(20) << "Xuat su"
         << "|" << setw(5)  << "ton"
         << "|" << setw(7)  << "Han muc"
         << "|" << setw(8)  << "Gia thue"
         << "|" << setw(10) << "thi truong"
         << "|" << setw(7)  << "So thue"
         << "|" << setw(6)  << "So ban"
         << "|" << setw(12) << "Do Ua Chuong"
         << "|" << setw(18) << "De xuat nhap hang" << "|\n";
    cout <<"+"<< setfill('-') << setw(152) << "-" << setfill(' ')<<"+" << "\n";

    DanhSachKhoDia(root);

    cout <<"+"<< setfill('-') << setw(152) << "-" << setfill(' ')<<"+" << "\n";
}

// 7. Giải phóng bộ nhớ cây
void tree::GiaiPhongCay(Node* p) {
    if (p != NULL) {
        GiaiPhongCay(p->left);
        GiaiPhongCay(p->right);
        delete p;
    }
}