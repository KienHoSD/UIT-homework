#include <iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    uint64_t n,L;
    std::cin>>n>>L;
    int m =1000000007;
    uint64_t dientich=(L*L)%m;
    int tong=0;
    for(int i=n+1;i!=0;i--){
        tong+=dientich;
        dientich=(dientich*4)%m;
    }
    std::cout<<tong;
}
