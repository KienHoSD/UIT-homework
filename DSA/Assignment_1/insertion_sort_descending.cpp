#include <iostream>
void in_array(int a[],int n){
    for(int i=0;i<n;i++)
        std::cout<<a[i]<<" ";
}
void insertion_sort_descending(int a[],int n){
    int i=1,e,k;
    while (i<n){
        e=a[i];
        k=i-1;
        while(k>=0 and !(a[k]>e)){
            a[k+1]=a[k];
            k-=1;
        }
        a[k+1]=e;
        i++;
    }
}
int main(){
    int a[]= {8,2,1,9,4,5,7,6,3};
    insertion_sort_descending(a,sizeof(a) / sizeof(int));
    in_array(a,sizeof(a)/sizeof(int));
}
