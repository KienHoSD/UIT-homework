#include <iostream>
#include "graphics.h"
#pragma comment (lib,"graphics.lib")
using namespace std;
class Point {
private:
	float x, y;
	friend class DaGiac;
public:
	Point();
	void TinhTien(float X, float Y);
	void Quay(float gocquay);
	void PhongTo(float k);
	void ThuNho(float k);
};
Point::Point() {
	x = 0;
	y = 0;
}
void Point::Quay(float gocquay) {
	double radian = (gocquay * 3.14159265359) / 180;
	double resultx, resulty;
	resultx = x * cos(radian) - y * sin(radian);
	resulty = x * sin(radian) + y * cos(radian);
	cout << resultx << " " << resulty;
}
void Point::TinhTien(float X, float Y) { 
	x = x + X;
	y = y + Y;
	cout << x << " " << y;
}
void Point::PhongTo(float k) {
	x = x * k;
	y = y * k;
	cout << x << " " << y;
}
void Point::ThuNho(float k) {
	x = x / k;
	y = y / k;
	cout << x << " " << y;
}
class DaGiac {
private:
	int TongDiem;
	Point* A;
public:
	DaGiac();
	~DaGiac();
	void NhapDaGiac();
	void XuatDaGiac();
	void TinhTienDaGiac();
	void QuayDaGiac();
	void PhongToDaGiac();
	void ThuNhoDaGiac();
	void VeDaGiac();
};
DaGiac::DaGiac() {
	TongDiem = 0;
	A = new Point[TongDiem];
}
DaGiac::~DaGiac() {
}
void DaGiac::NhapDaGiac() {
	do {
		cout << "Nhap so luong diem da giac: ";
		cin >> TongDiem;
		if (TongDiem < 3) cout << "Vui long nhap lai so luong diem da giac: ";
	} while (TongDiem < 3);
	for (int i = 0; i < TongDiem; i++) {
		cout << "Nhap toa do diem thu " << i + 1 << ": ";
		cin >> A[i].x >> A[i].y;
	}
}
void DaGiac::XuatDaGiac() {
	for (int i = 0; i < TongDiem; i++) {
		cout << "Toa do diem thu " << i + 1 << "la: " << A[i].x << " " << A[i].y << endl;
	}
}
void DaGiac::TinhTienDaGiac() {
	float x, y;
	cout << "Nhap vector tinh tien: ";
	cin >> x >> y;
	for (int i = 0; i < TongDiem; i++) {
		cout << "Toa do diem thu " << i + 1 << "sau khi tinh tien (" << x << "," << y << ") la: ";
		A[i].TinhTien(x, y);
		cout << endl;
	}
}
void DaGiac::QuayDaGiac() {
	float gocquay;
	cout << "Nhap goc quay cua da giac: ";
	cin >> gocquay;
	for (int i = 0; i < TongDiem; i++) {
		cout << "Toa do diem thu " << i + 1 << "sau khi quay goc " << gocquay << "la: ";
		A[i].Quay(gocquay);
		cout << endl;
	}
}
void DaGiac::PhongToDaGiac() {
	float k;
	cout << "Nhap do phong to da giac: ";
	cin >> k;
	while (k < 1) {
		cout << "Nhap lai do phong to da giac: ";
		cin >> k;
	}
	for (int i = 0; i < TongDiem; i++) {
		cout << "Toa do diem thu " << i + 1 << "sau khi phong to " << k << " lan la: ";
		A[i].PhongTo(k);
		cout << endl;
	}
}
void DaGiac::ThuNhoDaGiac() {
	float k;
	cout << "Nhap do thu nho da giac: ";
	cin >> k;
	while (k < 1) {
		cout << "Nhap lai do thu nho da giac: ";
		cin >> k;
	}
	for (int i = 0; i < TongDiem; i++) {
		cout << "Toa do diem thu " << i + 1 << "sau khi thu nho " << k << " lan la: ";
		A[i].ThuNho(k);
		cout << endl;
	}
}
void DaGiac::VeDaGiac() {
	//Thiet lap giao dien ve:
	initwindow(1000, 800, "Draw a polygon", 50, 50, false, true);
	//Ve da giac:
	int* Ve = new int[TongDiem * 2 + 2];
	int n = TongDiem * 2;
	Ve[TongDiem * 2 + 1] = int(A[0].y);
	Ve[TongDiem * 2 ] = int(A[0].x);
	for (int i = 1, j = 0; i < n; i = i + 2, j++) {
		Ve[i - 1] = int(A[j].x);
		Ve[i] = int(A[j].y);
	}
	setlinestyle(0, 0, 5);//Thiet lap do day cua duong ve
	drawpoly(TongDiem + 1, Ve);
	getch();
	closegraph();
	delete[] Ve;
}
int main()
{
	DaGiac a;
	a.NhapDaGiac();
	a.TinhTienDaGiac();
	a.QuayDaGiac();
	a.PhongToDaGiac();
	a.ThuNhoDaGiac();
	a.XuatDaGiac();
	a.VeDaGiac();
	return 0;
}
