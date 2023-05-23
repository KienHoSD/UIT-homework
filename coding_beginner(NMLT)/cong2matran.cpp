#include <iostream>
using namespace std;
int main(){
    int m,n;cin>>m>>n;
    float a[m][n],b[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    cin>>m>>n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>b[i][j];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            a[i][j]+=b[i][j];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


}
