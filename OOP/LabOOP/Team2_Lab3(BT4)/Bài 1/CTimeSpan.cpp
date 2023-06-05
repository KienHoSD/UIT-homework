#include <iostream>
#include "CTimeSpan.h"
using namespace std;
CTimeSpan::CTimeSpan() {
	Gio = 0;
	Phut = 0;
	Giay = 0;
}
void CTimeSpan::NhapThoiGian() {
		cout << "Nhap gio: ";
		cin >> Gio;
		cout << "Nhap phut: ";
		cin >> Phut;
		cout << "Nhap giay: ";
		cin >> Giay;
}
void CTimeSpan::XuatThoiGian() {
	while (Giay >= 60) {
		Giay = Giay - 60;
		Phut++;
	}
	while (Phut >= 60) {
		Phut = Phut - 60;
		Gio++;
	}
	cout << Gio << " gio " << Phut << " phut " << Giay << " giay " << endl;
}
int CTimeSpan::QuyDoiThoiGian() {
	int Time = Gio * 3600 + Phut * 60 + Giay;
	return Time;
}
CTimeSpan CTimeSpan::SecondToTime(int giay) {
	CTimeSpan ChuyenDoi;
	ChuyenDoi.Gio = giay / 3600;
	ChuyenDoi.Phut = (giay % 3600) / 60;
	ChuyenDoi.Giay = (giay % 3600) % 60;
	return ChuyenDoi;
}
void CTimeSpan::CongThoiGian(CTimeSpan B) {
	CTimeSpan result;
	result.Gio = Gio + B.Gio;
	result.Phut = Phut + B.Phut;
	result.Giay = Giay + B.Giay;
	cout << "Tong thoi gian la: ";
	result.XuatThoiGian();
}
void CTimeSpan::TruThoiGian(CTimeSpan B) {
	int Time1 = this->QuyDoiThoiGian();
	int Time2 = B.QuyDoiThoiGian();
	int subtract = abs(Time1 - Time2);
	CTimeSpan result = SecondToTime(subtract);
	cout << "Hieu thoi gian la: ";
	result.XuatThoiGian();
}
void CTimeSpan::BangNhau(CTimeSpan B) {
	int Time1 = this->QuyDoiThoiGian();
	int Time2 = B.QuyDoiThoiGian();
	if (Time1 == Time2) cout << "Hai thoi gian bang nhau la dung." << endl;
	else cout << "Hai thoi gian bang nhau la sai." << endl;
}
void CTimeSpan::KhacNhau(CTimeSpan B) {
	int Time1 = this->QuyDoiThoiGian();
	int Time2 = B.QuyDoiThoiGian();
	if (Time1 != Time2) cout << "Hai thoi gian khac nhau la dung." << endl;
	else cout << "Hai thoi gian khac nhau la sai." << endl;
}
void CTimeSpan::LonHon(CTimeSpan B) {
	int Time1 = this->QuyDoiThoiGian();
	int Time2 = B.QuyDoiThoiGian();
	if (Time1 > Time2) cout << "Thoi gian thu nhat lon hon thoi gian thu hai la dung." << endl;
	else cout << "Thoi gian thu nhat lon hon thoi gian thu hai la sai." << endl;
}
void CTimeSpan::LonHonHoacBang(CTimeSpan B) {
	int Time1 = this->QuyDoiThoiGian();
	int Time2 = B.QuyDoiThoiGian();
	if (Time1 >= Time2) cout << "Thoi gian thu nhat lon hon hoac bang thoi gian thu hai la dung." << endl;
	else cout << "Thoi gian thu nhat lon hon hoac bang thoi gian thu hai la sai." << endl;
}
void CTimeSpan::NhoHon(CTimeSpan B) {
	int Time1 = this->QuyDoiThoiGian();
	int Time2 = B.QuyDoiThoiGian();
	if (Time1 < Time2) cout << "Thoi gian thu nhat nho hon thoi gian thu hai la dung." << endl;
	else cout << "Thoi gian thu nhat nho hon thoi gian thu hai la sai." << endl;
}
void CTimeSpan::NhoHonHoacBang(CTimeSpan B) {
	int Time1 = this->QuyDoiThoiGian();
	int Time2 = B.QuyDoiThoiGian();
	if (Time1 <= Time2) cout << "Thoi gian thu nhat nho hon hoac bang thoi gian thu hai la dung." << endl;
	else cout << "Thoi gian thu nhat nho hon hoac bang thoi gian thu hai la sai." << endl;
}