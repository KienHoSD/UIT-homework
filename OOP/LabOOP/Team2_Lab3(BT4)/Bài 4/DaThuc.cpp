#include <iostream>
#include <vector>
#include <algorithm>
#include "DaThuc.h"
#include <cmath>
#include <iomanip>
using namespace std;
DaThuc::DaThuc() {
	a.BacDaThuc = 0;
	a.HeSo = 0;
}
bool SapXep(DonThuc a, DonThuc b) {
	if (a.BacDaThuc > b.BacDaThuc) return true;
	else return false;
}

void DaThuc::NhapDaThuc() {
	DonThuc temp;
	cout << "Nhap bac da thuc toi da cua da thuc: ";
	cin >> a.BacDaThuc;
	for (int i = int(a.BacDaThuc); i >=0; i--) {
		cout << "Nhap he so cua bac " << i << " : ";
		cin >> temp.HeSo;
		temp.BacDaThuc = i;
		DaySo.push_back(temp);
	}
}
void DaThuc::XuatDaThuc() {
	for (int i = 0; i < DaySo.size(); i++) {
		if (DaySo[i].HeSo == 0) continue;
		if (i != 0 && DaySo[i].HeSo > 0) {
			if (DaySo[i].HeSo == 1) cout << "+";
			else cout << "+" << DaySo[i].HeSo;
		}
		else {
			if (DaySo[i].HeSo == -1) cout << "-";
			else if (DaySo[i].HeSo != 1) cout << DaySo[i].HeSo;
		}
		if (DaySo[i].BacDaThuc == 0) {
			if (DaySo[i].HeSo == -1 || DaySo[i].HeSo == 1) cout << abs(DaySo[i].HeSo);
			continue;
		}
		if (DaySo[i].BacDaThuc != 1) cout << "x^" << DaySo[i].BacDaThuc;
		else cout << "x";
	}
}
void DaThuc::CongDaThuc(DaThuc B) {
	double temp;
	DaThuc result;
	if (this->DaySo[0].BacDaThuc > B.DaySo[0].BacDaThuc) {
		temp = int(this->DaySo[0].BacDaThuc - B.DaySo[0].BacDaThuc);
		for (int i = 0; i < temp; i++) {
			result.DaySo.push_back(this->DaySo[i]);
		}
		for (int x = int(temp), y = 0; x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
			DonThuc t;
			t.BacDaThuc = B.DaySo[y].BacDaThuc;
			t.HeSo = this->DaySo[x].HeSo + B.DaySo[y].HeSo;
			result.DaySo.push_back(t);
		}
	}
	else if (this->DaySo[0].BacDaThuc < B.DaySo[0].BacDaThuc) {
		temp = B.DaySo[0].BacDaThuc - this->DaySo[0].BacDaThuc;
		for (int i = 0; i < temp; i++) {
			result.DaySo.push_back(B.DaySo[i]);
		}
		for (int x = 0, y = int(temp); x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
			DonThuc t;
			t.BacDaThuc = this->DaySo[x].BacDaThuc;
			t.HeSo = this->DaySo[x].HeSo + B.DaySo[y].HeSo;
			result.DaySo.push_back(t);
		}
	}
	else {
		for (int i = 0, j = 0; i < this->DaySo.size() && j < B.DaySo.size(); i++, j++) {
			DonThuc t;
			t.BacDaThuc = this->DaySo[i].BacDaThuc;
			t.HeSo = this->DaySo[i].HeSo + B.DaySo[j].HeSo;
			result.DaySo.push_back(t);
		}
	}
	cout << "Tong cua hai da thuc la: ";
	result.XuatDaThuc();
	cout << endl;
}
void DaThuc::TruDaThuc(DaThuc B) {
	double temp;
	DaThuc result;
	if (this->DaySo[0].BacDaThuc > B.DaySo[0].BacDaThuc) {
		temp = int(this->DaySo[0].BacDaThuc - B.DaySo[0].BacDaThuc);
		for (int i = 0; i < temp; i++) {
			result.DaySo.push_back(this->DaySo[i]);
		}
		for (int x = int(temp), y = 0; x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
			DonThuc t;
			t.BacDaThuc = B.DaySo[y].BacDaThuc;
			t.HeSo = this->DaySo[x].HeSo - B.DaySo[y].HeSo;
			result.DaySo.push_back(t);
		}
	}
	else if (this->DaySo[0].BacDaThuc < B.DaySo[0].BacDaThuc) {
		temp = int(B.DaySo[0].BacDaThuc - this->DaySo[0].BacDaThuc);
		for (int i = 0; i < temp; i++) {
			B.DaySo[i].HeSo = (-1) * B.DaySo[i].HeSo;
			result.DaySo.push_back(B.DaySo[i]);
		}
		for (int x = 0, y = int(temp); x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
			DonThuc t;
			t.BacDaThuc = this->DaySo[x].BacDaThuc;
			t.HeSo = this->DaySo[x].HeSo - B.DaySo[y].HeSo;
			result.DaySo.push_back(t);
		}
	}
	else {
		for (int i = 0, j = 0; i < this->DaySo.size() && j < B.DaySo.size(); i++, j++) {
			DonThuc t;
			t.BacDaThuc = this->DaySo[i].BacDaThuc;
			t.HeSo = this->DaySo[i].HeSo - B.DaySo[j].HeSo;
			result.DaySo.push_back(t);
		}
	}
	cout << "Hieu cua hai da thuc la: ";
	result.XuatDaThuc();
	cout << endl;
}
void DaThuc::NhanDaThuc(DaThuc B) {
	DaThuc Nhan, result;
	DonThuc nhan;
	double tem = 0;
	bool flag = false;
	//Nhân hai đa thức với nhau và lưu vào một mảng Nhan
	for (int i = 0; i < this->DaySo.size(); i++) {
		for (int j = 0; j < B.DaySo.size(); j++) {
			DonThuc temp;
			temp.BacDaThuc = this->DaySo[i].BacDaThuc + B.DaySo[j].BacDaThuc;
			temp.HeSo = this->DaySo[i].HeSo * B.DaySo[j].HeSo;
			Nhan.DaySo.push_back(temp);
		}
	}
	//Sắp xếp lại mảng Nhan theo thứ tự giảm dần về số bậc để thuận tiện cho việc rút gọn đa thức
	sort(Nhan.DaySo.begin(), Nhan.DaySo.end(), SapXep);
	//Rút gọn lại đa thức và lưu vào mảng result.
	for (int i = 1; i < Nhan.DaySo.size(); i++) {
		if (Nhan.DaySo[i].BacDaThuc == Nhan.DaySo[i - 1].BacDaThuc) {
			tem = tem + Nhan.DaySo[i].HeSo + Nhan.DaySo[i - 1].HeSo;
			flag = true;
		}
		else if (Nhan.DaySo[i].BacDaThuc != Nhan.DaySo[i - 1].BacDaThuc) {
			nhan.BacDaThuc = Nhan.DaySo[i - 1].BacDaThuc;
			if (flag == false) nhan.HeSo = Nhan.DaySo[i - 1].HeSo;
			else if (flag == true) nhan.HeSo = tem;
			result.DaySo.push_back(nhan);
			tem = 0;
		}
	}
	flag = false;
	for (size_t j = Nhan.DaySo.size() - 2;; j--) {
		if (Nhan.DaySo[j].BacDaThuc == Nhan.DaySo[j + 1].BacDaThuc) {
			tem = tem + int(Nhan.DaySo[j].HeSo + Nhan.DaySo[j + 1].HeSo);
			flag = true;
		}
		else if (Nhan.DaySo[j].BacDaThuc != Nhan.DaySo[j + 1].BacDaThuc) {
			nhan.BacDaThuc = Nhan.DaySo[j + 1].BacDaThuc;
			if (flag == false) nhan.HeSo = Nhan.DaySo[j + 1].HeSo;
			else if (flag == true) nhan.HeSo = tem;
			result.DaySo.push_back(nhan);
			break;
		}
	}
	cout << "Tich 2 da thuc la: ";
	result.XuatDaThuc();
	cout << endl;
}
void DaThuc::ChiaDaThuc(DaThuc B) {
	DaThuc SoBiChia, SoChia, Hieu, Thuong;
	DaThuc tempo;
	DonThuc a, b;
	int dem = 0;
	SoBiChia.DaySo = this->DaySo;
	SoChia.DaySo = B.DaySo;
	for (int i = 0; i < SoBiChia.DaySo.size(); i++) {
		if (SoBiChia.DaySo[i].HeSo != 0) {
			a.BacDaThuc = SoBiChia.DaySo[i].BacDaThuc;
			a.HeSo = SoBiChia.DaySo[i].HeSo;
			break;
		}
	}
	for (int j = 0; j < SoChia.DaySo.size(); j++) {
		if (SoChia.DaySo[j].HeSo != 0) {
			b.BacDaThuc = SoChia.DaySo[j].BacDaThuc;
			b.HeSo = SoChia.DaySo[j].HeSo;
			if (j != 0) SoChia.DaySo.erase(SoChia.DaySo.begin(), SoChia.DaySo.begin() + j - 1);
			break;
		}
	}
	if (a.BacDaThuc < b.BacDaThuc || a.BacDaThuc == 0 || b.BacDaThuc==0 ) {
		cout << "Thuong cua 2 da thuc la: ";
		SoBiChia.XuatDaThuc();
		cout << "/";
		SoChia.XuatDaThuc();
	}
	else {
		while (true) {
			//Tìm thương của phép chia
			DonThuc temp;
			if (SoBiChia.DaySo.size()<= 0) break;
			if (SoBiChia.DaySo[0].BacDaThuc < SoChia.DaySo[0].BacDaThuc) break;
			temp.BacDaThuc = SoBiChia.DaySo[0].BacDaThuc - SoChia.DaySo[0].BacDaThuc;
			temp.HeSo = SoBiChia.DaySo[0].HeSo / SoChia.DaySo[0].HeSo;
			Thuong.DaySo.push_back(temp);
			//Nhân ngược thương cho số chia để trừ cho số bị chia
			for (int x = 0; x < SoChia.DaySo.size(); x++) {
				DonThuc nhan;
				nhan.HeSo = Thuong.DaySo[Thuong.DaySo.size() - 1].HeSo * SoChia.DaySo[x].HeSo;
				nhan.BacDaThuc = Thuong.DaySo[Thuong.DaySo.size() - 1].BacDaThuc + SoChia.DaySo[x].BacDaThuc;
				Hieu.DaySo.push_back(nhan);
			}
			//Hạ các số không bị ảnh hưởng bởi phép trừ ở dưới
			for (int i = 0; i < SoBiChia.DaySo.size(); i++) {
				for (int j = 0; j < Hieu.DaySo.size(); j++) {
					if (SoBiChia.DaySo[i].BacDaThuc != Hieu.DaySo[j].BacDaThuc) dem++;
				}
				if (dem == Hieu.DaySo.size()) tempo.DaySo.push_back(SoBiChia.DaySo[i]);
				dem = 0;
			}
			//Lấy số bị chia trừ cho tích của thương với số chia
			for (int y = 0; y < Hieu.DaySo.size(); y++) {
				for (int i = y; i < SoBiChia.DaySo.size(); i++) {
					if (Hieu.DaySo[y].BacDaThuc == SoBiChia.DaySo[i].BacDaThuc) {
						DonThuc tru;
						tru.BacDaThuc = Hieu.DaySo[y].BacDaThuc;
						tru.HeSo = SoBiChia.DaySo[i].HeSo - Hieu.DaySo[y].HeSo;
						if (tru.HeSo == 0) break;
						tempo.DaySo.push_back(tru);
						break;
					}
				}
			}
			//Tạo mảng lưu kết quả của phép trừ và gán lại cho số bị chia
			sort(tempo.DaySo.begin(), tempo.DaySo.end(), SapXep);
			Hieu.DaySo.clear();
			SoBiChia.DaySo.clear();
			SoBiChia.DaySo = tempo.DaySo;
			tempo.DaySo.clear();
		}
		cout << "Thuong cua 2 da thuc la: " << setprecision(3);
		if (SoBiChia.DaySo.size()<=0||SoBiChia.DaySo[0].HeSo==0) {
			Thuong.XuatDaThuc();
		}
		else {
			Thuong.XuatDaThuc();
			cout << endl;
			cout << "Phan du la: ";
			SoBiChia.XuatDaThuc();
			cout << "/";
			SoChia.XuatDaThuc();
			//cout << endl;
		}
		cout << endl;
	}

}
void DaThuc::GiaTriDonThuc(double x) {
	double result = 0;
	if (this->DaySo.size() == 0) result = 0;
	else {
		for (int i = 0; i < this->DaySo.size(); i++) {
			result = result + (this->DaySo[i].HeSo * pow(x,this->DaySo[i].BacDaThuc));
		}
	}
	cout << result << endl;
}
