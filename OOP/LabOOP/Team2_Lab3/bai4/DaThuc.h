#pragma once
#include <iostream>
#include <vector>
using namespace std;
struct DonThuc {
	int BacDaThuc;
	int HeSo;
};
class DaThuc {
private:
	DonThuc a;
	vector <DonThuc> DaySo;
	DaThuc RutGonDaThuc();
public:
	DaThuc();
	void NhapDaThuc();
	void XuatDaThuc();
	void CongDaThuc(DaThuc B);
	void TruDaThuc(DaThuc B);
	DaThuc TruDaThucTravaDaThuc(DaThuc B);
	void NhanDaThuc(DaThuc B);
	DaThuc NhanDaThucTraveDaThuc(DaThuc B);
	void ChiaDaThuc(DaThuc B);
	void GiaTriDonThuc(double x);
};