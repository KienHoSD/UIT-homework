#include <bits/stdc++.h>
using namespace std;
#define Max 100000
void nhapmang(int a[Max],int n){
    for(int i = 1;i<=n;i++)
        cin>>a[i];
}
int main(){
    int a[Max],b[Max],c[Max];
    int n1,n2;
    cin>>n1;
    nhapmang(a,n1);
    cin>>n2;
    nhapmang(b,n2);
    int n3=n1+n2;
    int solan=1;
    int i=1,j=1;
    while(solan!=n3){
        if (a[i]<b[j]) {
            c[solan]=a[i];
            i++;
            if(i>n1) a[i]=b[n2];
        }
        else {
            c[solan]=b[j];
            j++;
            if(j>n2) b[j]=a[n1];
        }
        solan++;
    }
    if(a[n1]>b[n2]) c[n3]=a[n1];
    else c[n3]=b[n2];
    for(int i=1;i<=n3;i++) cout<<c[i]<<" ";
}
