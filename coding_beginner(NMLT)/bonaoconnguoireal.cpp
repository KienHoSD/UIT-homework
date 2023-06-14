#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int64_t GCDofmin[100001];
int dodaij;
int findMin(int64_t a[100001],int n,int j){
    int64_t Min=1000000000000;
    int vitri;
    for(int i=1;i<=n;i++)
        if(a[i]<Min&&i!=j){
            Min=a[i];
            vitri=i;
        }
    return vitri;
}
void findGCDofmin(int64_t Min){
    int j=2;
    GCDofmin[1]=Min;
    for(int i=(Min/2)+1;i>=1;i--)
        if(Min%i==0){
            GCDofmin[j]=i;
            j++;
        }
    dodaij=j-1;
}
int main(){
    int n=0;
    int i,j,e;
    int vitri=0;
    int Max=0;
    int64_t a[100001];
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    int position=findMin(a,n,i);
    findGCDofmin(a[position]);
    for(i=1;i<=n;i++){
        e=1;
        for(j=1;j<=n;j++) {
            if(j!=i&&a[j]%GCDofmin[e]!=0) e++,j--;
            if(GCDofmin[e]<=Max&&e==dodaij) break;
        }
        if(GCDofmin[e]>Max) Max=GCDofmin[e],vitri=i;
    }
    int Max1=Max;
    int vitri1=vitri;
    position=findMin(a,n,position);
    findGCDofmin(a[position]);
    for(i=1;i<=n;i++){
        e=1;
        for(j=1;j<=n;j++) {
            if(j!=i&&a[j]%GCDofmin[e]!=0) e++,j--;
            if(GCDofmin[e]<=Max&&e==dodaij) break;
        }
        if(GCDofmin[e]>Max) Max=GCDofmin[e],vitri=i;
    }
    int Max2=Max;
    int vitri2=vitri;
    Max=(Max2>Max1)?Max2:Max1;
    vitri=(Max2>Max1)?vitri2:vitri1;
    cout<<vitri<<" "<<Max;
}
