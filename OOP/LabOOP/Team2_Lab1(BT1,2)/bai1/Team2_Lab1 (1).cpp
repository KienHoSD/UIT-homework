#include <iostream>
#include <numeric>
using namespace std;
struct PhanSo {
    int tu, mau;
};
void RutGonPhanSo(PhanSo &a) {
    if (a.mau < 0 && a.tu < 0) {
        a.tu = abs(a.tu);
        a.mau = abs(a.mau);
    }
    else if (a.mau < 0 && a.tu >= 0) {
        a.mau = abs(a.mau);
        a.tu = (-1) * a.tu;
    }
    
    int sochia = gcd(abs(a.tu), abs(a.mau));
    a.tu = a.tu / sochia;
    a.mau = a.mau / sochia;
    if (a.tu % a.mau == 0) cout << "Phan so da rut gon:" << a.tu;
    else cout << "Phan so da rut gon: " << a.tu << "/" << a.mau;
}
int main()
{
    PhanSo a;
    cout << "Nhap phan so: ";
    cin >> a.tu  >> a.mau;
    while (a.mau == 0) {
        cout << "Vui long nhap lai: ";
        cin >> a.tu >> a.mau;
    }
    RutGonPhanSo(a);
    return 0;
}