#include <iostream>
#include "CTime.h"
using namespace std;
int main()
{
	CTime ThoiGian;
	CTimeSpan Tru;
	cout << "Nhap moc thoi gian thu nhat: " << '\n';
	ThoiGian.NhapThoiGian();
	ThoiGian.CongMotSoNguyenGiay();
	ThoiGian.TruMotSoNguyenGiay();
	Tru = ThoiGian.TruHaiThoiGian();
	cout << "Khoang cach cua hai moc thoi gian: ";
	Tru.XuatThoiGian();
	ThoiGian.ThemMotGiay();
	ThoiGian.GiamMotGiay();
	return 0;
}
