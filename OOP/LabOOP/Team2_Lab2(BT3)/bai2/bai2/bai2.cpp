#include <iostream>
#include <cmath>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;


class Point {
private:
	double x;
	double y;
	friend class Triangle;
public:
	Point();
	~Point();
	void TinhTien(double X, double Y);
	void Quay(int goc);
	void ThuPhong(double k);
	void ThuNho(double k);
};

Point::Point() {
	x = 0;
	y = 0;
}
Point::~Point() { }
void Point::TinhTien(double X, double Y) {
	x = x + X;
	y = y + Y;
}
void Point::Quay(int goc) {
	Point quay;
	double radian = (goc * 3.14159) / 180;
	quay.x = x;
	quay.y = y;
	x = quay.x * cos(radian) - quay.y * sin(radian);
	y = quay.x * sin(radian) + quay.y * cos(radian);
}
void Point::ThuPhong(double k) {
	x = x * k;
	y = y * k;
}
void Point::ThuNho(double k) {
	x = x / k;
	y = y / k;
}



class Triangle {
private:
	Point A, B, C;
public:
	Triangle();
	~Triangle();
	void Nhap3DinhTamGiac();
	void XuatDuLieu3DinhTamGiac();
	void TinhTienTamGiac();
	void QuayTamGiac();
	void PhongToTamGiac();
	void ThuNhoTamGiac();
	void VeTrucToaDo();
	void VeTamGiac();
};




Triangle::Triangle() {
	initwindow(1000, 800, "Draw a triangle", 50, 50);
	VeTrucToaDo();
}
void Triangle::VeTrucToaDo() {
	int tamOx = int(getmaxx() / 2); // toa do x cua tam O
	int tamOy = int(getmaxy() / 2); // toa do y cua tam O
	line(tamOx, 0, tamOx, getmaxy()); // Ve truc Oy
	line(0, tamOy, getmaxx(), tamOy); // Ve truc Ox
	// Ve cac cham don vi tam O
	for (int i = tamOy; i <= getmaxy(); i += 50) {
		setfillstyle(SOLID_FILL, WHITE);
		circle(tamOx, i, 2);
	}
	for (int i = tamOy; i >= 0; i -= 50) {
		setfillstyle(SOLID_FILL, WHITE);
		circle(tamOx, i, 2);
	}
	for (int j = tamOx; j <= getmaxx(); j += 50) {
		setfillstyle(SOLID_FILL, WHITE);
		circle(j, tamOy, 2);
	}
	for (int j = tamOx; j >= 0; j -= 50) {
		setfillstyle(SOLID_FILL, WHITE);
		circle(j, tamOy, 2);
	}
}
Triangle::~Triangle() {
	getch();
	closegraph();
}
void Triangle::Nhap3DinhTamGiac() {
	double AB, AC, BC;
	int tamOx = int(getmaxx() / 2); // toa do x cua tam O
	int tamOy = int(getmaxy() / 2); // toa do y cua tam O
	do {
		cout << "Nhap toa do diem A: ";
		cin >> A.x >> A.y;
		circle(tamOx + A.x * 50, tamOy - A.y * 50, 2);
		cout << "Nhap toa do diem B: ";
		cin >> B.x >> B.y;
		circle(tamOx + B.x * 50, tamOy - B.y * 50, 2);
		cout << "Nhap toa do diem C: ";
		cin >> C.x >> C.y;
		circle(tamOx + C.x * 50, tamOy - C.y * 50, 2);
		AB = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2)); // Tinh canh AB
		AC = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2)); // Tinh canh AC
		BC = sqrt(pow(B.x - C.x, 2) + pow(B.y - C.y, 2)); // Tinh canh BC
		if (AB + AC <= BC || AB + BC <= AC || AC + BC <= AB) {
			clearviewport();
			VeTrucToaDo();
			cout << "Nhap lai toa do 3 diem: " << endl;
		}
	} while (AB + AC <= BC || AB + BC <= AC || AC + BC <= AB);
	VeTamGiac();
}
void Triangle::XuatDuLieu3DinhTamGiac() {
	cout << "Toa do diem A la: " << A.x << " " << A.y << endl;
	cout << "Toa do diem B la: " << B.x << " " << B.y << endl;
	cout << "Toa do diem C la: " << C.x << " " << C.y << endl;
}
void Triangle::VeTamGiac() {
	int tamOx = int(getmaxx() / 2);
	int tamOy = int(getmaxy() / 2);
	line(int(A.x * 50 + tamOx), int(-A.y * 50 + tamOy), int(B.x * 50 + tamOx), int(-B.y * 50 + tamOy));
	line(int(A.x * 50 + tamOx), int(-A.y * 50 + tamOy), int(C.x * 50 + tamOx), int(-C.y * 50 + tamOy));
	line(int(B.x * 50 + tamOx), int(-B.y * 50 + tamOy), int(C.x * 50 + tamOx), int(-C.y * 50 + tamOy));
}

void Triangle::TinhTienTamGiac() {
	double a, b;
	cout << "Nhap vecto tinh tien: ";
	cin >> a >> b;
	A.TinhTien(a, b);
	B.TinhTien(a, b);
	C.TinhTien(a, b);
	XuatDuLieu3DinhTamGiac();
	clearviewport();
	VeTrucToaDo();
	VeTamGiac();
}
void Triangle::QuayTamGiac() {
	int gocquay;
	cout << "Nhap goc quay tam giac (do) : ";
	cin >> gocquay;
	A.Quay(gocquay);
	B.Quay(gocquay);
	C.Quay(gocquay);
	XuatDuLieu3DinhTamGiac();
	clearviewport();
	VeTrucToaDo();
	VeTamGiac();
}
void Triangle::PhongToTamGiac() {
	double phongto;
	cout << "Nhap do phong to: ";
	cin >> phongto;
	while (phongto < 1) {
		cout << "Nhap lai do phong to: ";
		cin >> phongto;
	}
	A.ThuPhong(phongto);
	B.ThuPhong(phongto);
	C.ThuPhong(phongto);
	XuatDuLieu3DinhTamGiac();
	clearviewport();
	VeTrucToaDo();
	VeTamGiac();
}
void Triangle::ThuNhoTamGiac() {
	double thunho;
	cout << "Nhap do thu nho: ";
	cin >> thunho;
	while (thunho < 1) {
		cout << "Nhap lai do thu nho: ";
		cin >> thunho;
	}
	A.ThuNho(thunho);
	B.ThuNho(thunho);
	C.ThuNho(thunho);
	XuatDuLieu3DinhTamGiac();
	clearviewport();
	VeTrucToaDo();
	VeTamGiac();
}


int main() {
	Triangle A;
	A.Nhap3DinhTamGiac();
	A.TinhTienTamGiac();
	A.QuayTamGiac();
	A.PhongToTamGiac();
	A.ThuNhoTamGiac();
	return 0;
}
