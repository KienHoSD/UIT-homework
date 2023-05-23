#include <iostream>
#include "CTimeSpan.h"
using namespace std;
int main() {
	CTimeSpan A, B;
	cout << "Nhap thoi gian thu nhat: " << '\n';
	A.NhapThoiGian();
	cout << "Nhap thoi gian thu hai: " << '\n';
	B.NhapThoiGian();
	A.CongThoiGian(B);
	A.TruThoiGian(B);
	A.BangNhau(B);
	A.KhacNhau(B);
	A.LonHon(B);
	A.LonHonHoacBang(B);
	A.NhoHon(B);
	A.NhoHonHoacBang(B);
	return 0;
}