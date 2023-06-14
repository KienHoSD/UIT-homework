#include <iostream>
#include "CTime.h"
#include <cmath>
using namespace std;
CTime::CTime() {
	Gio = Phut = Giay = 0;
}
void CTime::NhapThoiGian() {
	do {
		cout << "Nhap gio: ";
		cin >> Gio;
		cout << "Nhap phut: ";
		cin >> Phut;
		cout << "Nhap giay: ";
		cin >> Giay;
		if (Giay < 0 || Giay>60 || Phut < 0 || Phut>60 || Gio < 0 || Gio>24) cout << "Vui long nhap lai thoi gian." << endl;
	} while (Giay < 0 || Giay>60 || Phut < 0 || Phut>60 || Gio < 0 || Gio>24);
}
void CTime::XuatThoiGian() {
	CTime result = *this;
	while (result.Giay >= 60) {
		result.Giay = result.Giay - 60;
		result.Phut++;
	}
	while (result.Phut >= 60) {
		result.Phut = result.Phut - 60;
		result.Gio++;
	}
	while (result.Gio >= 24) {
		result.Gio = result.Gio - 24;
	}
	cout << result.Gio << " gio " << result.Phut << " phut " << result.Giay << " giay " << endl;
}
CTime CTime::ChuyenDoiThoiGian(int giay) {
	CTime ChuyenDoi;
	ChuyenDoi.Gio = giay / 3600;
	ChuyenDoi.Phut = (giay % 3600) / 60;
	ChuyenDoi.Giay = (giay % 3600) % 60;
	return ChuyenDoi;
}
int CTime::TimeToSeconds() {
	int result = Gio * 3600 + Phut * 60 + Giay;
	return result;
}
void CTime::CongMotSoNguyenGiay() {
	int seconds;
	cout << "Nhap mot so nguyen (giay) de cong vao: ";
	cin >> seconds;
	CTime ThoiGian2 = ChuyenDoiThoiGian(seconds);
	Gio = Gio + ThoiGian2.Gio;
	Phut = Phut + ThoiGian2.Phut;
	Giay = Giay + ThoiGian2.Giay;
	cout << "Thoi gian sau khi cong " << seconds << " giay la: ";
	this->XuatThoiGian();
}
void CTime::TruMotSoNguyenGiay() {
	int seconds;
	int seconds2 = this->TimeToSeconds();
	cout << "Nhap mot so nguyen (giay) de tru ra: ";
	cin >> seconds;
	int result = seconds2 - seconds;
	if (result < 0) result = result + int(86400 * ceil((-result) * 1.0 / 86400));
	*this = ChuyenDoiThoiGian(result);
	cout << "Thoi gian sau khi tru " << seconds << " giay la: ";
	this->XuatThoiGian();
}
CTimeSpan CTime::TruHaiThoiGian() {
	CTimeSpan ThoiGian1,ThoiGian2, result;
	cout << "Nhap moc thoi gian thu 2:" << endl;
	ThoiGian2.NhapThoiGian();
	ThoiGian1 = CTimeSpan(this->Gio, this->Phut, this->Giay);
	result = ThoiGian1.TruThoiGian(ThoiGian2);
	return result;
}
void CTime::ThemMotGiay() {
	this->Giay++;
	cout << "Thoi gian sau khi them 1 giay: ";
	this->XuatThoiGian();
}
void CTime::GiamMotGiay() {
	this->Giay--;
	cout << "Thoi gian sau khi giam 1 giay: ";
	this->XuatThoiGian();
}
