#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int m,n;cin>>m>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int arr2[m]={1};
    fill_n(arr2,m,1);
    for(int i=n-1;i>=0;i--){
        if(arr2[arr[i]-1]){
            cout<<arr[i]<<" ";
            arr2[arr[i]-1]=0;
        }
    }
    for(int i=0;i<m;i++){
        if(arr2[i]==1)
            cout<<i+1<<" ";
    }
}
