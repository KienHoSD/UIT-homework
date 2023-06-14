#include <iostream>
#include <iomanip>
#define MAXR 101
#define MAXC 101

void NhapMaTran(double a[][MAXC],int &n,int &n2){
    std::cin>>n;
    std::cin>>n2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            std::cin>>a[i][j];
        }
    }
}
double Tinhduongcheochinh(double a[][MAXC],int n){
    double ketqua;
    for(int i =1; i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                ketqua+=a[i][j];
        }
    }
    return ketqua;
}
int main() {
    double a[MAXR][MAXC];
    int n, n2;
    NhapMaTran(a, n, n2);
    std::cout << std::setprecision(3)<< Tinhduongcheochinh(a, n);
    return 0;
}
