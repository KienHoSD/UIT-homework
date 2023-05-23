#include <iostream>
#include <cmath>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;


class hinhhoc {
protected:
	double x, y;
public:
	hinhhoc() {
		x = 0; y = 0;
		initwindow(1200, 800, "Draw", 50, 50);
	}
	virtual void Ve() = 0;
	virtual void Nhap() = 0;
	void VeTrucToaDo() {
		int TamX = int(getmaxx() / 2) + 1; // toa do x cua tam O
		int TamY = int(getmaxy() / 2) + 1; // toa do y cua tam O
		line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); // Ve truc Oy
		line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); // Ve truc Ox
		// Ve cac cham don vi tam O
		for (int i = TamY; i <= getmaxy(); i += 25) {
			setfillstyle(SOLID_FILL, WHITE);
			circle(getmaxx() / 2, i, 2);
		}
		for (int i = TamY; i >= 0; i -= 25) {
			setfillstyle(SOLID_FILL, WHITE);
			circle(getmaxx() / 2, i, 2);
		}
		for (int j = TamX; j <= getmaxx(); j += 25) {
			setfillstyle(SOLID_FILL, WHITE);
			circle(j, getmaxy() / 2, 2);
		}
		for (int j = TamX; j >= 0; j -= 25) {
			setfillstyle(SOLID_FILL, WHITE);
			circle(j, getmaxy() / 2, 2);
		}
	}
	void VeDiem() {
		int TamX = int(getmaxx() / 2) + 1;
		int TamY = int(getmaxy() / 2) + 1;
		//Thiet lap vi tri diem 
		int xx = int(x * 25 + TamX);
		int yy = int(-y * 25 + TamY);
		setfillstyle(SOLID_FILL, YELLOW);
		circle(xx, yy, 5);
		floodfill(xx, yy, WHITE);
	}

};

class classEllipse :public hinhhoc {
private:
	double x_rad, y_rad;
public:
	classEllipse() {
		x_rad = 0; y_rad = 0;
		VeTrucToaDo();
	}
	void Nhap() {
		cout << "Nhap lan luot toa do x, y, ban truc lon, ban truc be: ";
		double xx, yy, xx_rad, yy_rad;
		cin >> xx >> yy >> xx_rad >> yy_rad;
		x = xx; y = yy;
		x_rad = xx_rad; y_rad = yy_rad;
		while (x_rad < 0) {
			cout << "ban truc lon khong the la so am!\nvui long nhap lai ban truc lon: ";
			cin >> x_rad;
		}
		while (y_rad < 0) {
			cout << "ban truc be khong the la so am!\nvui long nhap lai ban truc be: ";
			cin >> y_rad;
		}
		VeDiem();
	}
	void Ve() {
		int tamOx = int(getmaxx() / 2);
		int tamOy = int(getmaxy() / 2);
		ellipse(int(x * 25) + tamOx, int(-y * 25) + tamOy, 0, 360, int(x_rad * 25), int(y_rad * 25));
	}
};

class classCircle :public hinhhoc {
private:
	double radius;
public:
	classCircle() {
		radius = 0;

		VeTrucToaDo();
	}
	void Nhap() {
		cout << "Nhap lan luot toa do x, y, ban kinh hinh tron: ";
		double xx, yy, r;
		cin >> xx >> yy >> r;
		while (r < 0) {
			cout << "ban kinh khong the la so am!\nvui long nhap lai ban kinh: ";
			cin >> r;
		}
		x = xx; y = yy; radius = r;
		VeDiem();
	}
	void Ve() {
		int tamOx = int(getmaxx() / 2);
		int tamOy = int(getmaxy() / 2);
		circle(int(x * 25) + tamOx, int(-y * 25) + tamOy, radius * 25);
	}
};
class chuongtrinh {
	hinhhoc* E = nullptr;
	classCircle A;
	classEllipse B;
public:
	chuongtrinh() {
		int option;
		while (true) {
			system("CLS");
			cout << "Nhap hinh muon ve!\n" << "1. Hinh tron\n2. Hinh Ellipse\n3. Don dep man hinh ve\n4. Dung chuong trinh\n";
			cin >> option;
			if (option == 1) {
				E = &A;
				E->Nhap();
				E->Ve();
			}
			else if (option == 2) {
				E = &B;
				E->Nhap();
				E->Ve();
			}
			else if (option == 3) {
				cleardevice();
				(*E).VeTrucToaDo();
			}
			else if (option == 4) {
				closegraph();
				break;
			}
			else {
				cout << "khong co lua chon nao khac!\nxin nhap lai lua chon!\n";
				continue;
			}
		}
	}
	~chuongtrinh() {
		E = nullptr;
		delete E;
	}
};
int main() {
	chuongtrinh start;
	return 0;
}
