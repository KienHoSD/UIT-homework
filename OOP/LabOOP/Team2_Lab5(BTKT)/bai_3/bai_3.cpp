#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Nguoi {
protected:
    string HoTen;
    int Tuoi;
    char GioiTinh;
public:
    void NhapThongTin() {
        cin.ignore();
        cout << "Vui long nhap ho ten: ";
        getline(cin, HoTen);
        cout << "Vui long nhap do tuoi: ";
        cin >> Tuoi;
        do {
            cout << "Vui long lua chon gioi tinh: " << endl;
            cout << "Nhap F neu la nu. Nhap M neu la nam." << endl;
            cout << "Nhap lua chon: ";
            cin >> GioiTinh;
            if (GioiTinh != 'F' && GioiTinh != 'M') cout << "Khong hop le. Vui long nhap lai." << endl;
        } while (GioiTinh != 'F' && GioiTinh != 'M');
    }
    void XuatThongTin() {
        cout << "Ho ten: " << HoTen << endl;
        cout << "Do tuoi: " << Tuoi << endl;
        if (GioiTinh == 'F') cout << "Gioi tinh: Nu." << endl;
        else cout << "Gioi tinh: Nam" << endl;
    }
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
};
class SinhVien :public Nguoi {
private:
    string MSSV;
    string TenDaiHoc;
    string ChuyenNganh;
public:
    void Nhap() {
        cout << "Doi tuong: Sinh vien. " << endl;
        Nguoi::NhapThongTin();
        cout << "Nhap ma so sinh vien: ";
        cin >> MSSV;
        cin.ignore();
        cout << "Nhap ten truong dai hoc: ";
        getline(cin, TenDaiHoc);
        cout << "Nhap nganh hoc: ";
        getline(cin, ChuyenNganh);
    }
    void Xuat() {
        cout << "Doi tuong: Sinh vien. " << endl;
        Nguoi::XuatThongTin();
        cout << "Ma so sinh vien: " << MSSV << endl;
        cout << "Hoc tai truong dai hoc: " << TenDaiHoc << endl;
        cout << "Chuyen nganh: " << ChuyenNganh << endl;
    }
};
class HocSinh :public Nguoi {
private:
    int Lop;
    string TenTruong;
    void Nhap() {
        cout << "Doi tuong: Hoc sinh. " << endl;
        Nguoi::NhapThongTin();
        do {
            cout << "Hoc lop: ";
            cin >> Lop;
            if (Lop < 1 || Lop > 12) cout << "Khong hop le. Vui long nhap lai. " << endl;
        } while (Lop < 1 || Lop > 12);
        cin.ignore();
        cout << "Nhap ten truong: ";
        getline(cin, TenTruong);
    }
    void Xuat() {
        cout << "Doi tuong: Hoc sinh. " << endl;
        Nguoi::XuatThongTin();
        cout << "Hoc lop: " << Lop << endl;
        if (Lop >= 1 && Lop <= 5) cout << "Hoc tai truong tieu hoc " << TenTruong << endl;
        else if (Lop >= 6 && Lop <= 9) cout << "Hoc tai truong THCS " << TenTruong << endl;
        else cout << "Hoc tai truong THPT " << TenTruong << endl;
    }
};
class CongNhan :public Nguoi {
private:
    long Luong;
    string TenCongTy;
public:
    void Nhap() {
        cout << "Doi tuong: Cong nhan. " << endl;
        Nguoi::NhapThongTin();
        cout << "Nhap luong cua cong nhan (thang): ";
        cin >> Luong;
        cin.ignore();
        cout << "Nhap ten cong ty cua cong nhan: ";
        getline(cin, TenCongTy);
    }
    void Xuat() {
        cout << "Doi tuong: Cong nhan. " << endl;
        Nguoi::XuatThongTin();
        cout << "Muc luong: " << Luong << endl;
        cout << "Dang lam viec tai cong ty: " << TenCongTy << endl;
    }
};
class NgheSi :public Nguoi {
private:
    long ThuNhap;
    vector <string> TacPham;
public:
    void Nhap() {
        cout << "Doi tuong: Nghe si." << endl;
        Nguoi::NhapThongTin();
        cout << "Thu nhap cua nghe si: ";
        cin >> ThuNhap;
        while (true) {
            int LuaChon;
            cout << "De nhap cac tac pham, vui long chon so 1. " << endl;
            cout << "De thoat, vui long chon so 2." << endl;
            cout << "Lua chon cua ban: ";
            cin >> LuaChon;
            if (LuaChon == 1) {
                string TenTacPham;
                cin.ignore();
                cout << "Vui long nhap ten tac pham: ";
                getline(cin, TenTacPham);
                TacPham.push_back(TenTacPham);
            }
            else if (LuaChon == 2) break;
            else {
                cout << "Lua chon khong hop le. Vui long thu lai. ";
                continue;
            }
        }
    }
    void Xuat() {
        cout << "Doi tuong: Nghe si." << endl;
        Nguoi::XuatThongTin();
        cout << "Thu nhap cua nghe si: " << ThuNhap << endl;
        cout << "Cac tac pham cua nghe si: " << endl;
        for (int i = 0; i < TacPham.size(); i++) {
            cout << i << ") " << TacPham[i] << endl;
        }
    }
};

