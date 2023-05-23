#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct DonThuc {
	int BacDaThuc;
	double HeSo;
};
class DaThuc {
private:
	DonThuc a;
	vector <DonThuc> DaySo;

public:
	DaThuc();
	void NhapDaThuc();
	void XuatDaThuc();
	void CongDaThuc(DaThuc B);
	void TruDaThuc(DaThuc B);
	DaThuc TruDaThucTravaDaThuc(DaThuc B);
	void NhanDaThuc(DaThuc B);
	DaThuc NhanDaThucTraveDaThuc(DaThuc B);
	void ChiaDaThuc(DaThuc B);
	void GiaTriDonThuc(double x);
	DaThuc RutGonDaThuc();
};


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
DaThuc DaThuc::RutGonDaThuc() {
	DaThuc result;
	sort(DaySo.begin(), DaySo.end(), SapXep);
	for (int i = 0; i < DaySo.size(); i++) {
		if (!Check0(DaySo[i])) {
			result.DaySo.push_back(DaySo[i]);
		}
	}
	return result;
}
void DaThuc::NhapDaThuc() {
	DonThuc temp;
	cout << "Nhap bac da thuc toi da cua da thuc: ";
	cin >> a.BacDaThuc;
	for (int i = a.BacDaThuc; i >= 0; i--) {
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
			}
			else { // negative coefficient
				cout << "- ";
			}
		}
		else if (DaySo[i].HeSo < 0) { // first term and negative coefficient
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
	DaThuc result;
	result.a.BacDaThuc = max(this->a.BacDaThuc, B.a.BacDaThuc);
	for (int i = result.a.BacDaThuc; i >= 0; i--) {
		DonThuc temp;
		temp.BacDaThuc = i;
		int coef_this = 0, coef_B = 0;
		for (int j = 0; j < this->DaySo.size(); j++) {
			if (this->DaySo[j].BacDaThuc == i) {
				coef_this = this->DaySo[j].HeSo;
				break;
			}
		}
		for (int j = 0; j < B.DaySo.size(); j++) {
			if (B.DaySo[j].BacDaThuc == i) {
				coef_B = B.DaySo[j].HeSo;
				break;
			}
		}
		temp.HeSo = coef_this - coef_B;
		if (temp.HeSo != 0) {
			result.DaySo.push_back(temp);
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
	DaThuc result;
	for (int i = 0; i <= this->DaySo[0].BacDaThuc; i++) {
		for (int j = 0; j <= B.DaySo[0].BacDaThuc; j++) {
			DonThuc temp;
			temp.BacDaThuc = this->DaySo[i].BacDaThuc + B.DaySo[j].BacDaThuc;
			temp.HeSo = this->DaySo[i].HeSo * B.DaySo[j].HeSo;
			result.DaySo.push_back(temp);
		}
	}
	return result.RutGonDaThuc();
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
	DaThuc R, tempB, result; //R la ket qua, result la so du
	tempB = B.RutGonDaThuc();
	result = (*this).RutGonDaThuc();
	if (tempB.DaySo[0].BacDaThuc > result.DaySo[0].BacDaThuc) {
		cout << "Thuong cua hai da thuc la: ";
		cout << "(("; (*this).XuatDaThuc(); cout << ")/("; B.XuatDaThuc(); cout << "))" << endl;
	}
	else {
		do {
			DaThuc TempDaThuc;
			DonThuc temp = TinhThuong(result.DaySo[0], tempB.DaySo[0]);
			R.DaySo.push_back(temp);
			TempDaThuc.DaySo.push_back(temp);
			TempDaThuc = TempDaThuc.NhanDaThucTraveDaThuc(tempB); // R * B
			result = result.TruDaThucTravaDaThuc(TempDaThuc); //result = result - R*B
		} while (result.DaySo[0].BacDaThuc >= tempB.DaySo[0].BacDaThuc);
		cout << "Thuong cua hai da thuc la: " << setprecision(3);
		R.XuatDaThuc(); cout << "+(("; result.XuatDaThuc(); cout << ")/("; tempB.XuatDaThuc(); cout << "))" << endl;
	}
}

void DaThuc::GiaTriDonThuc(double x) {
	double result = 0;
	if (this->DaySo.size() == 0) result = 0;
	else {
		for (int i = 0; i < this->DaySo.size(); i++) {
			result = result + (1.0 * this->DaySo[i].HeSo * pow(x, 1.0 * this->DaySo[i].BacDaThuc));
		}
	}
	cout << result << endl;
}


int main()
{
	double x, y;
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

