#include <iostream>
#include <vector>
#include "DaThuc.h"
using namespace std;
int main()
{
	double x,y;
	DaThuc A, B;
	cout << "Nhap da thuc A(x) :" << endl;
	A.NhapDaThuc();
	cout << "Nhap da thuc B(x): " << endl;
	B.NhapDaThuc();
	A.CongDaThuc(B);
	A.TruDaThuc(B);
	A.NhanDaThuc(B);
	A.ChiaDaThuc(B);
	cout << "Nhap x de tinh gia tri cua da thuc A: ";
	cin >> x;
	cout << "Gia tri cua da thuc A khi x = " << x << " la: ";
	A.GiaTriDonThuc(x);
	cout << "Nhap x de tinh gia tri cua da thuc B: ";
	cin >> y;
	cout << "Gia tri cua da thuc B khi x = " << x << " la: ";
	B.GiaTriDonThuc(y);
}

