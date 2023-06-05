#pragma once
#include <iostream>
using namespace std;
class CTimeSpan{
private:
	int Gio;
	int Phut;
	int Giay;
	int QuyDoiThoiGian();
	CTimeSpan SecondToTime(int giay);
public:
	CTimeSpan();
	void NhapThoiGian();
	void XuatThoiGian();
	void CongThoiGian(CTimeSpan B);
	void TruThoiGian(CTimeSpan B);
	void BangNhau(CTimeSpan B);
	void KhacNhau(CTimeSpan B);
	void LonHon(CTimeSpan B);
	void LonHonHoacBang(CTimeSpan B);
	void NhoHon(CTimeSpan B);
	void NhoHonHoacBang(CTimeSpan B);
};

