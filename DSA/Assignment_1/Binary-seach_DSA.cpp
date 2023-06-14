#include <iostream>
#include <map>
int main(){
    int n,q; std::cin>>n>>q;
    std::map<int, int> map;
    int a[q];
    int temp=0;
    for(int i=0;i<n;i++){
        std::cin>>temp;
        map[temp]++;
    }
    for(int i=0;i<q;i++) std::cin>>a[i];
    for(int i=0;i<q;i++){
        if(map[a[i]]) std::cout<<"YES"<<"\n";
        else std::cout<<"NO"<<"\n";
    }
}
