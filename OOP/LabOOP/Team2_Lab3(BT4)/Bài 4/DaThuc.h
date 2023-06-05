#pragma once
#include <iostream>
#include <vector>
using namespace std;
struct DonThuc {
	double BacDaThuc;
	double HeSo;
};
class DaThuc {
private:
	DonThuc a;
	vector <DonThuc> DaySo;
public:
	DaThuc();
	void NhapDaThuc();
	void XuatDaThuc();
	void CongDaThuc(DaThuc B);
	void TruDaThuc(DaThuc B);
	void NhanDaThuc(DaThuc B);
	void ChiaDaThuc(DaThuc B);
	void GiaTriDonThuc(double x);
};