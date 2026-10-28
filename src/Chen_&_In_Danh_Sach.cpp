#include <iostream>
#include <string>
#include <iomanip>
#include "../include/khungsuoncode.h"
using namespace std;

string tree::DanhGiaDoUaChuong(const ThongTinDia dia){
	int diem = dia.soLuotThue + dia.soLuotBan*2;
	if(diem >= 100) return "Sieu Hot";
	if(diem >= 30) return "Binh Thuong";
	return "E Am";
}
string tree::DeXuatNhapHang(const ThongTinDia dia){
	if(dia.soLuongTon <= dia.dinhMucToiThieu){
		string xephang= DanhGiaDoUaChuong(dia);
		if(xephang== "Sieu Hot") return "nhap hang gap";
		if(xephang == "E Am") return "Xa Kho";
		return "Nhap It";
	}
	return "Ton Kho An Toan";
}
string tree::LaChinhHang(const ThongTinDia dia){
	if(!dia.ChinhHang) return "Khong la Chinh Hang";
	return "La chinh Hang";
}
void tree::ThemDiaMoi(ThongTinDia dia){
	root = ThemDiaMoi(root, dia);
}
void tree::DanhSachKhoDia(){
	if(root== NULL){
		cout<< "\n -hien tai danh sach kho dang trong!";
		return;
	}
	cout << setfill('-')<< setw(154)<< "-"<< setfill(' ')<<"\n";
	cout << left
	     << setw(8) << "|maDia"
	     << setw(17) << "|TenDia"
	     << setw(15) << "|Nha cung cap"
	     << setw(11) << "|Tinh trang"
	     << setw(21) << "|Xuat su"
	     << setw(6) << "|ton"
	     << setw(8) << "|Han muc"
	     << setw(9) << "|Gia thue"
	     << setw(8) << "|thi truong"
	     << setw(8) << "|So thue"
	     << setw(7) << "|So ban"
	     << setw(13) << "|Do Ua Chuong"
	     << setw(19) << "|De xuat nhap hang"<< "|"<<"\n";
	cout << setfill('-')<< setw(154)<< "-"<< setfill(' ')<<"\n";
	DanhSachKhoDia(root);
	cout << setfill('-')<< setw(154)<< "-"<< setfill(' ')<<"\n";
}