class CaSi :public Nguoi {
private:
    long CatXe;
    vector<string> BaiHat;
public:
    void Nhap() {
        cout << "Doi tuong: Ca si." << endl;
        Nguoi::NhapThongTin();
        cout << "Cat xe cua ca si: ";
        cin >> CatXe;
        while (true) {
            int LuaChon;
            cout << "De nhap cac bai hat, vui long chon so 1. " << endl;
            cout << "De thoat, vui long chon so 2." << endl;
            cout << "Lua chon cua ban: ";
            cin >> LuaChon;
            if (LuaChon == 1) {
                string TenBaiHat;
                cin.ignore();
                cout << "Vui long nhap ten tac pham: ";
                getline(cin, TenBaiHat);
                BaiHat.push_back(TenBaiHat);
                continue;
            }
            else if (LuaChon == 2) break;
            else {
                cout << "Lua chon khong hop le. Vui long thu lai. ";
                continue;
            }
        }
    }
    void Xuat() {
        cout << "Doi tuong: Ca si." << endl;
        Nguoi::XuatThongTin();
        cout << "Cat xe cua ca si: " << CatXe << endl;
        cout << "Cac bai hat cua ca si: " << endl;
        for (int i = 0; i < BaiHat.size(); i++) {
            cout << i + 1 << ") " << BaiHat[i] << endl;
        }
    }
};
class ThongKeDanhSach {
private:
    vector <Nguoi*> DanhSach;
    Nguoi* DoiTuong;
    string LuaChon;
public:
    void NhapThongTinDanhSach() {
        while (true) {
            cout << "Vui long lua chon de nhap thong tin doi tuong. " << endl;
            cout << "Nhap so 1 de nhap thong tin sinh vien. " << endl;
            cout << "Nhap so 2 de nhap thong tin hoc sinh. " << endl;
            cout << "Nhap so 3 de nhap thong tin cong nhan. " << endl;
            cout << "Nhap so 4 de nhap thong tin nghe si. " << endl;
            cout << "Nhap so 5 de nhap thong tin ca si. " << endl;
            cout << "Nhap so 0 de thoat va xuat ra danh sach. " << endl;
            cout << "Vui long nhap lua chon cua ban: ";
            cin >> LuaChon;
            if (LuaChon == "1") {
                DoiTuong = new SinhVien;
                DanhSach.push_back(DoiTuong);
                DanhSach.back()->Nhap();
                system("cls");
            }
            else if (LuaChon == "2") {
                DoiTuong = new HocSinh;
                DanhSach.push_back(DoiTuong);
                DanhSach.back()->Nhap();
                system("cls");
            }
            else if (LuaChon == "3") {
                DoiTuong = new CongNhan;
                DanhSach.push_back(DoiTuong);
                DanhSach.back()->Nhap();
                system("cls");
            }
            else if (LuaChon == "4") {
                DoiTuong = new NgheSi;
                DanhSach.push_back(DoiTuong);
                DanhSach.back()->Nhap();
                system("cls");
            }
            else if (LuaChon == "5") {
                DoiTuong = new CaSi;
                DanhSach.push_back(DoiTuong);
                DanhSach.back()->Nhap();
                system("cls");
            }
            else if (LuaChon == "0") break;
            else {
                cout << "Lua chon khong hop le. Vui long nhap lai. " << endl;
                system("cls");
            }
        }
    }
    void XuatThongTinDanhSach() {
        for (int i = 0; i < DanhSach.size(); i++) {
            cout << "----------------------------------------------------------------------" << endl;
            DanhSach[i]->Xuat();
            cout << "----------------------------------------------------------------------" << endl;
       }
    }
};
int main()
{
    ThongKeDanhSach DoiTuong;
    DoiTuong.NhapThongTinDanhSach();
    DoiTuong.XuatThongTinDanhSach();
    return 0;
}
