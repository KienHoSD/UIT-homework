#include <iostream>
void in_array(int a[],int n){
    for(int i=0;i<n;i++)
        std::cout<<a[i]<<" ";
}
void selection_sort_descending(int a[],int n){
    int max,temp;
    for(int i=0;i<n;i++){
        max=i;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[max]) max=j;
        }
        temp=a[i];
        a[i]=a[max];
        a[max]=temp;
    }
}
int main(){
    int a[]= {8,2,1,9,4,5,7,6,3};
    selection_sort_descending(a,sizeof(a) / sizeof(int));
    in_array(a,sizeof(a)/sizeof(int));
}
