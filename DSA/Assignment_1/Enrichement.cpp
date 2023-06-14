#include <iostream>
#include <vector>
#include <math.h>
void nhap_mang(std::vector<int>& a, int n, int m) {
    int b;
    for (int i = 0; i < n * m; i++) {
        std::cin >> b;
        a.push_back(b);
    }
}
void xuat_mang(const std::vector<int>& a, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        if (i % m == 0)
            std::cout << "\n";
        std::cout << a[i] << " ";
    }
}
int tinh_min_dau3x3(const std::vector<int>& a, int i, int count_row, int m) {
    return a[i] + a[i + 1] + a[i + 2] + a[i % m + count_row * m] + a[i % m + count_row * m + 1] + a[i % m + count_row * m + 2] + a[i % m + count_row * m +m] + a[i % m + count_row * m + m + 1] + a[i % m + count_row * m + m + 2];
}
int min_tong_tru_luong_dau(const std::vector<int>& a, int n, int m) {
    int count_row = 1;
    int min = tinh_min_dau3x3(a, 0, count_row, m);
    int temp=0;
    for (int i = 0; i < m * n; i++) {
        if (float((i+1) / m) == count_row) {
            count_row++; //tang dong
            continue;
        }
        if (count_row > n - 2) return min;
        if (i >= count_row * m - 2) continue; //bo qua 2 cot cuoi
        temp = tinh_min_dau3x3(a, i, count_row, m);
        if (temp < min)
            min = temp;
    }
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a;
    nhap_mang(a, n, m);
    std::cout << min_tong_tru_luong_dau(a, n, m);
}
