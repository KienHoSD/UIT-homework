#include <bits/stdc++.h>
using namespace std;
#define Max 1000
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
    int solan=0;
    for(int i=0,int j=0;solan>n3;){
        if (a[i]>a[j]) {
            c[solan]=a[i]; 
            i++;solan++;
            }
        else {
            c[solan]=a[j];
            j++;solan++;
        }
    }
}
