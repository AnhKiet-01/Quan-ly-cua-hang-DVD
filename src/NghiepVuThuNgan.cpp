#include <iostream>
#include <string>
#include <iomanip>
#include "../include/khungsuoncode.h"

using namespace std;
bool HeThongCuaHang::choThue(int maDia, string tenKhach, string sdt, int soNgay) {
    Node* p = HeThongCuaHang::khoDia.timkiem(maDia);
    if (p == NULL) {
        cout << "\n[ERROR] Khong tim thay ma dia " << maDia << " trong he thong kho\n";
        return false;
    }

    if (p->data.soLuongTon <= 0) {
        cout << "\n[ERROR] Dia \"" << p->data.tenDia << "\" da het hang trong kho (Ton = 0)\n";
        return false;
    }
    p->data.soLuongTon--;
    p->data.soLuotThue++;

    int maPhieuMoi = stt++;
    PhieuThue* phieuMoi = new PhieuThue(maPhieuMoi, tenKhach, sdt, maDia, soNgay, p->data.giaThue);

    phieuMoi->next = danhSachPhieu;
    danhSachPhieu = phieuMoi;

    cout << "\n[SUCCESS] Cho thue dia thanh cong!\n";
    cout << " + Ma phieu: " << phieuMoi->maPhieu << endl;
    cout << " + Ten dia: " << p->data.tenDia << endl;
    cout << " + Don gia ngay: " << fixed << setprecision(0) << phieuMoi->donGiaNgay << " VND\n";
    cout << " + So ngay thue: " << phieuMoi->soNgayThue << " ngay\n";
    cout << " + Tam tinh: " << phieuMoi->tongTien << " VND\n";
    cout << " + So luong con lai trong kho: " << p->data.soLuongTon << endl;

    return true;
}

bool HeThongCuaHang::nhanTra(int maPhieu, int soNgayThucTe, string tinhTrangKhiTra) {
    PhieuThue* temp = danhSachPhieu;

    while (temp != NULL) {
        if (temp->maPhieu == maPhieu) {
            if (temp->daTra) {
                cout << "\n[WARNING] Phieu ma " << maPhieu << " da duoc tra truoc do!\n";
                return false;
            }

            temp->soNgayThucTe = soNgayThucTe;

            double tienGoc = temp->soNgayThue * temp->donGiaNgay;
            double tienPhat = 0.0;

            if (soNgayThucTe > temp->soNgayThue) {
                int soNgayTre = soNgayThucTe - temp->soNgayThue;
                tienPhat = soNgayTre * (temp->donGiaNgay * 1.5);
            }

            temp->tongTien = tienGoc + tienPhat;
            temp->daTra = true;
            tongDoanhThu += temp->tongTien;
            Node* p = khoDia.timkiem(temp->maDia);
            if (p != NULL) {
                p->data.soLuongTon++;
                if (!tinhTrangKhiTra.empty()) {
                    p->data.tinhTrang = tinhTrangKhiTra;
                }
            }

            cout <<"+" <<setfill('-') << setw(57) <<'-' << setfill(' ')<<"+"  <<"\n";
            cout << left
                 << setw(13) <<"| Ma phieu: "; 
			cout << left
			     << setw(44) <<temp->maPhieu<<" |\n";
			cout << left
			     << setw(15)<<"| Khach hang: " 
			     << setw(42)<<temp->tenKhachHang <<" |\n";
            if (p != NULL) {
            	cout << left
                     << setw(11)<< "| Ten dia: " ;
				cout << left 
				     << setw(46)<< p->data.tenDia <<" |\n";
				cout << left
					 << setw(22)<<"| Tinh trang luc tra: "; 
				cout << left
				     << setw(35)<<p->data.tinhTrang <<" |\n";
            }
            cout <<"+" <<setfill('-') << setw(57) <<'-' << setfill(' ')<<"+"  <<"\n";
            cout << left
			     << setw(13)<< "| Han thue: " 
				 << setw(39)<<temp->soNgayThue <<" ngay |\n" 
				 << setw(12)<<"| Thuc te: " << setw(40) <<soNgayThucTe << " ngay |\n"
                 << setw(13)<<"| Tien goc: " << fixed << setprecision(0) <<setw(40)<< tienGoc << " VND |\n";
            if (tienPhat > 0) {
                cout << left
				     <<setw(17) << "| Phat tre han (" << (soNgayThucTe - temp->soNgayThue) << " ngay x 150%): "<<setw(20) << tienPhat << " VND |\n";
            } else {
                cout << left
				     << setw(26) << "| Tinh trang: Tra dung han ";
				cout << left
				     <<setw(28)<<"|\n";
            }
            cout << left
			     << setw(13) << "| TONG THU: ";
			cout << left     
		         << setw(40)<<temp->tongTien << " VND |\n";
            cout <<"+" <<setfill('-') << setw(57) <<'-' << setfill(' ')<<"+"  <<"\n";

            return true;
        }
        temp = temp->next;
    }

    cout << "\n[ERROR] Khong tim thay ma phieu: " << maPhieu << endl;
    return false;
}