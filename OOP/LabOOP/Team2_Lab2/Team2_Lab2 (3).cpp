#include <iostream>
#include <vector>
#include <algorithm>
#include "graphics.h"
#pragma comment (lib,"graphics.lib")
using namespace std;


class Point {
private:
	double x, y;
	friend class DaGiac;
public:
	Point();
	~Point();
	void TinhTien(double X, double Y);
	void Quay(int gocquay);
	void PhongTo(double k);
	void ThuNho(double k);
};


Point::Point() {
	x = 0;
	y = 0;
}
Point::~Point() { }
void Point::Quay(int gocquay) {
	Point quay;
	double radian = (gocquay * 3.14159) / 180;
	quay.x = x;
	quay.y = y;
	x = quay.x * cos(radian) - quay.y * sin(radian);
	y = quay.x * sin(radian) + quay.y * cos(radian);
}
void Point::TinhTien(double X, double Y) {
	x = x + X;
	y = y + Y;
}
void Point::PhongTo(double k) {
	x = x * k;
	y = y * k;
}
void Point::ThuNho(double k) {
	x = x / k;
	y = y / k;
}


class DaGiac {
private:
	int TongDiem;
	Point* A;
public:
	DaGiac();
	~DaGiac();
	void VeTrucToaDo();
	void NhapDaGiac();
	void XuatDuLieuDaGiac();
	void TinhTienDaGiac();
	void QuayDaGiac();
	void PhongToDaGiac();
	void ThuNhoDaGiac();
	void VeDaGiac();
	void VeTrucToaDoVaDaGiac();
	void sortPointsByAngle(vector<Point>& points);
};

bool compareAngles(const std::pair<float, Point>& a, const std::pair<float, Point>& b) {
	return a.first < b.first;
}

void DaGiac::sortPointsByAngle(vector<Point>& points) {
	// Tinh toan toa do trung binh cua tat ca cac diem
	Point average;
	for (const auto& p : points) {
		average.x += p.x;
		average.y += p.y;
	}
	average.x /= points.size();
	average.y /= points.size();

	// tinh toan cac goc va luu vao thanh tung cap trong vector
	std::vector<std::pair<float, Point>> angles;
	for (const auto& p : points) {
		double dx = p.x - average.x;
		double dy = p.y - average.y;
		double angle = atan2f(dy, dx);
		angles.emplace_back(angle, p);
	}

	// sort cac diem boi goc cua chung
	sort(angles.begin(), angles.end(), compareAngles);

	// luu lai cac diem da sort vao vector ban dau
	for (size_t i = 0; i < points.size(); i++) {
		points[i] = angles[i].second;
	}
}

void DaGiac::VeTrucToaDo() {
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
void DaGiac::VeTrucToaDoVaDaGiac() {
	clearviewport();
	VeTrucToaDo();
	VeDaGiac();
}
DaGiac::DaGiac() {
	TongDiem = 0;
	A = new Point[TongDiem];
	initwindow(1000, 800, "Draw a polygon", 50, 50);
	VeTrucToaDo();
}
DaGiac::~DaGiac() {
	getch();
	closegraph();
	for (int i = 0; i < TongDiem; i++) {
		A[i].x = NULL;
		A[i].y = NULL;
	}
	delete[] A;
}
void DaGiac::VeDaGiac() {
	int tamOx = int(getmaxx() / 2);
	int tamOy = int(getmaxy() / 2);
	vector<Point> temp;
	// truyền mảng động Point A vào vector Point temp
	for (int i = 0; i < TongDiem; i++) temp.push_back(A[i]);
	// sort các điểm trong vector temp bởi góc của chúng với trục toạ độ Oxy
	sortPointsByAngle(temp);
	vector <int> Ve;
	for (int j = 0; j < TongDiem; j++) {
		int tempx = int(temp[j].x * 50 + tamOx);
		int tempy = int(-temp[j].y * 50 + tamOy);
		Ve.push_back(tempx);
		Ve.push_back(tempy);
	}
	Ve.push_back(int(temp[0].x * 50 + tamOx));
	Ve.push_back(int(-temp[0].y * 50 + tamOy));
	int* arr = Ve.data();
	drawpoly(TongDiem + 1, arr);
}
void DaGiac::NhapDaGiac() {
	do {
		cout << "Nhap so luong diem da giac: ";
		cin >> TongDiem;
		if (TongDiem < 3) cout << "Vui long nhap lai so luong diem da giac: ";
	} while (TongDiem < 3);
	int tamOx = int(getmaxx() / 2);
	int tamOy = int(getmaxy() / 2);
	for (int i = 0; i < TongDiem; i++) {
		cout << "Nhap toa do diem thu " << i + 1 << ": ";
		cin >> A[i].x >> A[i].y;
		circle(A[i].x * 50 + tamOx, -A[i].y * 50 + tamOy, 2);
	}
	VeDaGiac();
}
void DaGiac::XuatDuLieuDaGiac() {
	for (int i = 0; i < TongDiem; i++) {
		cout << "Toa do diem thu " << i + 1 << " la: " << A[i].x << " " << A[i].y << endl;
	}
}
void DaGiac::TinhTienDaGiac() {
	double x, y;
	cout << "Nhap vector tinh tien: ";
	cin >> x >> y;
	for (int i = 0; i < TongDiem; i++)
		A[i].TinhTien(x, y);
	XuatDuLieuDaGiac();
	VeTrucToaDoVaDaGiac();
}
void DaGiac::QuayDaGiac() {
	int gocquay;
	cout << "Nhap goc quay cua da giac: ";
	cin >> gocquay;
	for (int i = 0; i < TongDiem; i++)
		A[i].Quay(gocquay);
	XuatDuLieuDaGiac();
	VeTrucToaDoVaDaGiac();
}
void DaGiac::PhongToDaGiac() {
	double k;
	cout << "Nhap do phong to da giac: ";
	cin >> k;
	while (k < 1) {
		cout << "Nhap lai do phong to da giac: ";
		cin >> k;
	}
	for (int i = 0; i < TongDiem; i++)
		A[i].PhongTo(k);
	XuatDuLieuDaGiac();
	VeTrucToaDoVaDaGiac();
}
void DaGiac::ThuNhoDaGiac() {
	double k;
	cout << "Nhap do thu nho da giac: ";
	cin >> k;
	while (k < 1) {
		cout << "Nhap lai do thu nho da giac: ";
		cin >> k;
	}
	for (int i = 0; i < TongDiem; i++)
		A[i].ThuNho(k);
	XuatDuLieuDaGiac();
	VeTrucToaDoVaDaGiac();
}


int main()
{
	DaGiac a;
	a.NhapDaGiac();
	a.TinhTienDaGiac();
	a.QuayDaGiac();
	a.PhongToDaGiac();
	a.ThuNhoDaGiac();
	return 0;
}
