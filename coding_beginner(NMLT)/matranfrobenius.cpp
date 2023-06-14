#include <iostream>
#define MAXR 101
#define MAXC 101

void NhapMaTran(int a[][MAXC],int &n){
    std::cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            std::cin>>a[i][j];
        }
    }
}
bool isMaTranDonVi(int a[][MAXC],int n){
    bool ketqua=true;
    for(int i =1; i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j&&a[i][j]!=1){
                ketqua=false;
                break;
            }
            if(i!=j&&a[i][j]!=0){

            }
        }
    }
    return ketqua;
}
int main() {
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout <<  std::boolalpha << isMaTranDonVi(a, n);
    return 0;
}
