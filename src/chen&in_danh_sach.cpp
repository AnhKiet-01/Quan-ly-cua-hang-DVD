#include<iostream>
#include<string>
using namespace std;
#include "..\include\khungsuoncode.h"

string DanhGiaDoUaChuong (const ThongTinDia dia){
	int diem = dia.soLuotThue + dia.soLuotBan*2;
	if(diem >= 100) return "\nSieu Hot";
	if(diem >= 30) return "\nBinh Thuong";
	return "\nE Am";
}
string DeXuatNhapHang(const ThongTinDia dia){
	if(dia.soLuongTon <= dia.dinhMucToiThieu){
		string xephang= DanhGiaDoUaChuong();
		if(xephang== "Sieu Hot") return "\n nhap hang gap";
		if(xephang == "E Am") return "\n Xa Kho";
		return "\n Nhap It";
	}
	return "\n Ton Kho An Toan";
	
}
string LaChinhHang(const ThongTinDia dia){
	if(ChinhHang) return "\n la Chinh Hang";
}
int main(){
	tree t;
	
	cout<< "\n do ua chuong: "<<t.DanhGiaDoUaChuong ();
}