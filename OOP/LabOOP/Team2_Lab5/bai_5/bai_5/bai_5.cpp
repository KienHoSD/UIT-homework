#include <iostream>
#include <cmath>
#include "graphics.h"
#include <vector>
#include <algorithm>
#pragma comment(lib,"graphics.lib")
using namespace std;

struct point {
	double x, y;
	point() {
		x = 0; y = 0;
	}
};
bool compareAngles(const pair<float, point>& a, const pair<float, point>& b) {
	return a.first < b.first;
}
class hinhhoc {
protected:
	bool valid = 0;
	point a[4];
public:
	virtual void validcheck() = 0;
	bool Nhap() {
		int option;
		do {
			cout << "Nhap lan luot toa do x, y cua 4 diem: \n";
			for (int i = 0; i < 4; i++) {
				cout << "Nhap toa do cua diem " << i + 1 << ": ";
				cin >> a[i].x >> a[i].y;
				VeDiem(a[i]);
			}
			vector<point> temp;
			for (int i = 0; i < 4; i++) temp.push_back(a[i]);
			sortPointsByAngle(temp);
			for (int i = 0; i < 4; i++) {
				a[i].x = temp[i].x;
				a[i].y = temp[i].y;
			}
			validcheck();
			if (valid) {
				cout << "Ban da nhap sai du lieu!\nBan co muon nhap lai khong?\n1. Ok!\nKhac. Khong!";
				cin >> option;
				cleardevice();
				VeTrucToaDo();
				if (option == 1) continue;
				else return 0;
			}
		} while (valid);
		return 1;
	}
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
	void VeDiem(point a) {
		int TamX = int(getmaxx() / 2) + 1;
		int TamY = int(getmaxy() / 2) + 1;
		//Thiet lap vi tri diem 
		int xx = int(a.x * 25 + TamX);
		int yy = int(-a.y * 25 + TamY);
		setfillstyle(SOLID_FILL, YELLOW);
		circle(xx, yy, 5);
		floodfill(xx, yy, WHITE);
	}

	void sortPointsByAngle(vector<point>& points) {
		point average;
		for (const auto& p : points) {
			average.x += p.x;
			average.y += p.y;
		}
		average.x /= points.size();
		average.y /= points.size();

		// tinh toan cac goc va luu vao thanh tung cap trong vector
		std::vector<std::pair<float, point>> angles;
		for (const auto& p : points) {
			double dx = p.x - average.x;
			double dy = p.y - average.y;
			double angle = atan2f(float(dy), float(dx));
			angles.emplace_back(angle, p);
		}

		// sort cac diem boi goc cua chung
		sort(angles.begin(), angles.end(), compareAngles);

		// luu lai cac diem da sort vao vector ban dau
		for (size_t i = 0; i < points.size(); i++) {
			points[i] = angles[i].second;
		}
	}
	void Ve() {
		int tamOx = int(getmaxx() / 2);
		int tamOy = int(getmaxy() / 2);
		vector <int> Ve;
		for (int j = 0; j < 4; j++) {
			int tempx = int(a[j].x * 25 + tamOx);
			int tempy = int(-a[j].y * 25 + tamOy);
			Ve.push_back(tempx);
			Ve.push_back(tempy);
		}
		Ve.push_back(int(a[0].x * 25 + tamOx));
		Ve.push_back(int(-a[0].y * 25 + tamOy));
		int* arr = Ve.data();
		drawpoly(5, arr);
	}

};

class hinhthang :public hinhhoc {
public:
	void validcheck() {
		valid = a[0].y != a[1].y || a[2].y != a[3].y; // kiem tra 2 day
	}
};
class hinhbinhhanh :public hinhhoc {
public:
	void validcheck() {
		valid = a[0].y != a[1].y || a[2].y != a[3].y || a[0].x - a[1].x != a[3].x - a[2].x; // kiem tra 2 day va chieu dai 2 day
	}
};
class hinhchunhat :public hinhhoc {
public:
	void validcheck() {
		valid = a[0].y != a[1].y || a[1].x != a[2].x || a[2].y != a[3].y; // kiem tra 2 day va 1 canh
	}
};
class hinhvuong :public hinhhoc {
public:
	void validcheck() {
		valid = a[0].y != a[1].y || a[1].x!=a[2].x || a[2].y != a[3].y || a[1].x-a[0].x!=a[2].y-a[1].y; // kiem tra 2 day va 1 canh va do dai 2 canh ke nhau
	}
};

class chuongtrinh {
	hinhhoc* a = nullptr;
	hinhthang b;
	hinhbinhhanh c;
	hinhchunhat d;
	hinhvuong e;
public:
	chuongtrinh() {
		initwindow(1200, 800, "Ve tu giac", 50, 50);
		(*a).VeTrucToaDo();
		int option;
		while (true) {
			system("CLS");
			cout << "Nhap hinh muon ve!\n";
			cout << "1. Hinh thang\n2. Hinh binh hanh\n3. Hinh chu nhat\n4. Hinh vuong\n";
			cout << "5. Don dep man hinh\n6. Dung chuong trinh\nLuu y!: khi nhap du lieu sai tat ca cac hinh se mat!\n";
			cin >> option;
			if (option == 1) a = &b;
			else if (option == 2) a = &c;
			else if (option == 3) a = &d;
			else if (option == 4) a = &e;
			else if (option == 5) {
				cleardevice();
				(*a).VeTrucToaDo();
			}
			else if (option == 6) {
				closegraph();
				break;
			}
			else {
				cout << "khong co lua chon nao khac!\nxin nhap lai lua chon!\n";
				continue;
			}
			if (a->Nhap()) a->Ve();
		}
	}
	~chuongtrinh() {
		a = nullptr;
		delete a;
	}
};
int main() {
	chuongtrinh start;
	return 0;
}
