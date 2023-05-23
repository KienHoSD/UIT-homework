#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;
class Point {
private:
	float tungdo;
	float hoanhdo;
public:
	Point();
	~Point();
	void NhapDiem();
	void XuatDiem();
	float LayHoanhDo();
	float LayTungDo();
	void TinhTien();
	void VeDiem();
	void VeTrucToaDo();
};
Point::~Point() {
	getch();
	closegraph();
}
void Point::VeTrucToaDo() {
	int TamX = int(getmaxx() / 2) + 1; // toa do x cua tam O
	int TamY = int(getmaxy() / 2) + 1; // toa do y cua tam O
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); // Ve truc Oy
	line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); // Ve truc Ox
	// Ve cac cham don vi tam O
	for (int i = TamY; i <= getmaxy(); i += 50) {
		setfillstyle(SOLID_FILL, WHITE);
		circle(getmaxx() / 2, i, 2);
	}
	for (int i = TamY; i >= 0; i -= 50) {
		setfillstyle(SOLID_FILL, WHITE);
		circle(getmaxx() / 2, i, 2);
	}
	for (int j = TamX; j <= getmaxx(); j += 50) {
		setfillstyle(SOLID_FILL, WHITE);
		circle(j, getmaxy() / 2, 2);
	}
	for (int j = TamX; j >= 0; j -= 50) {
		setfillstyle(SOLID_FILL, WHITE);
		circle(j, getmaxy() / 2, 2);
	}
}
void Point::NhapDiem() {
	do {
		cout << "Nhap hoanh do (x) cua diem: ";
		cin >> hoanhdo;
		cout << "Nhap tung do (y) cua diem: ";
		cin >> tungdo;
		if (hoanhdo > 11 || tungdo > 11) cout << "Nhap lai: " << '\n';
	} while (hoanhdo > 11 || tungdo > 11);
	VeDiem();
}
Point::Point() {
	initwindow(1200, 800, "Draw a point", 50, 50, false, true);
	tungdo = 0;
	hoanhdo = 0;
	VeTrucToaDo();
}
void Point::XuatDiem() {
	cout << "Hoanh do cua diem la: " << hoanhdo << endl;
	cout << "Tung do cua diem la: " << tungdo << endl;
}
float Point::LayHoanhDo() {
	return hoanhdo;
}
float Point::LayTungDo() {
	return tungdo;
}
void Point::TinhTien() {
	do {
		float x, y;
		cout << "Nhap vecto de tinh tien: ";
		cin >> x >> y;
		hoanhdo = hoanhdo + x;
		tungdo = tungdo + y;
		if (hoanhdo > 11 || tungdo > 11) cout << "Diem tinh tien da vuot ngoai pham vi hien thi. Vui long nhap lai vecto tinh tien." << '\n';
	} while (hoanhdo > 11 || tungdo > 11);
	cout << "Diem sau khi da tinh tien la: " << '\n';
	clearviewport();
	VeTrucToaDo();
	XuatDiem();
	VeDiem();
}
void Point::VeDiem() {
	int TamX = int(getmaxx() / 2) + 1;
	int TamY = int(getmaxy() / 2) + 1;
	//Thiet lap vi tri diem 
	int x = int(hoanhdo * 50 + TamX);
	int y = int(-tungdo * 50 + TamY);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(x, y, 5);
	floodfill(x, y, WHITE);
}
int main()
{
	Point a;
	a.NhapDiem();
	a.TinhTien();
	return 0;
}