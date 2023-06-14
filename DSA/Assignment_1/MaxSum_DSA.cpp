#include <iostream>
int main(){
    int n;std::cin>>n;
    int a[n];
    for(int i=0;i<n;i++) std::cin>>a[i];
    int min=a[0],max=a[1];
    int minpst=0,maxpst=1;
    for(int i=0;i<n;i=i+2)
        if(a[i]<min){
            min=a[i];
            minpst=i;
        }
    for(int i=1;i<n;i=i+2)
        if(a[i]>max){
            max=a[i];
            maxpst=i;
        }
    int sum=0;
    if(max>min){
        a[maxpst]=min;
        a[minpst]=max;
    }
    for(int i=0;i<n;i++){
        if(i%2==0) sum+=a[i];
        else sum-=a[i];
    }
    std::cout<<sum;
}
