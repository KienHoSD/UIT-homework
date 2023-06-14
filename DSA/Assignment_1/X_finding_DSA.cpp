#include <iostream>
int main(){
    int n,x; std::cin>>n;
    int a[n];
    for(int i=0;i<n;i++) std::cin>>a[i];
    std::cin>>x;
    bool co_x=0;
    for(int i=0;i<n;i++) if(a[i]==x) {
        std::cout<<i+1<<" "; co_x=1;
    }
    if(!co_x) std::cout<<"NO";
}
