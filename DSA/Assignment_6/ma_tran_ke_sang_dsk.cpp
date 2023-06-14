#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> NhapMaTran(int n){
    vector<vector<bool>> result(n, vector<bool>(n,0));
    bool tempbool;
    for(int i =0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>tempbool;
            result[i][j]=tempbool;
        }
    return result;
}
void XuatDanhSachKe(const vector<vector<bool>>& matran,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(matran[i][j]==true){
                cout<<i+1<<"->"<<j+1<<" ";
                for(int q=j+1;q<n;q++)
                    if(matran[i][q]) cout<<q+1<<" ";
                cout<<'\n';
                break;
            }
        }
}
int main(){
    int n; cin>>n;
    vector<vector<bool>> matran;
    matran = NhapMaTran(n);
    XuatDanhSachKe(matran,n);
}