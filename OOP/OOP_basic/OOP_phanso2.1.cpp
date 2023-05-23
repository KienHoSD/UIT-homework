#include<iostream>
// Hàm tính GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
// Khởi tạo lớp PhanSo
class PhanSo {
private:
    int tuSo, mauSo;
public:
    // Hàm khởi tạo
    PhanSo() {
        tuSo = 0;
        mauSo = 1;
    }
    // Hàm khởi tạo có đối số
    PhanSo(int ts, int ms) {
        while (true) {
            if (ms == 0) { std::cout << "mau so phai khac 0!\nHay khai bao lai\n"; break; }
            tuSo = ts;
            mauSo = ms;
            break;
        }
    }
    // Hàm nhập
    void nhap() {
        std::cout << "Nhap tu so va mau so:";
        while (true) {
            std::cin >> tuSo >> mauSo;
            if (mauSo != 0) break;
            std::cout << "Mau so phai khac 0!\nHay nhap lai tu so va mau so:";
        }
    }
    // Hàm rút gọn phân số
    void rutgon(PhanSo &a) {
        int temp = gcd(a.mauSo, a.tuSo);
        a.tuSo /= temp;
        a.mauSo /= temp;
    }
    // Hàm xuất phân số
    void xuat() {
        rutgon(*this);
        if (mauSo == 1) std::cout << tuSo << "\n"; // nếu mauSo = 1 thì in ra tuSo
        else if ((tuSo > 0 && mauSo < 0) || (tuSo < 0 && mauSo < 0))// Nếu tuSo > 0 và mauSo < 0 hay tuSo < 0 và mauSo < 0 
            std::cout << -tuSo << "/" << -mauSo << "\n"; // in ra đối của tử số và mẫu số 
            //Ex: -6/-4 = 3/2, 4/-5 = -4/5
        else std::cout << tuSo << "/" << mauSo << "\n"; // các trường hợp còn lại thì in tuSo và mauSo
    }
    // Các hàm thành phần cộng, trừ, nhân, chia hai phân số
    PhanSo operator+(PhanSo p) {
        PhanSo tong; // khởi tạo biến PhanSo tong
        tong.tuSo = tuSo * p.mauSo + mauSo * p.tuSo; // thực hiện cộng phân số bằng quy đồng và gán cho tong
        tong.mauSo = mauSo * p.mauSo;
        rutgon(tong); // rút gọn tong
        return tong; // trả về
    }
    PhanSo operator-(PhanSo p) {
        PhanSo hieu; // khởi tạo biến PhanSo hieu
        hieu.tuSo = tuSo * p.mauSo - mauSo * p.tuSo; // thực hiện trừ phân số bằng quy đồng và gán cho hieu
        hieu.mauSo = mauSo * p.mauSo;
        rutgon(hieu); // rút gọn hieu
        return hieu; // trả về
    }
    PhanSo operator*(PhanSo p) {
        PhanSo tich; // khởi tạo biến PhanSo tich
        tich.tuSo = tuSo * p.tuSo;  // thực hiện nhân 2 phân số và gán cho tich
        tich.mauSo = mauSo * p.mauSo;
        rutgon(tich); // rút gọn tich
        return tich; // trả về
    }
    PhanSo operator/(PhanSo p) {
        PhanSo thuong; // khởi tạo biến PhanSo thuong
        thuong.tuSo = tuSo * p.mauSo;  // thực hiện chia 2 phân số và gán cho thuong
        thuong.mauSo = mauSo * p.tuSo;
        rutgon(thuong); // rút gọn thuong
        return thuong; // trả về
    }
};

int main() {
    PhanSo ps1;
    std::cout << "Nhap phan so 1:\n";
    ps1.nhap(); // Cách 1
    std::cout << "Nhap tu va mau cua phan so 2:";
    int a, b; std::cin >> a >> b; 
    PhanSo ps2(a, b); // Cách 2
    std::cout << "Phan so 1: "; 
    ps1.xuat();
    std::cout << "Phan so 2: ";
    ps2.xuat();
    std::cout << "Tong hai phan so: ";
    (ps1 + ps2).xuat();
    std::cout << "Hieu hai phan so: ";
    (ps1 - ps2).xuat();
    std::cout << "Tich hai phan so: ";
    (ps1 * ps2).xuat();
    std::cout << "Thuong hai phan so: ";
    (ps1 / ps2).xuat();
    return 0;
}
