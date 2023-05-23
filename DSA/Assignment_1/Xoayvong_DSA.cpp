#include <iostream>
int main(){
    int n,k;std::cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++) std::cin>>a[i];
    for(int i=0;i<n;i++) b[(i+k)%n]=a[i];
    for(int i=0;i<n;i++) std::cout<<b[i]<<" ";
}
