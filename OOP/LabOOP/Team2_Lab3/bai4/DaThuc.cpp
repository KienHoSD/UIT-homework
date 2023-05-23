#include <iostream>
#include <vector>
#include <algorithm>
#include "DaThuc.h"
#include <cmath>
using namespace std;
DaThuc::DaThuc() {
	a.BacDaThuc = 0;
	a.HeSo = 0;
}
bool Check0(const DonThuc& a) {
	if (a.HeSo == 0) return true;
	else return false;
}
bool SapXep(DonThuc a, DonThuc b) {
	if (a.BacDaThuc > b.BacDaThuc) return true;
	else return false;
}
DonThuc TinhThuong(const DonThuc& a, const DonThuc& b) {
	DonThuc result;
	result.HeSo = a.HeSo / b.HeSo;
	result.BacDaThuc = a.BacDaThuc - b.BacDaThuc;
	return result;
}
void DaThuc::NhapDaThuc() {
	DonThuc temp;
	cout << "Nhap bac da thuc toi da cua da thuc: ";
	cin >> a.BacDaThuc;
	for (int i = a.BacDaThuc; i >=0; i--) {
		cout << "Nhap he so cua bac " << i << " : ";
		cin >> temp.HeSo;
		temp.BacDaThuc = i;
		DaySo.push_back(temp);
	}
}
void DaThuc::XuatDaThuc() {
    int cnt = 0; // counter to keep track of the number of printed terms
    for (int i = 0; i < DaySo.size(); i++) {
        if (DaySo[i].HeSo == 0) continue; // skip terms with zero coefficient
        if (cnt > 0) { // not the first term
            if (DaySo[i].HeSo > 0) { // positive coefficient
                cout << "+ ";
            } else { // negative coefficient
                cout << "- ";
            }
        } else if (DaySo[i].HeSo < 0) { // first term and negative coefficient
            cout << "-"; 
        }
        if (abs(DaySo[i].HeSo) != 1 || DaySo[i].BacDaThuc == 0) { // print the coefficient if it's not +1 or -1, or if it's a constant term
            cout << abs(DaySo[i].HeSo);
        }
        if (DaySo[i].BacDaThuc > 0) { // print the variable and its exponent, if the term is not a constant
            cout << "x";
            if (DaySo[i].BacDaThuc > 1) {
                cout << "^" << DaySo[i].BacDaThuc;
            }
        }
        cnt++;
    }
    if (cnt == 0) cout << 0; // print 0 if all terms have zero coefficients
    cout << endl;
}
void DaThuc::CongDaThuc(DaThuc B) {
	int temp;
	DaThuc result;
	if (this->DaySo[0].BacDaThuc > B.DaySo[0].BacDaThuc) {
		temp = this->DaySo[0].BacDaThuc - B.DaySo[0].BacDaThuc;
		for (int i = 0; i < temp; i++) {
			result.DaySo.push_back(this->DaySo[i]);
		}
		for (int x = temp, y = 0; x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
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
		for (int x = 0, y = temp; x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
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
DaThuc DaThuc::TruDaThucTravaDaThuc(DaThuc B) {
	int temp;
	DaThuc result;
	if (this->DaySo[0].BacDaThuc > B.DaySo[0].BacDaThuc) {
		temp = this->DaySo[0].BacDaThuc - B.DaySo[0].BacDaThuc;
		for (int i = 0; i < temp; i++) {
			result.DaySo.push_back(this->DaySo[i]);
		}
		for (int x = temp, y = 0; x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
			DonThuc t;
			t.BacDaThuc = B.DaySo[y].BacDaThuc;
			t.HeSo = this->DaySo[x].HeSo - B.DaySo[y].HeSo;
			result.DaySo.push_back(t);
		}
	}
	else if (this->DaySo[0].BacDaThuc < B.DaySo[0].BacDaThuc) {
		temp = B.DaySo[0].BacDaThuc - this->DaySo[0].BacDaThuc;
		for (int i = 0; i < temp; i++) {
			B.DaySo[i].HeSo = (-1) * B.DaySo[i].HeSo;
			result.DaySo.push_back(B.DaySo[i]);
		}
		for (int x = 0, y = temp; x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
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
	return result;
}
void DaThuc::TruDaThuc(DaThuc B) {
	int temp;
	DaThuc result;
	if (this->DaySo[0].BacDaThuc > B.DaySo[0].BacDaThuc) {
		temp = this->DaySo[0].BacDaThuc - B.DaySo[0].BacDaThuc;
		for (int i = 0; i < temp; i++) {
			result.DaySo.push_back(this->DaySo[i]);
		}
		for (int x = temp, y = 0; x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
			DonThuc t;
			t.BacDaThuc = B.DaySo[y].BacDaThuc;
			t.HeSo = this->DaySo[x].HeSo - B.DaySo[y].HeSo;
			result.DaySo.push_back(t);
		}
	}
	else if (this->DaySo[0].BacDaThuc < B.DaySo[0].BacDaThuc) {
		temp = B.DaySo[0].BacDaThuc - this->DaySo[0].BacDaThuc;
		for (int i = 0; i < temp; i++) {
			B.DaySo[i].HeSo = (-1) * B.DaySo[i].HeSo;
			result.DaySo.push_back(B.DaySo[i]);
		}
		for (int x = 0, y = temp; x < this->DaySo.size() && y < B.DaySo.size(); x++, y++) {
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
DaThuc DaThuc::NhanDaThucTraveDaThuc(DaThuc B) {
	DaThuc Nhan, result;
	DonThuc nhan;
	int tem = 0;
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
			tem = tem + Nhan.DaySo[j].HeSo + Nhan.DaySo[j + 1].HeSo;
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
	return result;
}
void DaThuc::NhanDaThuc(DaThuc B) {
	DaThuc Nhan, result;
	DonThuc nhan;
	int tem = 0;
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
			tem = tem + Nhan.DaySo[j].HeSo + Nhan.DaySo[j + 1].HeSo;
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
    DaThuc R,result;
	result=*this;
	int i =2;
	while(i!=0){
		DonThuc temp = TinhThuong(result.DaySo[0],B.DaySo[0]);
		R.DaySo.push_back(temp); // R la ket qua, pushback
		R = R.NhanDaThucTraveDaThuc(B); // R * B
		result = result.TruDaThucTravaDaThuc(R); //result - R*B
		i--;
		R.XuatDaThuc();
	}
	
}



void DaThuc::GiaTriDonThuc(double x) {
	float result = 0;
	if (this->DaySo.size() == 0) result = 0;
	else {
		for (int i = 0; i < this->DaySo.size(); i++) {
			result = result + (1.0*this->DaySo[i].HeSo * pow(x,1.0*this->DaySo[i].BacDaThuc));
		}
	}
	cout << result << endl;
}
