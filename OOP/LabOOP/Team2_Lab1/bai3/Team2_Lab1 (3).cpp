#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
struct PhanSo {
    int tu, mau;
};
void DoiDau(PhanSo &a) {
    if (a.mau < 0 && a.tu < 0) {
        a.tu = abs(a.tu);
        a.mau = abs(a.mau);
    }
    else if (a.mau < 0 && a.tu > 0) {
        a.tu = (-1) * a.tu;
        a.mau = abs(a.mau);
    }
}
void RutGon(PhanSo &a) {
    int temp = __gcd(a.tu, a.mau);
    a.tu = a.tu / temp;
    a.mau = a.mau / temp;
}
void NhapPhanSo(PhanSo& a) {
    cout << "Nhap phan so thu nhat: ";
    cin >> a.tu >> a.mau;
    while (a.mau == 0) {
        cout << "Nhap lai: ";
        cin >> a.tu >> a.mau;
    }
    DoiDau(a);
}
PhanSo Nhap() {
    PhanSo b;
    cout << "Nhap phan so thu hai: ";
    cin >> b.tu >> b.mau;
    while (b.mau == 0) {
        cout << "Nhap lai: ";
        cin >> b.tu >> b.mau;
    }
    DoiDau(b);
    return b;
}
void Tong(PhanSo a, PhanSo b) {
    a.tu = a.tu * b.mau + b.tu * a.mau;
    a.mau = a.mau * b.mau;
    RutGon(a);
    if (a.tu % a.mau == 0) cout << "Tong hai phan so: " << a.tu << endl;
    else cout << "Tong hai phan so: " << a.tu << "/" << a.mau << endl;
}
void Hieu(PhanSo a, PhanSo b) {
    a.tu = a.tu * b.mau - b.tu * a.mau;
    a.mau = a.mau * b.mau;
    RutGon(a);
    if (a.tu % a.mau == 0) cout << "Hieu hai phan so: " << a.tu<<endl;
    else cout << "Hieu hai phan so: " << a.tu << "/" << a.mau << endl;
}
void Tich(PhanSo a, PhanSo b) {
    a.tu = a.tu * b.tu;
    a.mau = a.mau * b.mau;
    RutGon(a);
    if (a.tu % a.mau == 0) cout << "Tich hai phan so: " << a.tu << endl;
    else cout << "Tich hai phan so: " << a.tu << "/" << a.mau << endl;
}
void Thuong(PhanSo a, PhanSo b) {
    a.tu = a.tu * b.mau;
    a.mau = a.mau * b.tu;
    RutGon(a);
    if (a.tu % a.mau == 0) cout << "Thuong hai phan so: " << a.tu << endl;
    else cout << "Thuong hai phan so: " << a.tu << "/" << a.mau << endl;
}
int main()
{
    PhanSo a, b;
    NhapPhanSo(a);
    b = Nhap();
    Tong(a, b);
    Hieu(a, b);
    Tich(a, b);
    Thuong(a, b);
    return 0;
}
