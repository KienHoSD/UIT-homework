#include <iostream>
using namespace std;
int main(){
    int cot,dong;
    cin>>cot>>dong;
    double a[cot][dong];
    for(int i=0;i<cot;i++)
        for(int j=0;j<dong;j++)
            cin>>a[i][j];

    for(int j=0;j<dong;j++){
        double Max=0;
        for(int i=0;i<cot;i++)
            if(a[i][j]>Max)
                Max=a[i][j];
        cout<<"Gia tri lon nhat tren cot "<<j<<" la: "<<Max<<endl;
    }
}
