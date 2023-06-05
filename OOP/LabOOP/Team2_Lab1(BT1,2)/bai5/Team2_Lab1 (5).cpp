#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct HocSinh {
    string HoTen;
    float diemToan;
    float diemVan;
    float DTB;
};
void Nhap(HocSinh &a) {
    cout << "Nhap ho ten: ";
    getline(cin, a.HoTen);
    cout << "Nhap diem Toan: ";
    cin >> a.diemToan;
    while (a.diemToan < 0 || a.diemToan >10) {
        cout << "Nhap lai diem Toan: ";
        cin >> a.diemToan;
    }
    cout << "Nhap diem Van: ";
    cin >> a.diemVan;
    while (a.diemVan < 0 || a.diemVan >10) {
        cout << "Nhap lai diem Van: ";
        cin >> a.diemVan;
    }
}
void Xuat(HocSinh a) {
    a.DTB = (a.diemToan + a.diemVan) / 2;
    cout << "Diem trung binh = ";
    printf("%.1f", a.DTB);
}
int main()
{
    HocSinh A;
    Nhap(A);
    Xuat(A);
}