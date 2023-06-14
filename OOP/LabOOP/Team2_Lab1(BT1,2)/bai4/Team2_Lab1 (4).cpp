#include <iostream>
using namespace std;
bool isNamNhuan(int nam) {
    if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) return true;
    else return false;
}
int NgayCuaThang(int thang, int nam) {
    if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12) return 31;
    else if (thang == 2 && isNamNhuan(nam) == true) return 29;
    else if (thang == 2 && isNamNhuan(nam) == false) return 28;
    else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return 30;
}
void TheNextDay(int ngay, int thang, int nam) {
    int ngay1 = ngay;
    int thang1 = thang;
    int nam1 = nam;
    if (nam > 0 && thang > 0 && thang < 13 && thang > 0 && ngay <=(NgayCuaThang(thang, nam))) {
        ngay1++;
        if (thang != 12 && ngay == NgayCuaThang(thang, nam)) {
            ngay1 = 1;
            thang1++;
        }
        else if (thang == 12 && ngay == NgayCuaThang(thang, nam)) {
            ngay1 = 1;
            nam1++;
            thang1 = 1;
        }
        else if (thang == 2) {
        if (isNamNhuan(nam) == true) {
            if (ngay == 29) {
                ngay1 = 1;
                thang1++;
            }
        }
        else {
            if (ngay == 28) {
                ngay1 = 1;
                thang1++;
            }
        }
        }
    }
    cout << "Ngay tiep theo la: " << ngay1 << "/" << thang1 << "/" << nam1 << endl;
}
bool KiemTraNgay(int ngay, int thang, int nam) {
    if (nam < 0) return false;
    if (thang < 1 || thang > 12) return false;
    if (ngay < 1 || ngay > 31) return false;
    if (thang == 2) {
        if (isNamNhuan(nam) == true) return (ngay <= 29);
        else return (ngay <= 28);
    }
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return (ngay <= 30);
    return true;
}
int main()
{
    int ngay, thang, nam;
    cout << "Nhap ngay, thang, nam: ";
    cin >> ngay >> thang >> nam;
    while (KiemTraNgay(ngay,thang,nam)==false) {
        cout << "Vui long nhap lai ngay, thang, nam: ";
        cin >> ngay >> thang >> nam;
    }
    TheNextDay(ngay, thang, nam);
    return 0;
}