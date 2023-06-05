#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class NhanVien {
protected:
    string HoTen;
    int Ngay;
    int Thang; 
    int Nam;
    double Luong;
public:
    NhanVien() {
        HoTen = "";
        Ngay = Thang = Nam = 1;
        Luong = 0;
    }
    void NhapThongTin() {
        cin.ignore();
        cout << "Nhap ho ten nhan vien: ";
        getline(cin, HoTen);
        cout << "Nhap ngay thang nam sinh nhan vien: ";
        cin >> Ngay >> Thang >> Nam;
    }
    void XuatThongTin() {
        cout << "Ho ten nhan vien: " << HoTen << endl;
        cout << "Ngay thang nam sinh cua nhan vien: " << Ngay << "/" << Thang << "/" << Nam << endl;
        cout << "Luong: " << setprecision(0) << fixed << Luong << endl;
    }
    virtual void Nhap() = 0;
    virtual void TinhTienLuong() = 0;
    virtual void Xuat() = 0;
};
class NhanVienSanXuat :public NhanVien {
private:
    double LuongCanBan;
    int SoSanPham;
public:
    NhanVienSanXuat() {
        LuongCanBan = SoSanPham = 0;
    }
    void Nhap() {
        cout << "Doi tuong: Nhan vien san xuat. " << endl;
        NhanVien::NhapThongTin();
        cout << "Nhap luong can ban cua nhan vien san xuat: ";
        cin >> LuongCanBan;
        cout << "Nhap so san pham: ";
        cin >> SoSanPham;
    }
    void TinhTienLuong() {
        Luong = LuongCanBan + SoSanPham * 5000;
    }
    void Xuat() {
        cout << "Loai nhan vien: Nhan vien san xuat." << endl;
        NhanVien::XuatThongTin();
    }
};
class NhanVienVanPhong :public NhanVien {
private:
    int SoNgayLamViec;
public:
    NhanVienVanPhong() {
        SoNgayLamViec = 0;
    }
    void Nhap() {
        cout << "Doi tuong: Nhan vien van phong. " << endl;
        NhanVien::NhapThongTin();
        cout << "Nhap so ngay lam viec cua nhan vien van phong: ";
        cin >> SoNgayLamViec;
    }
    void TinhTienLuong() {
        Luong = SoNgayLamViec * 100000;
    }
    void Xuat() {
        cout << "Loai nhan vien: Nhan vien van phong." << endl;
        NhanVien::XuatThongTin();
    }
};
class ThongKeNhanVien {
private:
    vector<NhanVien*> CongTy;
public:
    void NhapThongTinNhanVienCongTy() {
        NhanVien* temp;
        while (true) {
            string LuaChon;
            cout << "De nhap thong tin nhan vien, vui long chon:" << endl;
            cout << "Nhap so 1 de nhap thong tin nhan vien san xuat: " << endl;
            cout << "Nhap so 2 de nhap thong tin nhan vien van phong: " << endl;
            cout << "Nhap so 0 de thoat." << endl;
            cout << "Vui long nhap lua chon cua ban: ";
            cin >> LuaChon;
            if (LuaChon == "1") {
                temp = new NhanVienSanXuat;
                CongTy.push_back(temp);
                CongTy.back()->Nhap();
                system("cls");
            }
            else if (LuaChon == "2") {
                //temp = &B;
                temp = new NhanVienVanPhong;
                CongTy.push_back(temp);
                CongTy.back()->Nhap();
                system("cls");
            }
            else if (LuaChon == "0") break;
            else cout << "Lua chon khong hop le. Vui long nhap lai. " << endl;
        }
    }
    void XuatThongTinNhanVienCongTy() {
        for (int i = 0; i < CongTy.size(); i++) {
            cout << "----------------------------------------------------------" << endl;
            CongTy[i]->TinhTienLuong();
            CongTy[i]->Xuat();
            cout << "----------------------------------------------------------" << endl;
        }
    }
};
int main()
{
    ThongKeNhanVien A;
    A.NhapThongTinNhanVienCongTy();
    A.XuatThongTinNhanVienCongTy();
    return 0;
}

