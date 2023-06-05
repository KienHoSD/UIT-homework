#include <iostream>
#include <numeric>
using namespace std;
struct PhanSo {
    int tu, mau;
};
void RutGon(PhanSo &a) {
    int temp = gcd(a.tu, a.mau);
    a.tu = a.tu / temp;
    a.mau = a.mau / temp;
}
void NhapPhanSo(PhanSo &a) {
    cout << "Nhap phan so thu nhat: ";
    cin >> a.tu >> a.mau;
    while (a.mau == 0) {
        cout << "Nhap lai: ";
        cin >> a.tu >> a.mau;
    }
    if (a.mau < 0 && a.tu < 0) {
        a.tu = abs(a.tu);
        a.mau = abs(a.mau);
    }
    else if (a.mau < 0 && a.tu > 0) {
        a.tu = (-1) * a.tu;
        a.mau = abs(a.mau);
    }
}
PhanSo Nhap() {
    PhanSo b;
    cout << "Nhap phan so thu hai: ";
    cin >> b.tu >> b.mau;
    while (b.mau == 0) {
        cout << "Nhap lai: ";
        cin >> b.tu >> b.mau;
    }
    if (b.mau < 0 && b.tu < 0) {
        b.tu = abs(b.tu);
        b.mau = abs(b.mau);
    }
    if (b.mau < 0) {
        b.tu = (-1) * b.tu;
        b.mau = abs(b.mau);
    }
    return b;
}
PhanSo PhanSoMax(PhanSo a, PhanSo b) {
    RutGon(a);
    RutGon(b);
    if (a.tu*b.mau > b.tu*a.mau) return a;
    else return b;
}
void Xuat(PhanSo c) {
    if (c.tu % c.mau == 0) cout << "Phan so lon nhat la: " << c.tu;
    cout << "Phan so lon nhat la: " << c.tu << "/" << c.mau;
}
int main()
{
    PhanSo a, b, c;
    NhapPhanSo(a);
    b = Nhap();
    c = PhanSoMax(a, b);
    Xuat(c);
    return 0;
}