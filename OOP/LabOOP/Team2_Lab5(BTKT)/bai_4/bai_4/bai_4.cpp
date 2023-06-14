#include <iostream>
#include <cmath>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;


class hinhhoc {
protected:
	// thuộc tính x và y double để lưu trữ tâm các đường tròn và ellipse
	double x, y;
public:
	// hàm khởi tạo lớp hinhhoc, cho x=0 và y=0 
	hinhhoc() {
		x = 0; y = 0;
	}
	// phương thức ảo Ve()
	virtual void Ve() = 0;
	// phương thức ảo Nhap()
	virtual void Nhap() = 0;
	// phương thức vẽ trục toạ độ và các điểm đơn vị (mỗi điểm cách nhau 25 pixels)
	void VeTrucToaDo() {
		int TamX = int(getmaxx() / 2) + 1; // toa do x cua tam O
		int TamY = int(getmaxy() / 2) + 1; // toa do y cua tam O
		line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy()); // Ve truc Oy
		line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2); // Ve truc Ox
		// Vẽ các điểm đơn đơn vị từ tâm O
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
	// phương thức vẽ điểm, vẽ những điểm có màu vàng (tâm của đường tròn và ellipse)
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
// lớp classEllipse kế thừa public từ lớp hinhhoc
class classEllipse :public hinhhoc {
private:
	// thêm vào 2 thuộc tính x_rad và y_rad (double) để lưu độ dài bán trục lớn và bé của ellipse
	double x_rad, y_rad;
public:
	// hàm khởi tạo gán mặc định x_rad và y_rad = 0
	classEllipse() {
		x_rad = 0; y_rad = 0;
	}
	// nhập toạ độ x,y,x_rad,y_rad và xét x_rad và y_rad (không thể bằng 0 hoặc âm) và vẽ điểm có toạ độ x,y
	void Nhap() {
		cout << "Nhap lan luot toa do x, y, ban truc lon, ban truc be: ";
		double xx, yy, xx_rad, yy_rad;
		cin >> xx >> yy >> xx_rad >> yy_rad;
		x = xx; y = yy;
		x_rad = xx_rad; y_rad = yy_rad;
		while (x_rad <= 0) {
			cout << "ban truc lon khong the la so am hoac bang 0!\nvui long nhap lai ban truc lon: ";
			cin >> x_rad;
		}
		while (y_rad <= 0) {
			cout << "ban truc be khong the la so am hoac bang 0!\nvui long nhap lai ban truc be: ";
			cin >> y_rad;
		}
		VeDiem();
	}
	// phương thức Ve có chức năng vẽ đường ellipse quanh tâm có toạ độ x,y
	void Ve() {
		int tamOx = int(getmaxx() / 2);
		int tamOy = int(getmaxy() / 2);
		ellipse(int(x * 25) + tamOx, int(-y * 25) + tamOy, 0, 360, int(x_rad * 25), int(y_rad * 25));
	}
};
// lớp classCircle kế thừa public từ lớp hinhhoc
class classCircle :public hinhhoc {
private:
	// thêm vào 1 thuộc tính radius là bán kính đường tròn
	double radius;
public:
	// hàm khởi tạo sẽ cho radius = 0
	classCircle() {
		radius = 0;
	}
	// hàm Nhap có chức năng nhập x,y và radius với radius không được âm hoặc bằng 0, và vẽ điểm với toạ độ x,y
	void Nhap() {
		cout << "Nhap lan luot toa do x, y, ban kinh hinh tron: ";
		double xx, yy, r;
		cin >> xx >> yy >> r;
		while (r <= 0) {
			cout << "ban kinh khong the la so am!\nvui long nhap lai ban kinh: ";
			cin >> r;
		}
		x = xx; y = yy; radius = r;
		VeDiem();
	}
	// hàm Ve vẽ một đường tròn có bán kính bằng radius và có tâm tại toạ độ x,y
	void Ve() {
		int tamOx = int(getmaxx() / 2);
		int tamOy = int(getmaxy() / 2);
		circle(int(x * 25) + tamOx, int(-y * 25) + tamOy, radius * 25);
	}
};
// lớp chuongtrinh là lớp quản lý chương trình
class chuongtrinh {
private:
	// khởi tạo con trỏ hinhhoc E, object classCircle A và object classEllipse B
	hinhhoc* E = nullptr;
	classCircle A;
	classEllipse B;
public:
	// cho hàm khởi tạo là hàm chính để chạy chương trình
	chuongtrinh() {
		initwindow(1200, 800, "Draw", 50, 50);
		int option;
		while (true) {
			E->VeTrucToaDo();
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
				E->VeTrucToaDo();
			}
			else if (option == 4) {
				closegraph();
				break;
			}
			else {
				cout << "khong co lua chon nao khac!\nxin nhap lai lua chon!\n";
				continue;
			}
			system("CLS");
		}
	}
	// xoá con trỏ E khi đã chạy xong chương trình
	~chuongtrinh() {
		E = nullptr;
		delete E;
	}
};
int main() {
	// khởi tạo object start lớp chuongtrinh và trả về 0 khi đã hoàn thành
	chuongtrinh start;
	return 0;
}
