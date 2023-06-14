#pragma once
class CDate {
    int ngay, thang, nam;
public:
    CDate(int d, int m, int y);
    void Nhap();
    void Xuat();
    int so_ngay_cach_nhau(CDate other);
    void them_1_ngay();
    void tru_1_ngay();
    void Cong(int days);
    void Tru(int days);
};