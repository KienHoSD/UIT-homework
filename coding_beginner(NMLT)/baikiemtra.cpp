#include <iostream>
using namespace std;
int main(){
    int n,k,p,q;
    cin>>n>>k>>p>>q;
    int a[(n+1)/2][2];
    int f=1;
    int i,j,e;
    for(i=1;i<=n;i++){
        for(j=1;j<=(n+1)/2;j++){
            for(e=1;e<=2;e++){
                if(f<=k)
                    a[j][e]=f;
                else{
                    f=1;
                    a[j][e]=f;
                }
                f++;
            }
        }
    }
    bool ketqua1=false;
    bool ketqua2=false;
    int ban1,ban2;
    for(i=p+1;i<=(n+1)/2;i++){
        if(a[i][q]==a[p][q]) {
            ketqua1=true;
            ban1=i;
            break;
        }
    }
    for(i=p-1;i>=1;i--){
        if(a[i][q]==a[p][q]) {
            ketqua2=true;
            ban2=i;
            break;
        }
    }
    if((ketqua1==true&&ketqua2==true)||(ketqua1==false&&ketqua2==true))
        cout<<ban2<<" "<<q;
    else if(ketqua1==true&&ketqua2==false)
        cout<<ban1<<" "<<q;
    else cout<<-1;
}


