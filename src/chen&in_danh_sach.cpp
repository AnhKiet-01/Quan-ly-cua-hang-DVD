#include<iostream>
#include "..\include\khungsuoncode.h"

string DanhGiaDoUaChuong (const ThongTinDia dia){
	int diem = dia.soLuotThue + dia.soLuotBan*2;
	if(diem >= 100) return "\nSieu Hot";
	if(diem >= 30) return "\nBinh Thuong";
	return "\nE Am";
}

int main(){
	tree t;
	cout<< "\n do ua chuong: "<<t->DanhGiaDoUaChuong (const ThongTinDia dia);
}