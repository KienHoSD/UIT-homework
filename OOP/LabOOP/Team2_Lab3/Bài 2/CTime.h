#pragma once
#include <iostream>
using namespace std;
class CTimeSpan {
private:
	int Gio;
	int Phut;
	int Giay;
	int QuyDoiThoiGian();
	CTimeSpan SecondToTime(int giay);
public:
	CTimeSpan(int hours = 0, int minutes = 0, int seconds = 0) {
		Gio = hours;
		Phut = minutes;
		Giay = seconds;
	}
	void NhapThoiGian();
	void XuatThoiGian();
	void CongThoiGian(CTimeSpan B);
	CTimeSpan TruThoiGian(CTimeSpan B);
	void BangNhau(CTimeSpan B);
	void KhacNhau(CTimeSpan B);
	void LonHon(CTimeSpan B);
	void LonHonHoacBang(CTimeSpan B);
	void NhoHon(CTimeSpan B);
	void NhoHonHoacBang(CTimeSpan B);
};
class CTime {
private:
	int Gio;
	int Phut;
	int Giay;
	CTime ChuyenDoiThoiGian(int giay);
	int TimeToSeconds();
public:
	CTime();
	void NhapThoiGian();
	void XuatThoiGian();
	void CongMotSoNguyenGiay();
	void TruMotSoNguyenGiay();
	CTimeSpan TruHaiThoiGian();
	void ThemMotGiay();
	void GiamMotGiay();
};